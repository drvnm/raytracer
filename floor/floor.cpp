#include "floor.hpp"
#define ROWS 2000
#define COLS 2000
#define GRIDSIZE (ROWS * COLS)
#define SQUAREWIDTH 10
#define SQAUREHEIGHT (ROWS / SQUAREWIDTH)

#include "../Vec3D/vec3d.hpp"

#include <limits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <cmath>

Floor::Floor(int zIndex, const Color &color)
{
    m_type = "Floor";
    intensity = 2;
    m_zIndex = zIndex;
    m_color = color;
}

float Floor::distFromRay(Ray &ray) const
{
    float t = (-ray.m_origin.m_z / ray.m_direction.m_z);
    Vec3D scaledVector = ray.m_origin + (ray.m_direction * t);
    if (t < 0)
        return -1;
    if ((int)(floor(scaledVector.m_x / 20) + floor(scaledVector.m_y / 20)) % 2 != 0)
        return -1;

    Vec3D point = ray.m_origin + ray.m_direction * t;
    Vec3D origin = ray.m_origin;
    return std::sqrt(std::pow(point.m_x - origin.m_x, 2) +
                     std::pow(point.m_y - origin.m_y, 2) +
                     std::pow(point.m_z - origin.m_z, 2));
}
Info Floor::hit(Ray &ray) const
{
    Vec3D normal = (Vec3D(0, 0, 1));
    Info info = Info(std::numeric_limits<float>::infinity(), false, Vec3D(0, 0, 0), normal, m_color, "Nothing");
    float z = 0;
    float t = (z - ray.m_origin.m_z / ray.m_direction.m_z);
    if (t > 0)
    {
        Vec3D hitPoint = ray.m_origin + (ray.m_direction * t);
        bool passesThrough = (int)(floor(hitPoint.m_x / 20) + floor(hitPoint.m_y / 20)) % 2 == 0;
        info = Info(t, passesThrough, hitPoint, normal, m_color, m_type);
    }
    return info;
}
