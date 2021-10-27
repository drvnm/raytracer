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

int main()
{

    Floor f = Floor();

    std::vector<Object *> objects;
    Sphere sphere1 = Sphere(Vec3D(-150, 30, 100), 70);
    Sphere sphere2 = Sphere(Vec3D(0, 30, 100), 50);
    Sphere sphere3 = Sphere(Vec3D(100, 30, 100), 30);

    objects.push_back(&sphere1);
    objects.push_back(&sphere2);
    objects.push_back(&sphere3);
    objects.push_back(&f);

    RayScanner scanner = RayScanner(objects);
    scanner.scan();
    scanner.render();
}
