#include "../canvas.hpp"
#include "../tuple.hpp"
#include "gmock/gmock.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CanvasTest, Constructor) {
  // with params
  {
    const int expWidth = 10;
    const int expHeight = 20;
    std::vector<Tuple> expRow(expHeight, Tuple());
    const Canvas sut{expWidth, expHeight};

    EXPECT_EQ(expWidth, sut.m_width);
    EXPECT_EQ(expHeight, sut.m_height);

    int i = 0;

    for (; i < expWidth; i++) {
      EXPECT_THAT(sut.m_canvas[i], ::testing::ElementsAreArray(expRow));
    }

    EXPECT_EQ(expWidth, i);
  }
}

TEST(CanvasTest, WritePixel) {
  const float expX = 1.f;
  const float expY = 0.f;
  const float expZ = 0.f;
  const float expW = 0.f;
  const Tuple expColor = Color(expX, expY, expZ);
  const int expHeight = 20;
  Canvas sut{10, 20};

  sut.WritePixel(expColor, 2, 3);

  EXPECT_FLOAT_EQ(expX, sut.m_canvas[2][3].m_x);
  EXPECT_FLOAT_EQ(expY, sut.m_canvas[2][3].m_y);
  EXPECT_FLOAT_EQ(expZ, sut.m_canvas[2][3].m_z);
  EXPECT_FLOAT_EQ(expW, sut.m_canvas[2][3].m_w);
}

TEST(CanvasTest, PixelAt) {
  const float expX = 1.f;
  const float expY = 0.f;
  const float expZ = 0.f;
  const float expW = 0.f;
  const Tuple expColor = Color(expX, expY, expZ);
  const int expHeight = 20;
  Canvas sut{10, 20};

  sut.WritePixel(expColor, 2, 3);

  EXPECT_FLOAT_EQ(expX, sut.PixelAt(2, 3).m_x);
  EXPECT_FLOAT_EQ(expY, sut.PixelAt(2, 3).m_y);
  EXPECT_FLOAT_EQ(expZ, sut.PixelAt(2, 3).m_z);
  EXPECT_FLOAT_EQ(expW, sut.PixelAt(2, 3).m_w);
}

TEST(CanvasTest, FlipY) {
  const float expX = 1.f;
  const float expY = 0.f;
  const float expZ = 0.f;
  const float expW = 0.f;
  const Tuple expColor = Color(expX, expY, expZ);
  const int expHeight = 20;
  Canvas sut{10, 20};

  sut.WritePixel(expColor, 2, 3);
  sut.FlipY();

  EXPECT_FLOAT_EQ(expX, sut.PixelAt(7, 3).m_x);
  EXPECT_FLOAT_EQ(expY, sut.PixelAt(7, 3).m_y);
  EXPECT_FLOAT_EQ(expZ, sut.PixelAt(7, 3).m_z);
  EXPECT_FLOAT_EQ(expW, sut.PixelAt(7, 3).m_w);
}