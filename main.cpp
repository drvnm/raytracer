#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#include "vec3d/vec3d.hpp"
#include "ray/ray.hpp"
#include "sphere/sphere.hpp"
#include "floor/floor.hpp"
#include "rayscanner/rayscanner.hpp"

#define ROWS 180
#define COLS 180
#define CELLHEIGHT 5
#define CELLWIDTH 10
#define HSQUARECOUNT (COLS / CELLWIDTH)

int main()
{
    // std::vector<std::vector<std::string>>
    //     board;
    // for (int y = 0; y < ROWS; y++)
    // {
    //     std::vector<std::string> row(COLS);
    //     for (int cx = 0; cx < HSQUARECOUNT; cx++)
    //     {
    //         int cy = y / CELLHEIGHT;
    //         std::fill(
    //             row.begin() + cx * CELLWIDTH,
    //             row.begin() + (cx + 1) * CELLWIDTH,
    //             (cx + cy) % 2 == 0 ? " " : "L");
    //     }
    //     board.push_back(row);
    // }

    // int xOrigin = (int)ROWS / 2;
    // int yOrigin = (int)COLS / 2;
    // int horizontalRadius = 40;
    // int verticalRadius = 20;

    // // draws the border of a circle in the board
    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //     {
    //         int dist = (std::pow(j - xOrigin, 2) / std::pow(horizontalRadius, 2)) + (std::pow(i - xOrigin, 2) / std::pow(verticalRadius, 2));
    //         if (dist == 1)
    //         {
    //             if (board[i][j] == " ")
    //                 board[i][j] = "L";
    //             else if (board[i][j] == "L")
    //                 board[i][j] = "N";
    //         }
    //     }
    // }

    Floor f = Floor();
    // for (int i = 0; i < f.m_floor.size(); i++)
    // {
    //     for (int j = 0; j < f.m_floor[0].size(); j++)
    //     {
    //         std::cout << f.m_floor[i][j];
    //     }
    //     std::cout << std::endl;
    // }

    std::vector<Object *> objects;
    Sphere sphere1 = Sphere(Vec3D(0, 50, 50), 50);
    Sphere sphere2 = Sphere(Vec3D(130, 100, 50), 30);
    Sphere sphere3 = Sphere(Vec3D(180, 50, 20), 20);

    objects.push_back(&sphere1);
    objects.push_back(&sphere2);
    objects.push_back(&sphere3);
    objects.push_back(&f);

    RayScanner scanner = RayScanner(objects);
    scanner.scan();
    scanner.render();
}

// std::vector<Sphere> spheres{
//     Sphere(Vec3D(-0.4, 0.23, -1), 0.4),
//     Sphere(Vec3D(0.4, 0.4, -1.2), 0.3),
//     Sphere(Vec3D(0.7, -0.15, -1.5), 0.2),
// };

// float far = 1.0f;
// std::vector<Ray> rays{
//     Ray(Vec3D(-far, 0.23, -1), Vec3D(far, 0, 0)),
//     Ray(Vec3D(0.4, -far, -1.2), Vec3D(0, far, 0)),
//     Ray(Vec3D(0.7, -0.15, -far), Vec3D(0, 0, far)),
// };

// for (auto sphere : spheres)
// {
//     for (auto ray : rays)
//     {
//         auto hitpoint =  sphere.hitPoint(ray);
//         if (!(hitpoint == Vec3D(0, 0, 0)))
//         {
//             sphere.m_centre.show("Sphere");
//             (ray.m_origin + ray.m_direction).show("ray");
//             hitpoint.show("Hitpoint");
//         }
//     }
// }
