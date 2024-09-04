#include "canvas.hpp"
#include "tuple.hpp"

Canvas::Canvas(int width, int height) :
    m_width{width}, m_height{height}, m_canvas(width, std::vector<Tuple>(height, Tuple()))
{
}

Canvas::~Canvas()
{
}