#pragma once

#include <vector>

template <int N> class Matrix {
public:
  Matrix()
      : m_mat(std::vector<std::vector<float>>(N, std::vector<float>(N, 0.f))),
        rows(N), cols(N) {}

  Matrix(const std::vector<std::vector<float>> &mat)
      : rows(N), cols(N), m_mat(mat) {}

  bool operator==(const Matrix &other) const {
    if (m_mat.size() != other.m_mat.size()) {
      return false;
    }

    for (int i = 0; i < m_mat.size(); i++) {
      if (m_mat[i] != other.m_mat[i]) {
        return false;
      }
    }

    return true;
  }

  Matrix operator*(const Matrix &b) const {
    Matrix<N> res;

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        res.m_mat[r][c] = 0.f;

        for (int run = 0; run < rows; run++) {
          res.m_mat[r][c] += m_mat[r][run] * b.m_mat[run][c];
        }
      }
    }

    return res;
  }

  std::vector<std::vector<float>> m_mat;
  int rows;
  int cols;
};