#include <functional>
#include <iostream>

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>

int main() {

  const int image_width = 256;
  const int image_height = 256;

  const double b = 0.25;
  const double colour_multipler = 255.999;

  std::cout << "P3\n"
            << image_width << ' ' << image_height << '\n'
            << "255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {

      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);

      int ir = static_cast<int>(colour_multipler * r);
      int ig = static_cast<int>(colour_multipler * g);
      int ib = static_cast<int>(colour_multipler * b);

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
  std::cerr << "\nDone!\n";
}
