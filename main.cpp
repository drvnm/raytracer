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

    Floor f = Floor(0);

    std::vector<Object *> objects;
    Sphere sphere1 = Sphere(Vec3D(1000, 50, 500), 300, 1);
    Sphere sphere2 = Sphere(Vec3D(0, 50, 100), 300, 1);
    Sphere sphere3 = Sphere(Vec3D(-1000, 50, 500), 300, 1);

    objects.push_back(&f);
    objects.push_back(&sphere1);
    objects.push_back(&sphere3);
    objects.push_back(&sphere2);

    RayScanner scanner = RayScanner(objects);
    scanner.scan();
    scanner.render();
}
