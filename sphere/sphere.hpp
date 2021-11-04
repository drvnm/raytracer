#pragma once
#include <string>
#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include "../object/object.hpp"
#include "../color/color.hpp"
#include "../returninfo/info.hpp"

/* 
REQUIREMENTS:
I had to make a class that represents a sphere.
It has some functions that help me, like calculating the intersection point, distance from ray

TESTSPEC:
I've tested my class with the following:
Test the different methods and check if the results are right

Design:
I made the class just like it was described in the assignment.
I did made a big change, which is returning my custom "info" type. I thought it was wasteful to just return a bool
This type contains info such as: did the ray hit, intersection point, color, norm

*/

class Sphere : public Object
{

public:
    Vec3D m_centre;
    float m_radius;

    Sphere(Vec3D const &centre, float radius, int zIndex, Color const &color, std::string type); //constructor
    float distFromRay(Ray &ray) const; //calculates the distance from the ray to the sphere
    Info hit(Ray &ray) const; //returns the info of the intersection point
    Vec3D hitPoint(Ray const &ray) const; //returns the intersection point
};
