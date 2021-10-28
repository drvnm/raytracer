#pragma once

#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include <string>


class Object
{

public:
    std::string m_type;
    int intensity;
    Vec3D m_centre;
    Object(){ };
    Object(Vec3D const &v);
    virtual bool hit(Ray &ray) const = 0;
};
