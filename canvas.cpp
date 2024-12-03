#include "canvas.hpp"
#include "tuple.hpp"
#include <algorithm>

Canvas::Canvas(int width, int height)
    : m_width{width}, m_height{height},
      m_canvas(width, std::vector<Tuple>(height, Tuple())) {}

Canvas::~Canvas() {}

void Canvas::WritePixel(const Tuple &color, int r, int c) {
  m_canvas[r][c] = color;
}

const Tuple &Canvas::PixelAt(int r, int c) { return m_canvas[r][c]; }

void Canvas::FlipY() { std::reverse(m_canvas.begin(), m_canvas.end()); }