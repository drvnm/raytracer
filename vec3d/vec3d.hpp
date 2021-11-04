/* 
REQUIREMENTS:
I had to make a class that represents a 3D vector.
It has to be able to be initialized with 3 values, and do some basic vector operations.
I've overloaded my operaterors, instead of making a bunch of functions.

TESTSPEC:
I've tested my class with the following:
Test the different method / operator combinations

Design:
The class is pretty simmilar to the one described in the assignment.
I went with operator overloading because it makes my code cleaner / clearer.

*/

#pragma once

#include <string>

class Vec3D
{
public:
    float m_x, m_y, m_z;
    Vec3D(){};
    Vec3D(float x, float y, float z); //constructor
    void show(std::string label);
    void show(std::string label, float scalar);
    void show();
    Vec3D minus();
    // overloaded operaterors
    Vec3D operator+(Vec3D const &v) const;
    Vec3D operator-(Vec3D const &v) const;
    Vec3D operator-(float other) const;
    Vec3D operator*(float scalar) const;
    friend Vec3D operator*(float scalar, Vec3D self);
    Vec3D operator/(float scalar);
    bool operator==(const Vec3D &v) const;

    float norm(); //returns the norm of the vector
    Vec3D unit(); //returns the unit vector
    float dot(Vec3D const &other) const; //returns the dot product between 2 vectors
    Vec3D cross(Vec3D const &other); //returns the cross product between 2 vectors
};
