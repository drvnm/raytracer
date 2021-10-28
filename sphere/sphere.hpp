#pragma once
#include <string>
#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include "../object/object.hpp"

class Sphere : public Object
{

public:
   
    Vec3D m_centre;
    float m_radius;
    Sphere(Vec3D const &centre, float radius);
    float distFromRay(Ray const &ray) const;
    bool hit(Ray &ray) const;
    Vec3D hitPoint(Ray const &ray) const;
};

