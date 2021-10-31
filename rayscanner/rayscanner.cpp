#include "rayscanner.hpp"
#include "../ray/ray.hpp"
#include "../sphere/sphere.hpp"
#include "../vendor/bitmap/bitmap_image.hpp"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define SCREEN_WIDTH 3000
#define SREEN_LENGTH 3000

RayScanner::RayScanner(VPO objects) : m_objects(objects)
{
}
void RayScanner::scan()
{
    // shoot a ray from the camera to the screen
    // for each object in the scene, check if the ray intersects with the object

    for (int i = 0; i < SREEN_LENGTH; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {

            Vec3D endPoint = Vec3D(-(SCREEN_WIDTH / 2) + j, 0, (SCREEN_WIDTH / 2) - i);
            Vec3D origin = Vec3D(-(SCREEN_WIDTH / 2) + j, -600, (SCREEN_WIDTH / 2) - i);
            Vec3D dir = endPoint - origin;
            Ray startPoint = Ray(origin, dir, m_objects);

            Color color = startPoint.scan();
            m_screenBuffer[i][j] = color;
        }
    }
}

void RayScanner::render()
{

    bitmap_image base(SCREEN_WIDTH, SREEN_LENGTH);
    for (int y = 0; y < SCREEN_WIDTH; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            Color colorToDraw = m_screenBuffer[y][x];
            base.set_pixel(x, y, colorToDraw.m_r, colorToDraw.m_g, colorToDraw.m_b);
        }
        std::cout << y << std::endl;
    }
    base.save_image("base.bmp");
}
