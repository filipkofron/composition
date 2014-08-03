#include "box.h"

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

#define PRECISION_UNIT 1e-10

Box::Box()
{
}

Box::Box(const Box &box)
    : m_A(box.m_A), m_B(box.m_B)
{

}

Box::Box(const Vec3 &a, const Vec3 &b)
    : m_A(a), m_B(b)
{
    sort();
}

void Box::sort()
{
    double t;
    if(m_A.m_X > m_B.m_X)
    {
        t = m_B.m_X;
        m_B.m_X = m_A.m_X;
        m_A.m_X = t;
    }
    if(m_A.m_Y > m_B.m_Y)
    {
        t = m_B.m_Y;
        m_B.m_Y = m_A.m_Y;
        m_A.m_Y = t;
    }
    if(m_A.m_Z > m_B.m_Z)
    {
        t = m_B.m_Z;
        m_B.m_Z = m_A.m_Z;
        m_A.m_Z = t;
    }
}

bool Box::contains(const Vec3 &vec) const
{
    return vec.m_X >= m_A.m_X && vec.m_X <= m_B.m_X
        && vec.m_Y >= m_A.m_Y && vec.m_Y <= m_B.m_Y
        && vec.m_Z >= m_A.m_Z && vec.m_Z <= m_B.m_Z;
}

bool Box::contains(const Box &box) const
{
    return box.m_A.m_X >= m_A.m_X && box.m_B.m_X <= m_B.m_X
        && box.m_A.m_Y >= m_A.m_Y && box.m_B.m_Y <= m_B.m_Y
        && box.m_A.m_Z >= m_A.m_Z && box.m_B.m_Z <= m_B.m_Z;
}

bool Box::touches(const Box &box) const
{
    return intersect(box).volume() > PRECISION_UNIT;
}

Box Box::intersect(const Box &box) const
{
    Box nbox;

    nbox.m_A.m_X = MAX(m_A.m_X, box.m_A.m_X);
    nbox.m_B.m_X = MIN(m_B.m_X, box.m_B.m_X);

    nbox.m_A.m_Y = MAX(m_A.m_Y, box.m_A.m_Y);
    nbox.m_B.m_Y = MIN(m_B.m_Y, box.m_B.m_Y);

    nbox.m_A.m_Z = MAX(m_A.m_Z, box.m_A.m_Z);
    nbox.m_B.m_Z = MIN(m_B.m_Z, box.m_B.m_Z);

    return nbox;
}

bool Box::intersects(const Box &box) const
{
    return ((box.m_A.m_X >= m_A.m_X && box.m_A.m_X <= m_B.m_X) || (box.m_B.m_X >= m_A.m_X && box.m_B.m_X <= m_B.m_X))
        && ((box.m_A.m_Y >= m_A.m_Y && box.m_A.m_Y <= m_B.m_Y) || (box.m_B.m_Y >= m_A.m_Y && box.m_B.m_Y <= m_B.m_Y))
        && ((box.m_A.m_Z >= m_A.m_Z && box.m_A.m_Z <= m_B.m_Z) || (box.m_B.m_Z >= m_A.m_Z && box.m_B.m_Z <= m_B.m_Z));
}

double Box::volume() const
{
    return (m_B.m_X - m_A.m_X) * (m_B.m_Y - m_A.m_Y) * (m_B.m_Z - m_A.m_Z);
}

std::ostream &operator << (std::ostream &os, const Box &box)
{
    os << "[" << box.m_A << ", " << box.m_B << "]";
    return os;
}
