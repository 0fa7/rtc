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