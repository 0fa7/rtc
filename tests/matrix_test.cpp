#include "../matrix.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(MatrixTest, Constructor4x4) {
  const int exSz = 4;
  std::vector<float> expRow(exSz, 0.f);

  Matrix<exSz> sut;

  EXPECT_EQ(exSz, sut.m_mat.size());
  EXPECT_EQ(exSz, sut.m_mat[0].size());

  int i = 0;

  for (; i < exSz; i++) {
    EXPECT_THAT(sut.m_mat[i], ::testing::ElementsAreArray(expRow));
  }

  EXPECT_EQ(exSz, i);
}

TEST(MatrixTest, Constructor4x4WithParams) {
  const int exSz = 4;
  std::vector<float> expRow0({1.f, 2.f, 3.f, 4.f});
  std::vector<float> expRow1({5.5f, 6.5f, 7.5f, 8.5f});
  std::vector<float> expRow2({9.f, 10.f, 11.f, 12.f});
  std::vector<float> expRow3({13.5f, 14.5f, 15.5f, 16.5f});

  Matrix<exSz> sut({expRow0, expRow1, expRow2, expRow3});

  EXPECT_THAT(sut.m_mat[0], ::testing::ElementsAreArray(expRow0));
  EXPECT_THAT(sut.m_mat[1], ::testing::ElementsAreArray(expRow1));
  EXPECT_THAT(sut.m_mat[2], ::testing::ElementsAreArray(expRow2));
  EXPECT_THAT(sut.m_mat[3], ::testing::ElementsAreArray(expRow3));
}

TEST(MatrixTest, Constructor2x2WithParams) {
  const int exSz = 2;
  std::vector<float> expRow0({-3.f, 5.f});
  std::vector<float> expRow1({1.f, -2.f});

  Matrix<exSz> sut({expRow0, expRow1});

  EXPECT_THAT(sut.m_mat[0], ::testing::ElementsAreArray(expRow0));
  EXPECT_THAT(sut.m_mat[1], ::testing::ElementsAreArray(expRow1));
}

TEST(MatrixTest, Constructor3x3WithParams) {
  const int exSz = 4;
  std::vector<float> expRow0({-3.f, 5.f, 0.f});
  std::vector<float> expRow1({1.f, -2.f, -7.f});
  std::vector<float> expRow2({0.f, 1.f, 1.f});

  Matrix<exSz> sut({expRow0, expRow1, expRow2});

  EXPECT_THAT(sut.m_mat[0], ::testing::ElementsAreArray(expRow0));
  EXPECT_THAT(sut.m_mat[1], ::testing::ElementsAreArray(expRow1));
  EXPECT_THAT(sut.m_mat[2], ::testing::ElementsAreArray(expRow2));
}

TEST(MatrixTest, OperatorEqualsTrue) {
  const int exSz = 4;
  std::vector<float> expRow0({1.f, 2.f, 3.f, 4.f});
  std::vector<float> expRow1({5.f, 6.f, 7.f, 8.f});
  std::vector<float> expRow2({9.f, 8.f, 7.f, 6.f});
  std::vector<float> expRow3({5.f, 4.f, 3.f, 2.f});

  Matrix<exSz> sutA({expRow0, expRow1, expRow2, expRow3});
  Matrix<exSz> sutB({expRow0, expRow1, expRow2, expRow3});

  EXPECT_TRUE(sutA == sutB);
}

TEST(MatrixTest, OperatorEqualsFalse) {
  const int exSz = 4;
  std::vector<float> expARow0({1.f, 2.f, 3.f, 4.f});
  std::vector<float> expARow1({5.f, 6.f, 7.f, 8.f});
  std::vector<float> expARow2({9.f, 8.f, 7.f, 6.f});
  std::vector<float> expARow3({5.f, 4.f, 3.f, 2.f});

  std::vector<float> expBRow0({2.f, 3.f, 4.f, 5.f});
  std::vector<float> expBRow1({6.f, 7.f, 8.f, 9.f});
  std::vector<float> expBRow2({8.f, 7.f, 6.f, 5.f});
  std::vector<float> expBRow3({4.f, 3.f, 2.f, 1.f});

  Matrix<exSz> sutA({expARow0, expARow1, expARow2, expARow3});
  Matrix<exSz> sutB({expBRow0, expBRow1, expBRow2, expBRow3});

  EXPECT_FALSE(sutA == sutB);
}

TEST(MatrixTest, OperatorMultiply) {
  std::vector<float> expRow0({20.f, 22.f, 50.f, 48.f});
  std::vector<float> expRow1({44.f, 54.f, 114.f, 108.f});
  std::vector<float> expRow2({40.f, 58.f, 110.f, 102.f});
  std::vector<float> expRow3({16.f, 26.f, 46.f, 42.f});

  Matrix<4> a({{1.f, 2.f,3.f, 4.f}, {5.f, 6.f, 7.f, 8.f}, {9.f, 8.f, 7.f, 6.f}, {5.f, 4.f , 3.f, 2.f}});
  Matrix<4> b({{-2.f, 1.f, 2.f, 3.f}, {3.f, 2.f, 1.f, -1.f}, {4.f, 3.f, 6.f, 5.f}, {1.f, 2.f, 7.f, 8.f}});

  const auto sut = a * b;

  EXPECT_THAT(sut.m_mat[0], ::testing::ElementsAreArray(expRow0));
  EXPECT_THAT(sut.m_mat[1], ::testing::ElementsAreArray(expRow1));
  EXPECT_THAT(sut.m_mat[2], ::testing::ElementsAreArray(expRow2));
  EXPECT_THAT(sut.m_mat[3], ::testing::ElementsAreArray(expRow3));
}