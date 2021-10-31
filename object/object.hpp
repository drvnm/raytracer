#pragma once

#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include "../color/color.hpp"
#include <string>


class Object
{

public:
    std::string m_type;
    Color m_color;
    int intensity;
    int m_zIndex;
    Vec3D m_centre;
    Object(){ };
    Object(Vec3D const &v);
    virtual bool hit(Ray &ray) const = 0;
    virtual float distFromRay(Ray &ray) const = 0;
};
