#pragma once

#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"
#include "../color/color.hpp"
#include <vector>
#include <string>

class Floor : public Object
{
public:
    Floor(int zIndex, const Color &color);
    bool hit(Ray &ray) const;
    float distFromRay(Ray &ray) const;
};