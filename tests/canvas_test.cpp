#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../canvas.hpp"
#include "../tuple.hpp"

TEST(CanvasTest, Constructor)
{
    // with params
    {
        const int expWidth = 10;
        const int expHeight = 20;
        std::vector<Tuple> expRow(expHeight, Tuple());
        const Canvas sut{expWidth, expHeight};

        EXPECT_EQ(expWidth, sut.m_width);
        EXPECT_EQ(expHeight, sut.m_height);

        int i = 0;

        for(; i < expWidth; i++)
        {
            EXPECT_THAT(sut.m_canvas[i], ::testing::ElementsAreArray(expRow));
        }

        EXPECT_EQ(expWidth, i);
    }
}