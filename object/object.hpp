#pragma once

#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include "../color/color.hpp"
#include "../returninfo/info.hpp"
#include <string>



/* 
REQUIREMENTS:
I had to make a class that was could represent a object.

TESTSPEC:
I've tested my class with the following:
Test the different methods

Design:
I have the same methods that were described in the assignment.
I have also added a method that returns the distance from the object to the ray, every subclass must implement this method.
The hit method again returns info.
*/

class Object
{

public:
    std::string m_type;
    Color m_color;
    int intensity;
    int m_zIndex; 
    Object();
    virtual Info hit(Ray &ray) const = 0;
    virtual float distFromRay(Ray &ray) const = 0;
};
