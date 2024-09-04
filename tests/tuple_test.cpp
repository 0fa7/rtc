#include <cmath>
#include <gtest/gtest.h>
#include "../tuple.hpp"

TEST(TupleTest, Constructor)
{
    const float exp = 0.f;
    const Tuple sut;

    EXPECT_FLOAT_EQ(exp, sut.m_x);
    EXPECT_FLOAT_EQ(exp, sut.m_y);
    EXPECT_FLOAT_EQ(exp, sut.m_z);
    EXPECT_FLOAT_EQ(exp, sut.m_w);
}

TEST(TupleTest, ConstructorWithXYZWParams)
{
    const float expX = 1.f;
    const float expY = 2.f;
    const float expZ = 3.f;
    const float expW = 5.f;
    const Tuple sut(expX, expY, expZ, expW);
    
    EXPECT_FLOAT_EQ(expX, sut.m_x);
    EXPECT_FLOAT_EQ(expY, sut.m_y);
    EXPECT_FLOAT_EQ(expZ, sut.m_z);
    EXPECT_FLOAT_EQ(expW, sut.m_w);
}

TEST(TupleTest, OperatorInPlaceAddition)
{
    // point + vector
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 1.f;
        Tuple sut1 = Point(3.f, -2.f, 5.f);
        const Tuple sut2 = Vector(-2.f, 3.f, 1.f);

        sut1 += sut2;
    
        EXPECT_FLOAT_EQ(expX, sut1.m_x);
        EXPECT_FLOAT_EQ(expY, sut1.m_y);
        EXPECT_FLOAT_EQ(expZ, sut1.m_z);
        EXPECT_FLOAT_EQ(expW, sut1.m_w);
    }

    // vector + point
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 1.f;
        Tuple sut1 = Vector(3.f, -2.f, 5.f);
        const Tuple sut2 = Point(-2.f, 3.f, 1.f);

        sut1 += sut2;
    
        EXPECT_FLOAT_EQ(expX, sut1.m_x);
        EXPECT_FLOAT_EQ(expY, sut1.m_y);
        EXPECT_FLOAT_EQ(expZ, sut1.m_z);
        EXPECT_FLOAT_EQ(expW, sut1.m_w);
    }

    // point + point
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 1.f;
        Tuple sut1 = Point(3.f, -2.f, 5.f);
        const Tuple sut2 = Point(-2.f, 3.f, 1.f);

        sut1 += sut2;
    
        EXPECT_FLOAT_EQ(expX, sut1.m_x);Tuple operator*(float a, const Tuple& b);
        EXPECT_FLOAT_EQ(expY, sut1.m_y);
        EXPECT_FLOAT_EQ(expZ, sut1.m_z);
        EXPECT_FLOAT_EQ(expW, sut1.m_w);
    }

    // vector + vector
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 0.f;
        Tuple sut1 = Vector(3.f, -2.f, 5.f);
        const Tuple sut2 = Vector(-2.f, 3.f, 1.f);

        sut1 += sut2;
        
        EXPECT_FLOAT_EQ(expX, sut1.m_x);
        EXPECT_FLOAT_EQ(expY, sut1.m_y);
        EXPECT_FLOAT_EQ(expZ, sut1.m_z);
        EXPECT_FLOAT_EQ(expW, sut1.m_w);
    }
}

TEST(TupleTest, OperatorInPlaceSubtraction)
{
    // point - point
    {
        const float expX = -2.f;
        const float expY = -4.f;
        const float expZ = -6.f;
        const float expW = 0.f;
        Tuple sut1 = Point(3.f, 2.f, 1.f);
        const Tuple sut2 = Point(5.f, 6.f, 7.f);

        sut1 -= sut2;
    
        EXPECT_FLOAT_EQ(expX, sut1.m_x);
        EXPECT_FLOAT_EQ(expY, sut1.m_y);
        EXPECT_FLOAT_EQ(expZ, sut1.m_z);
        EXPECT_FLOAT_EQ(expW, sut1.m_w);
    }
    
    // point - vector
    {
        const float expX = -2.f;
        const float expY = -4.f;
        const float expZ = -6.f;
        const float expW = 1.f;
        Tuple sut1 = Point(3.f, 2.f, 1.f);
        const Tuple sut2 = Vector(5.f, 6.f, 7.f);

        sut1 -= sut2;
    
        EXPECT_FLOAT_EQ(expX, sut1.m_x);
        EXPECT_FLOAT_EQ(expY, sut1.m_y);
        EXPECT_FLOAT_EQ(expZ, sut1.m_z);
        EXPECT_FLOAT_EQ(expW, sut1.m_w);
    }

    // vector - vector
    {
        const float expX = -2.f;
        const float expY = -4.f;
        const float expZ = -6.f;
        const float expW = 0.f;
        Tuple sut1 = Vector(3.f, 2.f, 1.f);
        const Tuple sut2 = Vector(5.f, 6.f, 7.f);

        sut1 -= sut2;
    
        EXPECT_FLOAT_EQ(expX, sut1.m_x);
        EXPECT_FLOAT_EQ(expY, sut1.m_y);
        EXPECT_FLOAT_EQ(expZ, sut1.m_z);
        EXPECT_FLOAT_EQ(expW, sut1.m_w);
    }
}

TEST(TupleTest, OperatorInPlaceMultiplication)
{
    {
        const float expX = 3.5f;
        const float expY = -7.f;
        const float expZ = 10.5f;
        const float expW = -14.f;
        Tuple sut = Tuple(1.f, -2.f, 3.f, -4.f);

        sut *= 3.5f;

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    {
        const float expX = .5f;
        const float expY = -1.f;
        const float expZ = 1.5f;
        const float expW = -2.f;
        Tuple sut = Tuple(1.f, -2.f, 3.f, -4.f);

        sut *= .5f;

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }
}

TEST(TupleTest, OperatorInPlaceDivision)
{
    const float expX = .5f;
    const float expY = -1.f;
    const float expZ = 1.5f;
    const float expW = -2.f;
    Tuple sut = Tuple(1.f, -2.f, 3.f, -4.f);

    sut /= 2.f;

    EXPECT_FLOAT_EQ(expX, sut.m_x);
    EXPECT_FLOAT_EQ(expY, sut.m_y);
    EXPECT_FLOAT_EQ(expZ, sut.m_z);
    EXPECT_FLOAT_EQ(expW, sut.m_w);
}

TEST(TupleTest, MemberVecMag)
{
    {
        const float exp = 1.f;
        const Tuple sut = Vector(1.f, 0.f, 0.f);
    
        const float res = sut.VecMag();

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = 1.f;
        const Tuple sut = Vector(0.f, 1.f, 0.f);
    
        const float res = sut.VecMag();

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = 1.f;
        const Tuple sut = Vector(0.f, 0.f, 1.f);
    
        const float res = sut.VecMag();

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = std::sqrtf(14.f);
        const Tuple sut = Vector(1.f, 2.f, 3.f);
    
        const float res = sut.VecMag();

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = std::sqrtf(14.f);
        const Tuple sut = Vector(-1.f, -2.f, -3.f);
    
        const float res = sut.VecMag();

        EXPECT_FLOAT_EQ(exp, res);
    }
}

TEST(TupleTest, Point)
{
    const float expX = 4.3f;
    const float expY = -4.2f;
    const float expZ = 3.1f;
    const float expW = 1.f;
    const Tuple sut = Point(expX, expY, expZ);
    
    EXPECT_FLOAT_EQ(expX, sut.m_x);
    EXPECT_FLOAT_EQ(expY, sut.m_y);
    EXPECT_FLOAT_EQ(expZ, sut.m_z);
    EXPECT_FLOAT_EQ(expW, sut.m_w);
}

TEST(TupleTest, Vector)
{
    const float expX = 4.3f;
    const float expY = -4.2f;
    const float expZ = 3.1f;
    const float expW = 0.f;
    const Tuple sut = Vector(expX, expY, expZ);
    
    EXPECT_FLOAT_EQ(expX, sut.m_x);
    EXPECT_FLOAT_EQ(expY, sut.m_y);
    EXPECT_FLOAT_EQ(expZ, sut.m_z);
    EXPECT_FLOAT_EQ(expW, sut.m_w);
}

TEST(TupleTest, Color)
{
    const float expX = -.5f;
    const float expY = .4f;
    const float expZ = 1.7f;
    const float expW = 0.f;
    const Tuple sut = Color(expX, expY, expZ);
    
    EXPECT_FLOAT_EQ(expX, sut.m_x);
    EXPECT_FLOAT_EQ(expY, sut.m_y);
    EXPECT_FLOAT_EQ(expZ, sut.m_z);
    EXPECT_FLOAT_EQ(expW, sut.m_w);
}

TEST(TupleTest, OperatorAddition)
{
    // point + vector
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 1.f;
        const Tuple a1 = Point(3.f, -2.f, 5.f);
        const Tuple a2 = Vector(-2.f, 3.f, 1.f);

        const Tuple sut = a1 + a2;
    
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    // vector + point
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 1.f;
        const Tuple a1 = Vector(3.f, -2.f, 5.f);
        const Tuple a2 = Point(-2.f, 3.f, 1.f);

        const Tuple sut = a1 + a2;
    
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    // point + point
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 1.f;
        const Tuple a1 = Point(3.f, -2.f, 5.f);
        const Tuple a2 = Point(-2.f, 3.f, 1.f);

        const Tuple sut = a1 + a2;
        
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    // vector + vector
    {
        const float expX = 1.f;
        const float expY = 1.f;
        const float expZ = 6.f;
        const float expW = 0.f;
        const Tuple a1 = Vector(3.f, -2.f, 5.f);
        const Tuple a2 = Vector(-2.f, 3.f, 1.f);

        const Tuple sut = a1 + a2;
        
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    // color + color
    {
        const float expX = 1.6f;
        const float expY = .7f;
        const float expZ = 1.f;
        const float expW = 0.f;
        const Tuple a1 = Color(.9f, .6f, .75f);
        const Tuple a2 = Color(.7f, .1f, .25f);

        const Tuple sut = a1 + a2;
        
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }
}

TEST(TupleTest, OperatorNegate)
{
        const float expX = -1.f;
        const float expY = -1.f;
        const float expZ = -6.f;
        const float expW = 0.f;
        const Tuple a1 = Vector(-expX, -expY, -expZ);

        const Tuple sut = -a1;
        
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
}

TEST(TupleTest, OperatorSubtraction)
{
    // point - point
    {
        const float expX = -2.f;
        const float expY = -4.f;
        const float expZ = -6.f;
        const float expW = 0.f;
        const Tuple a1 = Point(3.f, 2.f, 1.f);
        const Tuple a2 = Point(5.f, 6.f, 7.f);

        const Tuple sut = a1 - a2;
    
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    // point - vector
    {
        const float expX = -2.f;
        const float expY = -4.f;
        const float expZ = -6.f;
        const float expW = 1.f;
        const Tuple a1 = Point(3.f, 2.f, 1.f);
        const Tuple a2 = Vector(5.f, 6.f, 7.f);

        const Tuple sut = a1 - a2;
    
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }
    
    // vector - vector
    {
        const float expX = -2.f;
        const float expY = -4.f;
        const float expZ = -6.f;
        const float expW = 0.f;
        const Tuple a1 = Vector(3.f, 2.f, 1.f);
        const Tuple a2 = Vector(5.f, 6.f, 7.f);

        const Tuple sut = a1 - a2;
    
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    // color - color
    {
        const float expX = .2f;
        const float expY = .5f;
        const float expZ = .5f;
        const float expW = 0.f;
        const Tuple a1 = Color(.9f, .6f, .75f);
        const Tuple a2 = Color(.7f, .1f, .25f);

        const Tuple sut = a1 - a2;
        
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }
}

TEST(TupleTest, OperatorMultiplication)
{
    {
        const float expX = 3.5f;
        const float expY = -7.f;
        const float expZ = 10.5f;
        const float expW = -14.f;
        Tuple a1 = Tuple(1.f, -2.f, 3.f, -4.f);

        Tuple sut = 3.5f * a1;

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    {
        const float expX = .5f;
        const float expY = -1.f;
        const float expZ = 1.5f;
        const float expW = -2.f;
        Tuple a1 = Tuple(1.f, -2.f, 3.f, -4.f);

        Tuple sut = .5f * a1;

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    {
        const float expX = .4f;
        const float expY = .6f;
        const float expZ = .8f;
        const float expW = 0.f;
        Tuple a1 = Color(.2f, .3f, .4f);

        Tuple sut = 2.f * a1;

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    // color * color
    {
        const float expX = .9f;
        const float expY = .2f;
        const float expZ = .04f;
        const float expW = 0.f;
        Tuple a1 = Color(1.f, .2f, .4f);
        Tuple a2 = Color(.9f, 1.f, .1f);

        Tuple sut = a1 * a2;

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }
}

TEST(TupleTest, OperatorDivision)
{
    const float expX = .5f;
    const float expY = -1.f;
    const float expZ = 1.5f;
    const float expW = -2.f;
    Tuple a = Tuple(1.f, -2.f, 3.f, -4.f);

    Tuple sut = a / 2.f;

    EXPECT_FLOAT_EQ(expX, sut.m_x);
    EXPECT_FLOAT_EQ(expY, sut.m_y);
    EXPECT_FLOAT_EQ(expZ, sut.m_z);
    EXPECT_FLOAT_EQ(expW, sut.m_w);
}

TEST(TupleTest, VecMag)
{
    {
        const float exp = 1.f;
        const Tuple sut = Vector(1.f, 0.f, 0.f);
    
        const float res = VecMag(sut);

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = 1.f;
        const Tuple sut = Vector(0.f, 1.f, 0.f);
    
        const float res = VecMag(sut);

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = 1.f;
        const Tuple sut = Vector(0.f, 0.f, 1.f);
    
        const float res = VecMag(sut);

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = std::sqrtf(14.f);
        const Tuple sut = Vector(1.f, 2.f, 3.f);
    
        const float res = VecMag(sut);

        EXPECT_FLOAT_EQ(exp, res);
    }

    {
        const float exp = std::sqrtf(14.f);
        const Tuple sut = Vector(-1.f, -2.f, -3.f);
    
        const float res = VecMag(sut);

        EXPECT_FLOAT_EQ(exp, res);
    }
}

TEST(TupleTest, Normalize)
{
    {
        const float expX = 1.f;
        const float expY = 0.f;
        const float expZ = 0.f;
        const float expW = 0.f;
        const Tuple a = Vector(4.f, 0.f, 0.f);
    
        const Tuple sut = Normalize(a);

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    {
        const float expX = 1.f / std::sqrtf(14.f);
        const float expY = 2.f / std::sqrtf(14.f);
        const float expZ = 3.f / std::sqrtf(14.f);
        const float expW = 0.f;
        const Tuple a = Vector(1.f, 2.f, 3.f);
    
        const Tuple sut = Normalize(a);

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }

    {
        const float exp = 1.f;
        const Tuple sut = Vector(1.f, 2.f, 3.f);
        const Tuple norm = Normalize(sut);
        const float res = VecMag(norm);

        EXPECT_FLOAT_EQ(exp, res);
    }
}

TEST(TupleTest, DotProduct)
{
    const float exp = 20.f;
    const Tuple a = Vector(1.f, 2.f, 3.f);
    const Tuple b = Vector(2.f, 3.f, 4.f);

    const float sut = Dot(a, b);

    EXPECT_FLOAT_EQ(exp, sut);
}

TEST(TupleTest, CrossProduct)
{
    // a x b
    {
        const float expX = -1.f;
        const float expY = 2.f;
        const float expZ = -1.f;
        const float expW = 0.f;
        const Tuple a = Vector(1.f, 2.f, 3.f);
        const Tuple b = Vector(2.f, 3.f, 4.f);

        const Tuple sut = Cross(a, b);

        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }
    
    // b x a
    {
        const float expX = 1.f;
        const float expY = -2.f;
        const float expZ = 1.f;
        const float expW = 0.f;
        const Tuple a = Vector(1.f, 2.f, 3.f);
        const Tuple b = Vector(2.f, 3.f, 4.f);
    
        const Tuple sut = Cross(b, a);
    
        EXPECT_FLOAT_EQ(expX, sut.m_x);
        EXPECT_FLOAT_EQ(expY, sut.m_y);
        EXPECT_FLOAT_EQ(expZ, sut.m_z);
        EXPECT_FLOAT_EQ(expW, sut.m_w);
    }
}