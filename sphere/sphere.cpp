#include "sphere.hpp"
#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

// ray constructor
Sphere::Sphere(const Vec3D &centre, float radius, int zIndex, const Color &color, std::string type)
{
    m_centre = centre;
    m_radius = radius;
    m_type = type;
    intensity = 1;
    m_zIndex = zIndex;
    m_color = color;
}

// returns distance from center to ray
float Sphere::distFromRay(Ray &ray) const
{
    Vec3D origin = ray.m_origin;
    Vec3D point = hitPoint(ray);
    if (point.m_x == 0 && point.m_y == 0 && point.m_z == 0)
    {
        return -1;
    }
    return std::sqrt(std::pow(point.m_x - origin.m_x, 2) +
                     std::pow(point.m_y - origin.m_y, 2) +
                     std::pow(point.m_z - origin.m_z, 2));
}

Info Sphere::hit(Ray &ray) const
{

    // reflect the Ray on the hitpoint on the Sphere
    Info info;
    Vec3D hitpoint = hitPoint(ray);
    Vec3D normal = hitpoint - m_centre;
    normal = normal.unit();

    Vec3D v = ray.m_origin - m_centre;
    float a = ray.m_direction.dot(ray.m_direction);
    float b = 2 * v.dot(ray.m_direction);
    float c = (v.dot(v)) - (m_radius * m_radius);

    float discriminant = b * b - 4 * a * c;
    float t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    float t2 = (-b + std::sqrt(discriminant)) / (2 * a);
    float t = std::min(std::abs(t1), std::abs(t2));

    if (discriminant < 0)
    {
        info = Info(t, false, Vec3D(0, 0, 0), normal, m_color);
        return info;
    }
    else if (t1 < 0 || t2 < 0)
    {
        info = Info(t, false, Vec3D(0, 0, 0), normal, m_color);
        return info;
    }
    else
    {
      
        Vec3D reflect = (ray.m_direction - (2 * ray.m_direction.dot(normal) * normal)).unit();
        ray.m_origin = hitpoint + (0.001 * reflect);
        ray.m_direction = reflect;
        info = Info(t, true, hitpoint, normal, m_color);

        return info;
    }
}
bool Sphere::hitLight(Ray &ray) const
{

    // reflect the Ray on the hitpoint on the Sphere
    Info info;
    Vec3D hitpoint = hitPoint(ray);
    Vec3D normal = hitpoint - m_centre;
    normal = normal.unit();

    Vec3D v = ray.m_origin - m_centre;
    float a = ray.m_direction.dot(ray.m_direction);
    float b = 2 * v.dot(ray.m_direction);
    float c = (v.dot(v)) - (m_radius * m_radius);

    float discriminant = b * b - 4 * a * c;
    float t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    float t2 = (-b + std::sqrt(discriminant)) / (2 * a);
    float t = std::min(std::abs(t1), std::abs(t2));

    if (discriminant < 0)
    {
        // info = I?nfo(t, false, Vec3D(0, 0, 0), normal, m_color);
        return false;
    }
    else if (t1 < 0 || t2 < 0)
    {
        // info = Info(t, false, Vec3D(0, 0, 0), normal, m_color);
        return false;
    }
    else
    {
      
        return true;

    }
}

// Returns the point where the ray intersects the sphere
Vec3D Sphere::hitPoint(Ray const &ray) const
{
    Vec3D v = ray.m_origin - m_centre;
    float a = ray.m_direction.dot(ray.m_direction);
    float b = 2 * v.dot(ray.m_direction);
    float c = (v.dot(v)) - (m_radius * m_radius);

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return Vec3D(0, 0, 0);

    float t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    float t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    int t = std::min(t1, t2);
    if (t < 0)
        t = std::max(t1, t2);

    return ray.m_origin + (t * ray.m_direction);
}
