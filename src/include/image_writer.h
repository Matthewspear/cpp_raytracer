#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>

#include "color.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wold-style-cast"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#pragma GCC diagnostic pop

enum image_format { png, jpg, ppm };

class image_writer {
private:
  int _width;
  int _height;
  int _channels;
  image_format _format;
  std::vector<color> _pixel_data;

public:
  image_writer(int width, int height, int channels, image_format format)
    : _width(width), _height(height), _channels(channels), _format(format) {
    auto size = static_cast<unsigned long>(width * height);
    _pixel_data = std::vector<color>(size, color(0, 0, 0));
  }

  void pixel_value(int row, int col, const color &pixel_color) {
    auto index = static_cast<unsigned long>(row * _width + col);
    _pixel_data.at(index) = pixel_color;
  }

  int write(std::string filename) {

    int result = 0;
    int index = 0;
    auto size = static_cast<unsigned long>(_width * _height * _channels) * sizeof(char);
    char *data = new char[size];

    std::ofstream ppmfile;

    switch (_format) {
    case jpg:
    case png:
      for (const color &pixel : _pixel_data) {
        data[index++] = static_cast<char>(256 * std::clamp(pixel.x(), 0.0, 0.999));
        data[index++] = static_cast<char>(256 * std::clamp(pixel.y(), 0.0, 0.999));
        data[index++] = static_cast<char>(256 * std::clamp(pixel.z(), 0.0, 0.999));
      }
      if (_format == png) {
        result = stbi_write_png(filename.c_str(), _width, _height, _channels, data, _width * _channels);
      } else {
        result = stbi_write_jpg(filename.c_str(), _width, _height, _channels, data, 100);
      }
      break;
    case ppm:
      ppmfile.open(filename);
      ppmfile << "P3\n" << _width << ' ' << _height << '\n' << "255\n";
      for (const color &pixel : _pixel_data) { write_color(ppmfile, pixel); }
      ppmfile.close();
      result = 1;
      break;
    }

    delete[] data;
    return result;
  }
};
