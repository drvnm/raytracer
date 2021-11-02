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
    Color purple = Color(128, 0, 128);
    Color black = Color(0, 0, 0);
    Color white = Color(255, 255, 255);
    Sphere light = Sphere(Vec3D(0, 50, 100), 20, 1, white, "light");

    Floor f = Floor(0, white);

    std::vector<Object *> objects;
    Sphere sphere3 = Sphere(Vec3D(-700, 50, 500), 300, 1, purple, "sphere");
    Sphere sphere1 = Sphere(Vec3D(700, 50, 100), 300, 1, Color(154, 255, 215), "sphere");
    Sphere sphere2 = Sphere(Vec3D(0, 200, 500), 300, 1, Color(255, 99, 71), "sphere");

      objects.push_back(&sphere1);
    objects.push_back(&sphere2);
    objects.push_back(&sphere3);
    objects.push_back(&f);

    RayScanner scanner = RayScanner(objects);
    scanner.scan();
    // scanner.scanLight(light);
    scanner.render();
}
