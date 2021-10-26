// #include <vector>
// #include <string>
// #include <iostream>
// #include <algorithm>
// #include <cmath>

// struct Vec3D
// {
//     float x, y, z;
// };

// Vec3D vec3d(float x, float y, float z)
// {
//     Vec3D v{x, y, z};
//     return v;
// }

// void show(std::string label, Vec3D const &self)
// {
//     std::cout << label << ": " << self.x << ", " << self.y << ", " << self.z << std::endl;
// }

// void show(std::string label, float scalar)
// {
//     std::cout << label << ": " << scalar << std::endl;
// }

// void show()
// {
//     std::cout << std::endl;
// }

// Vec3D minus(Vec3D &self)
// {
//     Vec3D v{-self.x, -self.y, -self.z};
//     return v;
// }

// Vec3D add(Vec3D const &self, Vec3D const &other)
// {
//     Vec3D v{self.x + other.x, self.y + other.y, self.z + other.z};
//     return v;
// }

// Vec3D sub(Vec3D const &self, Vec3D const &other)
// {
//     Vec3D v{self.x - other.x, self.y - other.y, self.z - other.z};
//     return v;
// }

// Vec3D div(Vec3D const &self, float scalar)
// {
//     Vec3D v{self.x / scalar, self.y / scalar, self.z / scalar};
// }

// float norm(Vec3D const &self)
// {
//     float length = sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
// }

// Vec3D unit(Vec3D const &self)
// {
//     float length = sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
//     Vec3D v{self.x / length, self.y / length, self.z / length};
//     return v;
// }

// Vec3D dot(Vec3D const &self, Vec3D const &other)
// {
//     Vec3D v{self.x * other.x, self.y * other.y, self.z * other.z};
//     return v;
// }

// Vec3D cross(Vec3D const &self, Vec3D const &other)
// {
//     Vec3D v{self.y * other.z - self.z * other.y, self.z * other.x - self.x * other.z, self.x * other.y - self.y * other.x};
//     return v;
// }