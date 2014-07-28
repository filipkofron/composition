#ifndef VEC3_H
#define VEC3_H

class Vec3;

#include <ostream>

class Vec3
{
public:
    Vec3();
    Vec3(const Vec3 &orig);
    Vec3(const double &x, const double &y, const double &z);

    double m_X, m_Y, m_Z;
};

std::ostream &operator << (std::ostream &os, const Vec3 &vec3);

#endif // VEC3_H
