#pragma once

#include <string>


class Vec3D
{
public:
    float m_x, m_y, m_z;
    Vec3D(){};
    Vec3D(float x, float y, float z);
    void show(std::string label);
    void show(std::string label, float scalar);
    void show();
    Vec3D minus();
    Vec3D operator+(Vec3D const &v) const;
    Vec3D operator-(Vec3D const &v) const;
    Vec3D operator*(float scalar) const;
    Vec3D operator/(float scalar);
    bool operator==(const Vec3D &v) const;
    float norm();
    Vec3D unit();
    float dot(Vec3D const &other) const;
    Vec3D cross(Vec3D const &other);
};
