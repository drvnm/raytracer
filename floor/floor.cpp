#include "floor.hpp"
#define ROWS 2000
#define COLS 2000
#define GRIDSIZE (ROWS * COLS)
#define SQUAREWIDTH 10
#define SQAUREHEIGHT (ROWS / SQUAREWIDTH)

#include "../Vec3D/vec3d.hpp"

#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

Floor::Floor()
{
    m_type = "Floor";
    intensity = 2;

}

bool Floor::hit(Ray &ray) const
{
    float t = (-ray.m_origin.m_z / ray.m_direction.m_z);
    Vec3D scaledVector = ray.m_origin + (ray.m_direction * t);
    if (t > 0)
    {

        return (int)(floor(scaledVector.m_x / 20) + floor(scaledVector.m_y / 20)) % 2 == 0;
    }

    return false;
}
