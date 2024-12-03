#include "ppm_writer.hpp"
#include "canvas.hpp"
#include "tuple.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>

PpmWriter::PpmWriter() {}

PpmWriter::~PpmWriter() {}

void PpmWriter::Write(const Canvas &canvas, const std::string &filePath) {
  std::ofstream outFile(filePath);

  if (outFile.bad()) {
    return;
  }

  outFile << "P3\n";
  outFile << canvas.m_width << " " << canvas.m_height << "\n";
  outFile << "255\n";

  for (int r = 0; r < canvas.m_height; r++) {
    for (int c = 0; c < canvas.m_width; c++) {
      float rf = std::clamp<float>(canvas.m_canvas[r][c].m_x, 0.f, 1.f);
      float gf = std::clamp<float>(canvas.m_canvas[r][c].m_y, 0.f, 1.f);
      float bf = std::clamp<float>(canvas.m_canvas[r][c].m_z, 0.f, 1.f);

      int r = std::clamp<int>(std::ceil(rf * 255), 0, 255);
      int g = std::clamp<int>(std::ceil(gf * 255), 0, 255);
      int b = std::clamp<int>(std::ceil(bf * 255), 0, 255);

      outFile << r << " " << g << " " << b << " ";
    }

    outFile << "\n";
  }
}