#pragma once

#include "../vec3d/vec3d.hpp"
#include "../object/object.hpp"
#include "../color/color.hpp"
#include "../returninfo/info.hpp"
#include <vector>
#include <string>


/* 
REQUIREMENTS:
I had to make a class that was could represent a floor.

TESTSPEC:
I've tested my class with the following:
Test the different methods

Design:
I have the same methods that were described in the assignment.
I used a formula that represents my floor, instead of using a 2d vector. I did this because i wanted an infinite floor.
I also implemented the distfromray method. the hit method returns information about the hit.
*/

class Floor : public Object
{
public:
    Floor(int zIndex, const Color &color); //constructor
    Info hit(Ray &ray) const; //hit method
    float distFromRay(Ray &ray) const; //returns distance from ray
};