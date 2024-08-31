#pragma once

class Tuple
{
public:
    Tuple();
    Tuple(float x, float y, float z, float w);

    float m_x;
    float m_y;
    float m_z;
    float m_w;
};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);