#pragma once

#include <string>

class Canvas;

class PpmWriter {
public:
  static void Write(const Canvas &canvas, const std::string &filePath);
  static void WriteHeader(const Canvas &canvas, const std::string &filePath);
  static void WriteImageData(const Canvas &canvas, const std::string &filePath);

private:
  PpmWriter();
  ~PpmWriter();
};