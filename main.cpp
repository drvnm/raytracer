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
#include "color/color.hpp"

int main()
{

    Color red = Color(255, 0, 0);
    Color green = Color(0, 255, 0);
    Color blue = Color(0, 0, 255);
    Color black = Color(0, 0, 0);
    Color white = Color(255, 255, 255);
    Floor f = Floor(0, white);

    std::vector<Object *> objects;
    Sphere sphere1 = Sphere(Vec3D(500, 50, 500), 50, 1, Color(154, 255, 215));
    Sphere sphere2 = Sphere(Vec3D(0, 50, 500), 300, 1, Color(255, 99, 71));
    Sphere sphere3 = Sphere(Vec3D(-500, 10, 500), 50, 1, white);

    objects.push_back(&f);
    objects.push_back(&sphere1);
    objects.push_back(&sphere3);
    objects.push_back(&sphere2);

    RayScanner scanner = RayScanner(objects);
    scanner.scan();
    scanner.render();
}
