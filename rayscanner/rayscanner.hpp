#pragma once

#include "../object/object.hpp"
#include "../sphere/sphere.hpp"
#include "../color/color.hpp"
#include "../returnInfo/info.hpp"

#include <vector>
#include <string>

typedef std::vector<Object *> VPO;

class RayScanner
{
public:
    VPO m_objects;
    std::vector<std::vector<Color>> m_screenBuffer = std::vector<std::vector<Color>>(3000, std::vector<Color>(3000));
    RayScanner(VPO objects);
    void scan();
    // void scanLight(Sphere &sphere);
    void render();
    Color giveMeColorPls(Info bestHit, Vec3D lightDir, Vec3D direction, int bounce);
};