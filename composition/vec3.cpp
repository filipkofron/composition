#include "vec3.h"

Vec3::Vec3()
    : m_X(0.0), m_Y(0.0), m_Z(0.0)
{
}

Vec3::Vec3(const Vec3 &orig)
    : m_X(orig.m_X), m_Y(orig.m_Y), m_Z(orig.m_Z)
{

}

Vec3::Vec3(const double &m_X, const double &m_Y, const double &m_Z)
    : m_X(m_X), m_Y(m_Y), m_Z(m_Z)
{

}

std::ostream &operator << (std::ostream &os, const Vec3 &vec3)
{
    os << "(" << vec3.m_X << ", " << vec3.m_Y << ", " << vec3.m_Z << ")";
    return os;
}
