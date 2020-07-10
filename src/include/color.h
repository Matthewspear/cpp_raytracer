#pragma once

#include <iostream>

#include "vec3.h"
#include "utility.h"

void write_color(std::ostream &out, color pixel_color) {
  out << static_cast<int>(256 * std::clamp(pixel_color.x(), 0.0, 0.999)) << ' '
      << static_cast<int>(256 * std::clamp(pixel_color.y(), 0.0, 0.999)) << ' '
      << static_cast<int>(256 * std::clamp(pixel_color.z(), 0.0, 0.999)) << '\n';
}
