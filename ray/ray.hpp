#pragma once

#include <vector>
#include "../vec3d/vec3d.hpp"

class Object;
typedef std::vector<Object *> VPO;

class Ray
{
public:
    Vec3D m_origin;
    Vec3D m_direction;
    VPO m_VPO;
    int intensity;
    Ray(Vec3D const &origin, Vec3D &direction);
    Ray(Vec3D const &origin, Vec3D &direction, VPO &m_VPO);
    Ray(float xStart, float yStart, VPO &m_VPO);

    int scan();
   
};
