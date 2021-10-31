#pragma once

#include "../object/object.hpp"
#include <vector>
#include <string>

typedef std::vector<Object *> VPO;

class RayScanner
{
public:
    VPO m_objects;
    std::vector<std::vector<int>> m_screenBuffer = std::vector<std::vector<int>>(3000, std::vector<int>(3000));

    RayScanner(VPO objects);
    void scan();
    void render();
};