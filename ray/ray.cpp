#include "ray.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"

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

    if (obOuter->hit(*this))
    {
        color = Color(obOuter->m_color.m_r, obOuter->m_color.m_g, obOuter->m_color.m_b);

        for (Object *obInner : m_VPO)
        {
            bounces = bounces + 1;
            if (obInner->hit(*this))
            {
                int r = obInner->m_color.m_r;
                int g = obInner->m_color.m_g;
                int b = obInner->m_color.m_b;
                color = Color(color.m_r + r, color.m_g + g, color.m_b + b);
            }
        }
    }

    return Color(std::round(color.m_r / bounces), std::round(color.m_g / bounces), std::round(color.m_b / bounces));
}