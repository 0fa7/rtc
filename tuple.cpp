#include "tuple.hpp"

Tuple::Tuple() :
    m_x{0.f}, m_y{0.f}, m_z{0.f}, m_w{0.f}
{
}

Tuple::Tuple(float x, float y, float z, float w) :
    m_x{x}, m_y{y}, m_z{z}, m_w{w}
{
}

Tuple Point(float x, float y, float z)
{
    return Tuple(x, y, z, 1.f);
}

Tuple Vector(float x, float y, float z)
{
    return Tuple(x, y, z, 0.f);
}