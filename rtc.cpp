#include "canvas.hpp"
#include "ppm_writer.hpp"
#include "tuple.hpp"
#include <iostream>

int main() {
  std::cout << "Hello world!" << std::endl;
  Canvas c(5, 3);
  c.WritePixel(Color(1.5f, 0.f, 0.f), 0, 0);
  c.WritePixel(Color(0.f, .5f, 0.f), 1, 2);
  c.WritePixel(Color(-.5f, 0.f, 1.f), 2, 4);

  PpmWriter::Write(c, "test.ppm");
}