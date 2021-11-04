#pragma once

#include <vector>
#include "../vec3d/vec3d.hpp"
#include "../color/color.hpp"
#include "../returnInfo/info.hpp"
class Object;
typedef std::vector<Object *> VPO;

/* 
REQUIREMENTS:
I had to make a class that was could represent a ray.

TESTSPEC:
I've tested my class with the following:
Test the different methods

Design:
I have the same methods that were described in the assignment.
But instead of returning a bool upon a hit, i return my custom Info class. I did this so that i would have more information about the hit.

*/

class Ray
{
public:
    Vec3D m_origin;                                         // origin of the ray
    Vec3D m_direction;                                      // direction of the ray
    VPO m_VPO;                                              // vector of pointers to objects
    Ray(Vec3D const &origin, Vec3D &direction);             // constructor
    Ray(Vec3D const &origin, Vec3D &direction, VPO &m_VPO); // constructor
    Ray(float xStart, float yStart, VPO &m_VPO);            // constructor

    Info scan(); // scan the scene, return the info of the closest hit
};
