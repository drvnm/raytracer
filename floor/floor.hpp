#pragma once


#include <string>
#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"
#include <vector>
#include <string>

class Floor : public Object
{
public:
    
    Floor();
    bool hit(Ray &ray) const;
};