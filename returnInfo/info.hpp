#pragma once
#include "../vec3d/vec3d.hpp"
#include "../color/color.hpp"
#include <vector>
#include <string>

/* 
REQUIREMENTS:
This was not a requirement for the assignment, but it made sense to make this class.

TESTSPEC:
There is no testing here, since it will be uses by other classes.

Design:
I made the decision to make this class because it is a way to return multiple values from a function.

*/


class Info
{
public:
    float m_t;
    bool m_hit;
    Vec3D m_coord;
    Vec3D m_normal;
    Color m_color;
    std::string m_type;

    Info(float t, bool hit, Vec3D coord, Vec3D normal, Color color, std::string type); // constructor
    Info(); // default constructor
};
