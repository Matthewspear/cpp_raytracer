#include <docopt/docopt.h>
#include <spdlog/spdlog.h>

#include <functional>
#include <iostream>

#include "image_writer.h"

#include "utility.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

color ray_color(const ray &r, const hittable &world) {
  hit_record rec;
  if (world.hit(r, 0, infinity, rec)) { return 0.5 * (rec.normal + color(1, 1, 1)); }
  vec3 unit_direction = unit_vector(r.direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
  const auto aspect_ratio = 16.0 / 9.0;
  const int image_width = 384 * 2;
  const int image_height = static_cast<int>(image_width / aspect_ratio);
  const int sample_per_pixel = 100;

  const int channel_num = 3;
  image_writer img_writer(image_width, image_height, channel_num, jpg);

  camera cam;
  hittable_list world;
  world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {

      color pixel_color(0, 0, 0);

      for (int s = 0; s < sample_per_pixel; ++s) {
        auto u = (i + random_double()) / (image_width - 1);
        auto v = (j + random_double()) / (image_height - 1);
        ray r = cam.get_ray(u, v);
        pixel_color += ray_color(r, world);
      }
      pixel_color /= sample_per_pixel;

      img_writer.pixel_value(image_height - j - 1, i, pixel_color);
    }
  }

  auto result = img_writer.write("image.jpg");
  std::cerr << '\n' << (result == 1 ? "Success!" : "Failed to write file :(") << '\n';
}
