#include "rayscanner.hpp"
#include "../ray/ray.hpp"
#include "../sphere/sphere.hpp"
#include "../vendor/bitmap/bitmap_image.hpp"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

// linear interpolation function
float lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

RayScanner::RayScanner(VPO objects) : m_objects(objects)
{
}
void RayScanner::scan()
{
    // shoot a ray from the camera to the screen
    for (int i = 0; i < SREEN_LENGTH; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {

            Vec3D endPoint = Vec3D(-(SCREEN_WIDTH / 2) + j, 0, (SCREEN_WIDTH / 2) - i); // every point on my screen
            Vec3D origin = Vec3D(0, -1700, 200);                                        // camera or "eye"
            Vec3D dir = endPoint - origin;
            Ray startPoint = Ray(origin, dir, m_objects);

            Info bestHit = startPoint.scan();     // returns information about the clostest hit
            Vec3D light = Vec3D(1, -1, 1).unit(); // directional light vector!
            int bounce = 5;
            m_screenBuffer[i][j] = giveMeColorPls(bestHit, light, dir, bounce);
        }
    }
}

Color RayScanner::giveMeColorPls(Info bestHit, Vec3D lightDir, Vec3D direction, int bounce)

{

    Color color = Color(0, 0, 0); // color to use if there is no hit
    if (bestHit.m_hit)
    {

        // directional light
        color = bestHit.m_color;
        Vec3D normal = bestHit.m_normal.unit();
        lightDir = lightDir;
        float dotResult = normal.dot(lightDir);
        float lightIntensity = std::min(std::max(dotResult, 0.0f), 1.0f);
        color = Color(color.m_r * lightIntensity, color.m_g * lightIntensity, color.m_b * lightIntensity);

        // shadow casting
        Ray lightDirRay = Ray(bestHit.m_coord + (0.003 * lightDir), lightDir, m_objects);
        Info lightHit = lightDirRay.scan();
        if (lightHit.m_hit)
        {
            color = Color(0, 0, 0);
        }

        // recursively reflecting my ray, compute new color.
        if (bounce > 0)
        {
            Vec3D reflectedDir = direction - (2 * (direction.dot(normal)) * normal);
            Ray reflectedRay = Ray(bestHit.m_coord + (0.003 * reflectedDir), reflectedDir, m_objects);
            Info reflectedHit = reflectedRay.scan();
            Color temp;
            if (reflectedHit.m_hit)
            {
                temp = giveMeColorPls(reflectedHit, lightDir, reflectedDir, bounce - 1);
            }
            else
            {
                temp = Color(0, 0, 0);
            }
            float percentage = 0.5f;

            color = Color(std::round(lerp(color.m_r, temp.m_r, percentage)),
                          std::round(lerp(color.m_g, temp.m_g, percentage)),
                          std::round(lerp(color.m_b, temp.m_b, percentage)));
        }
    }

    return color;
}

void RayScanner::render()
{

    // writes the image to a BMP file.
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
