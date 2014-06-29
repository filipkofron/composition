#include "vec3.h"

Vec3::Vec3()
    : x(0.0), y(0.0), z(0.0)
{
}

Vec3::Vec3(const Vec3 &orig)
    : x(orig.x), y(orig.y), z(orig.z)
{

}

Vec3::Vec3(const double &x, const double &y, const double &z)
    : x(x), y(y), z(z)
{

}

std::ostream &operator << (std::ostream &os, const Vec3 &vec3)
{
    os << "(" << vec3.x << ", " << vec3.y << ", " << vec3.z << ")";
    return os;
}
