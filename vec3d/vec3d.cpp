#include "vec3d.hpp"
#include <string>
#include <iostream>
#include <cmath>

Vec3D::Vec3D(float m_x, float m_y, float m_z) : m_x(m_x), m_y(m_y), m_z(m_z) {}

void Vec3D::show(std::string label)
{
    std::cout << label << ": " << m_x << ", " << m_y << ", " << m_z << std::endl;
}

void Vec3D::show(std::string label, float scaler)
{
    std::cout << label << ": " << m_x * scaler << ", " << m_y * scaler << ", " << m_z * scaler << std::endl;
}

void Vec3D::show()
{
    std::cout << std::endl;
}

Vec3D Vec3D::minus()
{
    return Vec3D(-m_x, -m_y, -m_z);
}

Vec3D Vec3D::operator+(Vec3D const &other) const
{
    return Vec3D(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

Vec3D Vec3D::operator-(Vec3D const &other) const
{
    return Vec3D(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
}

Vec3D Vec3D::operator*(float scalar) const {
    return Vec3D(m_x * scalar, m_y * scalar, m_z * scalar);
}

Vec3D Vec3D::operator/(float scalar)
{
    return Vec3D(m_x / scalar, m_y / scalar, m_z / scalar);
}

bool Vec3D::operator==(const Vec3D &other) const 
{
    return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
}

float Vec3D::norm()
{
    float length = std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2) + std::pow(m_z, 2));
    return length;
}

float Vec3D::dot(Vec3D const &other) const
{
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

Vec3D Vec3D::cross(Vec3D const &other) 
{
    return Vec3D(m_y * other.m_z - m_z * other.m_y, m_z * other.m_x - m_x * other.m_z, m_x * other.m_y - m_y * other.m_x);
}

Vec3D Vec3D::unit() {
    float length = norm();
    return Vec3D(m_x / length, m_y / length, m_z / length);
}