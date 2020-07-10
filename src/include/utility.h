//
//  utility.h
//  cpp_raytracer
//
//  Created by Matthew Spear on 13/06/2020.
//

#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>

// using

using std::shared_ptr;
using std::make_shared;

using std::sqrt;

// constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// utility functions

inline double deg_to_rad(double degrees) { return degrees * pi / 180.0; }

inline double random_double() {
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);
  static std::mt19937 generator;
  return distribution(generator);
}

inline double random_double(double min, double max) {
  // Return a random real in [min,max)
  return min + (max - min) * random_double();
}

// Replaced with std::clamp
//  inline double clamp(double x, double min, double max) {
//      if (x < min) return min;
//      if (x > max) return max;
//      return max;
//  }

// common headers

#include "ray.h"
#include "vec3.h"
