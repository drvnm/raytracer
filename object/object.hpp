#pragma once

#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"


class Object
{

public:
    Vec3D m_centre;
    Object(){ };
    Object(Vec3D const &v);
    virtual bool hit(Ray &ray) const = 0;
};
