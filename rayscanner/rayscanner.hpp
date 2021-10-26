#pragma once

#include "../object/object.hpp"
#include <vector>
#include <string>

typedef std::vector<Object *> VPO;

class RayScanner
{
public:
    VPO m_objects;
    std::vector<std::vector<std::string>> m_screenBuffer = std::vector<std::vector<std::string>>(400, std::vector<std::string>(400));

    RayScanner(VPO objects);
    void scan();
    void render();
};