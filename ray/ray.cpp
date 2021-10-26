#include "ray.hpp"
#include <vector>

#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"

Ray::Ray(Vec3D const &origin, Vec3D const &direction) : m_origin(origin), m_direction(direction) {}
Ray::Ray(Vec3D const &origin, Vec3D const &direction, VPO &VPO) : m_origin(origin), m_direction(direction), m_VPO(VPO) {}
Ray::Ray(float xStart, float yStart, VPO &VPO) : m_VPO(VPO) {}
bool Ray::scan()
{
    for (Object *ob : m_VPO)
    {
        if (ob->hit(*this))
            return true;
    }
    return false;
}