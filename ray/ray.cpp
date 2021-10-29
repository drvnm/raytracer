#include "ray.hpp"
#include <vector>
#include <iostream>
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

int Ray::scan()
{
    // recursive ray
    Vec3D direction = m_direction;
    Vec3D origin = m_origin;
    int intensity = 0;
    for (Object *obOuter : m_VPO)
    {
        for (Object *obOuter : m_VPO)
        {
            if(obOuter->hit(*this)) {
                intensity += obOuter->intensity;
            }
        }
        m_origin = origin;
        m_direction = direction;
    }
    return intensity;
}