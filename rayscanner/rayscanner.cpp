#include "rayscanner.hpp"
#include "../ray/ray.hpp"
#include "../sphere/sphere.hpp"
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
            // int jj = j - SCREEN_WIDTH / 2;
            // int ii = i - SREEN_LENGTH / 2;
            // std::cout << "i: " << ii << " j: " << jj << std::endl;
            // int ii = i;
            // int jj = j;

            Vec3D endPoint = Vec3D(-(SCREEN_WIDTH / 2) + j, 0, (SCREEN_WIDTH / 2) - i);
            Vec3D origin = Vec3D(0, -600, 200);

            Vec3D dir = endPoint - origin;

            Ray startPoint = Ray(origin, dir, m_objects);

            int intensity = startPoint.scan();
            m_screenBuffer[i][j] = (int)std::round(intensity / 10.0 * 255);

            // // std::cout << intensity;

            // // THIS IS JUST FOR TESTING PURPOSES!!!!
            // if(intensity == 0) {
            //     m_screenBuffer[i][j] = "   ";
            // }
            // else if (intensity == 1)
            // {
            //     m_screenBuffer[i][j] = "LLL";
            // }
            // else if (intensity == 2)
            // {
            //     m_screenBuffer[i][j] = "MMM";
            // }
            // else if (intensity == 3)
            // {
            //     m_screenBuffer[i][j] = "KKK";
            // }
            // else if (intensity == 4)
            // {
            //     m_screenBuffer[i][j] = "TTT";
            // }
            // else if (intensity == 5)
            // {
            //     m_screenBuffer[i][j] = "UUU";
            // }
            // else if (intensity == 6)
            // {
            //     m_screenBuffer[i][j] = "VVV";
            // }
            // else if (intensity == 7)
            // {
            //     m_screenBuffer[i][j] = "WWW";
            // }
            // else if (intensity == 8)
            // {
            //     m_screenBuffer[i][j] = "XXX";
            // }
            // else if (intensity == 9)
            // {
            //     m_screenBuffer[i][j] = "YYY";
            // }
        }
        // std::cout << "\n";
    }
    // 𝙺𝙼𝚁𝙽𝚃
}

void RayScanner::render()
{
    // for (int i = 0; i < SCREEN_WIDTH; i++)
    // {
    //     for (int j = 0; j < SREEN_LENGTH; j++)
    //     {
    //         std::cout << m_screenBuffer[i][j];
    //     }
    //     std::cout << std::endl;
    // }
    //setup file operations
    FILE *pgmImg;
    pgmImg = fopen("test.pgm", "wb");

    if (pgmImg == NULL)
    { //check is pointer is valid
        return;
    }

    //setup setting for pgm
    fprintf(pgmImg, "P2\n");                                //magic number
    fprintf(pgmImg, "%d %d\n", SCREEN_WIDTH, SCREEN_WIDTH); // Writing Width and Height
    fprintf(pgmImg, "255\n");                               // Writing the maximum gray value
    int temp;

    for (int y = 0; y < SCREEN_WIDTH; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {

            temp = m_screenBuffer[y][x];
            fprintf(pgmImg, "%d ", temp); //store value in file 0<255
        }
        std::cout << y << std::endl;
        fprintf(pgmImg, "\n"); //enter newline in file
    }
    fclose(pgmImg);
}
