#pragma once

#include <vector>

template<int N>
class Matrix
{
public:
  Matrix() :
    m_mat(std::vector<std::vector<float>>(N, std::vector<float>(N, 0.f)))
  { 
  }

  Matrix(const std::vector<std::vector<float>>& mat) :
    m_mat(mat)
  {
  }

  bool operator==(const Matrix& other) const
  {
    if(m_mat.size() != other.m_mat.size())
    {
      return false;
    }

    for(int i = 0; i < m_mat.size(); i++)
    {
      if(m_mat[i] != other.m_mat[i])
      {
        return false;
      }
    }

    return true;
  }

  std::vector<std::vector<float>> m_mat;
};