#include "ray.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"
#include ".."

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

bool my_cmp(Object *&a, Object *&b)
{
    // smallest comes first
    return a->m_zIndex < b->m_zIndex;
}

// std::sort(A.begin(), A.end(), my_cmp);

int Ray::scan()
{


    // z ordering
    std::vector<float> lengths;
    for (int i = 0; i < m_VPO.size(); i++)
    {
        float distance = m_VPO[i]->distFromRay(*this);
        if(distance == -1) {
            lengths.push_back(1000000.0);
            continue;
        }
        lengths.push_back(m_VPO[i]->distFromRay(*this));
    }
    int clostestObject = std::distance(std::begin(lengths), std::min_element(std::begin(lengths), std::end(lengths)));
    if(lengths[clostestObject] == 1000000.0) {
        return 0;
    }


    // reflection
    int intensity = 0;
    Vec3D direction = m_direction;
    Vec3D origin = m_origin;

    Object *obOuter = m_VPO[clostestObject];

    if (obOuter->hit(*this))
    {
        intensity += obOuter->intensity;
        for (Object *obInner : m_VPO)
        {

            if (obInner->hit(*this))
            {
                intensity += obInner->intensity;
            }
        }
    }

    return intensity;
}