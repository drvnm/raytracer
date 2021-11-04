#include "ray.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"
#include "../sphere/sphere.hpp"

Ray::Ray(Vec3D const &origin, Vec3D &direction) : m_origin(origin)
{

    m_direction = direction.unit();
}
Ray::Ray(Vec3D const &origin, Vec3D &direction, VPO &VPO) : m_origin(origin), m_VPO(VPO)
{
    m_direction = direction.unit();
}
Ray::Ray(float xStart, float yStart, VPO &VPO) : m_VPO(VPO) {}

Info Ray::scan()
{

    Info result = Info(
        std::numeric_limits<float>::infinity(),
        false, // you don't really need m_hit, but well
        Vec3D(0, 0, 0),
        Vec3D(0, 0, 0),
        Color(0, 0, 0),
        "Nothing"); // info to return if there is no hit

    // following loop will return the hit info about the closest hit, this will allow me to have z ordering.
    for (Object *obj : m_VPO)
    {
        Info hit_result = obj->hit(*this);
        if (hit_result.m_t > 0 && hit_result.m_t < result.m_t)
        {
            result = hit_result;
        }
    }
    return result;
}
