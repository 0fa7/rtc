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
    
        EXPECT_FLOAT_EQ(expX, sut1.m_x);
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