#include "box.h"

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

Box::Box()
{
}

Box::Box(const Box &box)
    : a(box.a), b(box.b)
{

}

Box::Box(const Vec3 &a, const Vec3 &b)
    : a(a), b(b)
{
    sort();
}

void Box::sort()
{
    double t;
    if(a.x > b.x)
    {
        t = b.x;
        b.x = a.x;
        a.x = t;
    }
    if(a.y > b.y)
    {
        t = b.y;
        b.y = a.y;
        a.y = t;
    }
    if(a.z > b.z)
    {
        t = b.z;
        b.z = a.z;
        a.z = t;
    }
}

bool Box::contains(const Vec3 &vec) const
{
    return vec.x >= a.x && vec.x <= b.x
        && vec.y >= a.y && vec.y <= b.y
        && vec.z >= a.z && vec.z <= b.z;
}

bool Box::contains(const Box &box) const
{
    return box.a.x >= a.x && box.b.x <= b.x
        && box.a.y >= a.y && box.b.y <= b.y
        && box.a.z >= a.z && box.b.z <= b.z;
}

Box Box::intersect(const Box &box) const
{
    Box nbox;

    nbox.a.x = MAX(a.x, box.a.x);
    nbox.b.x = MIN(b.x, box.b.x);

    nbox.a.y = MAX(a.y, box.a.y);
    nbox.b.y = MIN(b.y, box.b.y);

    nbox.a.z = MAX(a.z, box.a.z);
    nbox.b.z = MIN(b.z, box.b.z);

    return nbox;
}

bool Box::intersects(const Box &box) const
{
    return ((box.a.x >= a.x && box.a.x <= b.x) || (box.b.x >= a.x && box.b.x <= b.x))
        && ((box.a.y >= a.y && box.a.y <= b.y) || (box.b.y >= a.y && box.b.y <= b.y))
        && ((box.a.z >= a.z && box.a.z <= b.z) || (box.b.x >= a.z && box.b.z <= b.z));
}

double Box::volume() const
{
    return (b.x - a.x) * (b.y - a.y) * (b.z - a.z);
}

std::ostream &operator << (std::ostream &os, const Box &box)
{
    os << "[" << box.a << ", " << box.b << "]";
    return os;
}
