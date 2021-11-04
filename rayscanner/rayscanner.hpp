#pragma once

#define SCREEN_WIDTH 3000
#define SREEN_LENGTH 3000

#include "../object/object.hpp"
#include "../sphere/sphere.hpp"
#include "../color/color.hpp"
#include "../returnInfo/info.hpp"

#include <vector>
#include <string>

/* 
REQUIREMENTS:
I had to make a class that was responsible for shooting rays in my wortld.
It had to be able to take objects, and use the hit information to do something

TESTSPEC:
I've tested my class with the following:
Test the different methods

Design:
I have the same methods that were described in the assignment.
The difference is that i have a giveMeColorPls method that uses the "closest ray (z ordering)" and uses that to compute the final color

*/


typedef std::vector<Object *> VPO;

class RayScanner
{
public:
    VPO m_objects;
    std::vector<std::vector<Color>> m_screenBuffer = std::vector<std::vector<Color>>(SREEN_LENGTH, std::vector<Color>(SCREEN_WIDTH)); // 2D vector of colors
    RayScanner(VPO objects); // Constructor
    void scan(); // Scan the world
    void render(); // Render the world
    Color giveMeColorPls(Info bestHit, Vec3D lightDir, Vec3D direction, int bounce); // Compute the color of a pixel
};