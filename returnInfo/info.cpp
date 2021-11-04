#include "info.hpp"

Info::Info(float t, bool hit, Vec3D coord, Vec3D normal, Color color, std::string type)
{
    m_t = t;
    m_hit = hit;
    m_coord = coord;
    m_normal = normal;
    m_color = color;
    m_type = type;
}

Info::Info() {
    
}