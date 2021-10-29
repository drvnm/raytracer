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
    Sphere sphere1 = Sphere(Vec3D(80, 50, 100), 40);
    Sphere sphere2 = Sphere(Vec3D(-30, 50, 100), 50);
    Sphere sphere3 = Sphere(Vec3D(-150, 10, 100), 30);

    objects.push_back(&sphere1);
    objects.push_back(&sphere2);
    objects.push_back(&sphere3);
    objects.push_back(&f);

    RayScanner scanner = RayScanner(objects);
    scanner.scan();
    scanner.render();
}
