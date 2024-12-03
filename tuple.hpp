#pragma once

class Tuple {
public:
  Tuple();
  Tuple(float x, float y, float z, float w);

  Tuple &operator+=(const Tuple &b);
  Tuple &operator-=(const Tuple &b);
  Tuple &operator*=(float b);
  Tuple &operator/=(float b);

  float VecMag() const;

  float m_x;
  float m_y;
  float m_z;
  float m_w;
};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);
Tuple Color(float x, float y, float z);

bool operator==(const Tuple &a, const Tuple &b);

Tuple operator+(const Tuple &a, const Tuple &b);
Tuple operator-(const Tuple &a);
Tuple operator-(const Tuple &a, const Tuple &b);
Tuple operator*(float a, const Tuple &b);
Tuple operator*(const Tuple &a, const Tuple &b);
Tuple operator/(const Tuple &a, float b);

float VecMag(const Tuple &a);
Tuple Normalize(const Tuple &a);
float Dot(const Tuple &a, const Tuple &b);
Tuple Cross(const Tuple &a, const Tuple &b);