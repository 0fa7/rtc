#include "tuple.hpp"
#include <algorithm>
#include <cmath>

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

Tuple& Tuple::operator*=(float b)
{
    m_x *= b;
    m_y *= b;
    m_z *= b;
    m_w *= b;
    return *this;
}

Tuple& Tuple::operator/=(float b)
{
    m_x /= b;
    m_y /= b;
    m_z /= b;
    m_w /= b;
    return *this;
}

float Tuple::VecMag() const
{
    return std::sqrtf(m_x * m_x +
        m_y * m_y +
        m_z * m_z);
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

Tuple operator-(const Tuple& a, const Tuple& b)
{
    float w = 1.f;

    if(a.m_w == b.m_w)
    {
        w = 0.f;
    }

    return Tuple(a.m_x - b.m_x,
        a.m_y - b.m_y,
        a.m_z - b.m_z,
        w);
}

Tuple operator*(float a, const Tuple& b)
{
    return Tuple(a * b.m_x,
        a * b.m_y,
        a * b.m_z,
        a * b.m_w);
}

Tuple operator/(const Tuple& a, float b)
{
    return Tuple(a.m_x / b,
        a.m_y / b,
        a.m_z / b,
        a.m_w / b);
}

float VecMag(const Tuple& a)
{
    return a.VecMag();
}

Tuple Normalize(const Tuple& a)
{
    float mag = a.VecMag();

    return Tuple(a.m_x / mag,
        a.m_y / mag,
        a.m_z / mag,
        a.m_w / mag);
}

/*
the smaller the dot product, the larger the angle between the vectors. For
example, given two unit vectors, a dot product of 1 means the vectors are
identical, and a dot product of -1 means they point in opposite directions.
More specifically, and again if the two vectors are unit vectors, the dot product
is actually the cosine of the angle between them.
*/

float Dot(const Tuple& a, const Tuple& b)
{
    return a.m_x * b.m_x +
        a.m_y * b.m_y +
        a.m_z * b.m_z +
        a.m_w * b.m_w;
}

/*
If you take the cross product of (unit vectors) X and Y, you get Z. Similarly, Y cross Z gets
you X, and Z cross X is Y. The results are always perpendicular to the inputs.
Again, order is important here. X cross Y gives you Z, but Y cross X gives you -Z
*/

Tuple Cross(const Tuple& a, const Tuple& b)
{
    return Vector(a.m_y * b.m_z - a.m_z * b.m_y,
        a.m_z * b.m_x - a.m_x * b.m_z,
        a.m_x * b.m_y - a.m_y * b.m_x);
}