#pragma once

#define SCREEN_WIDTH 3000
#define SREEN_LENGTH 3000

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
    std::vector<std::vector<Color>> m_screenBuffer = std::vector<std::vector<Color>>(SREEN_LENGTH, std::vector<Color>(SCREEN_WIDTH));
    RayScanner(VPO objects);
    void scan();
    void render();
    Color giveMeColorPls(Info bestHit, Vec3D lightDir, Vec3D direction, int bounce);
};