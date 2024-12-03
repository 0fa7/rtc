#pragma once

#include <vector>

class Tuple;

class Canvas {
public:
  Canvas(int width, int height);
  ~Canvas();

  void WritePixel(const Tuple &color, int r, int c);
  const Tuple &PixelAt(int r, int c);
  void FlipY();

  int m_width;
  int m_height;
  std::vector<std::vector<Tuple>> m_canvas;

private:
  Canvas();
};