#include "ray.hpp"
#include <vector>
#include <iostream>
#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"

Ray::Ray(Vec3D const &origin, Vec3D const &direction) : m_origin(origin), m_direction(direction) {}
Ray::Ray(Vec3D const &origin, Vec3D &direction, VPO &VPO) : m_origin(origin), m_direction(direction), m_VPO(VPO)
{
    m_direction = direction.unit();
}
Ray::Ray(float xStart, float yStart, VPO &VPO) : m_VPO(VPO) {}
int Ray::scan()
{
    int intensity = 0;
    for (Object *ob : m_VPO)
    {
        if (ob->hit(*this))
        {
            intensity += ob->intensity;
        }
    }
    return intensity;
}