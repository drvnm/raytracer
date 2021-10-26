#include "floor.hpp"
#define ROWS 400
#define COLS 400
#define CELLHEIGHT 5
#define CELLWIDTH 10
#define HSQUARECOUNT (COLS / CELLWIDTH)

#include "../Vec3D/vec3d.hpp"

#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

Floor::Floor()
{
    std::vector<std::vector<int>> board;
    for (int y = 0; y < ROWS; y++)
    {
        std::vector<int> row(COLS);
        for (int cx = 0; cx < HSQUARECOUNT; cx++)
        {
            int cy = y / CELLHEIGHT;
            std::fill(
                row.begin() + cx * CELLWIDTH,
                row.begin() + (cx + 1) * CELLWIDTH,
                (cx + cy) % 2 == 0 ? 0 : 1);
        }
        m_floor.push_back(row);
    }
}

bool Floor::hit(Ray &ray) const
{
    float t = (-ray.m_origin.m_z / ray.m_direction.m_z);
    Vec3D scaledVector = ray.m_origin + (ray.m_direction * t);
    if (t > 0)
    {
        // std::cout << "x " << scaledVector.m_x << std::endl;
        // std::cout << "y " << scaledVector.m_y << std::endl;
        bool xCordIsOnFloor = scaledVector.m_x >= 0 && scaledVector.m_x < m_floor.size();
        bool YCordIsOnFloor = scaledVector.m_y >= 0 && scaledVector.m_y < m_floor.size();

        if (xCordIsOnFloor && YCordIsOnFloor && m_floor[scaledVector.m_x][scaledVector.m_y] == 1)
        {
            return true;
        }
    }

    return false;
}
