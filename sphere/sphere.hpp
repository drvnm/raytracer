#pragma once
#include <string>
#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include "../object/object.hpp"
#include "../color/color.hpp"
#include "../returninfo/info.hpp"

class Sphere : public Object
{

public:
    Vec3D m_centre;
    float m_radius;
 

    Sphere(Vec3D const &centre, float radius, int zIndex, Color const &color, std::string type);
    float distFromRay(Ray &ray) const;
    Info hit(Ray &ray) const;
    Vec3D hitPoint(Ray const &ray) const;
};
