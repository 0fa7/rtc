#include "tuple.hpp"
#include <algorithm>

Tuple::Tuple() :
    m_x{0.f}, m_y{0.f}, m_z{0.f}, m_w{0.f}
{
}

Tuple::Tuple(float x, float y, float z, float w) :
    m_x{x}, m_y{y}, m_z{z}, m_w{w}
{
}

Tuple& Tuple::operator+=(const Tuple& b)
{
    m_x += b.m_x;
    m_y += b.m_y;
    m_z += b.m_z;
    m_w = std::max(m_w, b.m_w);
    return *this;
}

Tuple& Tuple::operator-=(const Tuple& b)
{
    m_x -= b.m_x;
    m_y -= b.m_y;
    m_z -= b.m_z;
    
    if(m_w == b.m_w)
    {
        m_w = 0.f;
    }
    else
    {
        m_w = 1.f;
    }
    
    return *this;
}

Tuple Point(float x, float y, float z)
{
    return Tuple(x, y, z, 1.f);
}

Tuple Vector(float x, float y, float z)
{
    return Tuple(x, y, z, 0.f);
}

Tuple operator+(const Tuple& a, const Tuple& b)
{
    return Tuple(a.m_x + b.m_x,
        a.m_y + b.m_y,
        a.m_z + b.m_z,
        std::max(a.m_w, b.m_w));
}

Tuple operator-(const Tuple& a)
{
    return Tuple(-a.m_x, -a.m_y, -a.m_z, a.m_w);
}