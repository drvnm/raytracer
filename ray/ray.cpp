#include "ray.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"
#include "../sphere/sphere.hpp"

Ray::Ray(Vec3D const &origin, Vec3D &direction) : m_origin(origin), m_direction(direction)
{
    {
        m_direction = direction.unit();
    }
}
Ray::Ray(Vec3D const &origin, Vec3D &direction, VPO &VPO) : m_origin(origin), m_VPO(VPO)
{
    m_direction = direction.unit();
}
Ray::Ray(float xStart, float yStart, VPO &VPO) : m_VPO(VPO) {}

Color Ray::scan()
{

    Sphere light = Sphere(Vec3D(0, 50, 1200), 2, 1, Color(255, 255, 255), "light");

    // z ordering
    std::vector<float> lengths;
    for (int i = 0; i < m_VPO.size(); i++)
    {
        float distance = m_VPO[i]->distFromRay(*this);
        if (distance == -1)
        {
            lengths.push_back(1000000.0);
            continue;
        }
        lengths.push_back(m_VPO[i]->distFromRay(*this));
    }
    int clostestObject = std::distance(std::begin(lengths), std::min_element(std::begin(lengths), std::end(lengths)));
    if (lengths[clostestObject] == 1000000.0)
    {
        return Color(0, 0, 0);
    }

    // reflection
    Color color;
    int bounces = 0;
    Vec3D direction = m_direction;
    Vec3D origin = m_origin;

    Object *obOuter = m_VPO[clostestObject];

    Info hitInfo = obOuter->hit(*this);
    if (hitInfo.m_hit)
    {
        bounces = bounces + 1;
        color = Color(obOuter->m_color.m_r, obOuter->m_color.m_g, obOuter->m_color.m_b);

        for (Object *obInner : m_VPO)
        {
            if (obInner->hit(*this).m_hit)
            {
                bounces = bounces + 1;
                int r = obInner->m_color.m_r;
                int g = obInner->m_color.m_g;
                int b = obInner->m_color.m_b;
                color = Color(color.m_r + r, color.m_g + g, color.m_b + b);
            }
        }
    }

    color = Color(std::round(color.m_r / bounces), std::round(color.m_g / bounces), std::round(color.m_b / bounces));
    if (obOuter->m_type == "Floor")
    {
        for (Object *obInner : m_VPO)
        {
            Vec3D origin = hitInfo.m_coord;
            Vec3D direction = light.m_centre - origin;
            Ray lightRay(origin, direction);

            if (obInner->hitLight(lightRay) && obInner->m_type != "light")
            {

                color = Color(color.m_r * 0.5, color.m_g * 0.5, color.m_b * 0.5);
            }
        }
    }
    return color;
}
