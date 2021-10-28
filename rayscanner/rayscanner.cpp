#include "rayscanner.hpp"
#include "../ray/ray.hpp"
#include <iostream>
#define SCREEN_WIDTH 400
#define SREEN_LENGTH 400

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
            // int jj = j - SCREEN_WIDTH / 2;
            // int ii = i - SREEN_LENGTH / 2;
            // std::cout << "i: " << ii << " j: " << jj << std::endl;
            // int ii = i;
            // int jj = j;
            Vec3D endPoint = Vec3D(-200 + j, 0, 200 - i);

            Vec3D origin = Vec3D(0, -400, 200);
            Vec3D dir = endPoint - origin;

            Ray startPoint = Ray(origin, dir, m_objects);

            int intensity = startPoint.scan();
            if (intensity == 0)
            {
                m_screenBuffer[i][j] = "   ";
            }
            else if (intensity == 1)
            {
                m_screenBuffer[i][j] = "lll";
            }
            else if (intensity == 2)
            {
                m_screenBuffer[i][j] = "MMM";
            }
            else if (intensity == 3)
            {
                m_screenBuffer[i][j] = "\u001b[30mKKK\033[0m";
            }
            else if (intensity == 4)
            {
                m_screenBuffer[i][j] = "TTT";
            }
                }
    }
    // 𝙺𝙼𝚁𝙽𝚃
}

void RayScanner::render()
{
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < SREEN_LENGTH; j++)
        {
            std::cout << m_screenBuffer[i][j];
        }
        std::cout << std::endl;
    }
}
