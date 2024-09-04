#pragma once

#include <vector>

class Tuple;

class Canvas
{
public:
    Canvas(int width, int height);
    ~Canvas();

    int m_width;
    int m_height;

    std::vector<std::vector<Tuple>> m_canvas;
private:
    Canvas();
};