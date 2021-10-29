#include "sphere.hpp"
#include "../vec3d/vec3d.hpp"
#include "../ray/ray.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

// ray constructor
Sphere::Sphere(const Vec3D &centre, float radius)
    : m_centre(centre), m_radius(radius)
{
    m_type = "Sphere";
    intensity = 1;
}

// returns distance from center to ray
float Sphere::distFromRay(const Ray &ray) const
{
    return std::sqrt(std::pow(m_centre.m_x - ray.m_direction.m_x, 2) +
                     std::pow(m_centre.m_y - ray.m_direction.m_y, 2) +
                     std::pow(m_centre.m_z - ray.m_direction.m_z, 2));
}

bool Sphere::hit(Ray &ray) const
{

    // reflect the Ray on the hitpoint on the Sphere
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

    if (discriminant < 0)
    {
        return false;
    }
    else if (t1 < 0 || t2 < 0)
    {
        return false;
    }
    else
    {
        // ray.m_direction.show("Incomming ray");
        Vec3D reflect = (ray.m_direction - (2 * ray.m_direction.dot(normal) * normal)).unit();
        ray.m_origin = hitpoint + (0.001 * reflect);
        // ray.m_origin.show("origin of \"reflected\" ray: ");
        ray.m_direction = reflect;
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

    // if(t1 < t2) {
    //     return ray.m_origin + (t1 * ray.m_direction);
    // } else {
    //     return ray.m_origin + (t2 * ray.m_direction);
    // }

    int t = std::min(t1, t2);
    if (t < 0)
        t = std::max(t1, t2);

    // std::cout << "t: " << t << " t1 " << t1 << " t2 " << t2 << std::endl;
    return ray.m_origin + (t * ray.m_direction);
}
