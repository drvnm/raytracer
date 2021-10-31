#pragma once

#include "../object/object.hpp"
#include "../color/color.hpp"
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
    void render();
};