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

    for (int i = 0; i < 400; i++)
    {
        for (int j = 0; j < 400; j++)
        {
            int realJ = -200 + j;
            int realI = 200 - i;

            Vec3D endPoint = Vec3D(realJ, 0, realI);
            Vec3D origin = Vec3D(realJ, -600, realI + 100);
            Vec3D dir = endPoint - origin;

            Ray startPoint = Ray(origin, dir, m_objects);

            origin.show("Origin: ");
            if (startPoint.scan())
            {
                m_screenBuffer[i][j] = "]]]";
            }
            else
            {
                m_screenBuffer[i][j] = "   ";
            }
        }
    }
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
