#pragma once
#include "../vec3d/vec3d.hpp"
#include "../color/color.hpp"
#include <vector>
#include <string>

class Info
{
public:
    float m_t;
    bool m_hit;
    Vec3D m_coord;
    Vec3D m_normal;
    Color m_color;
    std::string m_type;
    Info(float t, bool hit, Vec3D coord, Vec3D normal, Color color, std::string type)
    {
        m_t = t;
        m_hit = hit;
        m_coord = coord;
        m_normal = normal;
        m_color = color;
        m_type = type;
    }
    Info()
    {
    }
};
