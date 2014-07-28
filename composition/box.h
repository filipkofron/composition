#ifndef BOX_H
#define BOX_H

class Box;

#include <ostream>

#include "vec3.h"

class Box
{
public:
    Box();
    Box(const Box &box);
    Box(const Vec3 &a, const Vec3 &b);

    void sort();

    bool contains(const Vec3 &vec) const;
    bool contains(const Box &box) const;
    Box intersect(const Box &box) const;
    bool intersects(const Box &box) const;

    double volume() const;

    Vec3 m_A;
    Vec3 m_B;
};

std::ostream &operator << (std::ostream &os, const Box &box);

#endif // BOX_H
