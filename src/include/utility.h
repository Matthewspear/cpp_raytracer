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

// using

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// utility functions

inline double deg_to_rad(double degrees) {
    return degrees * pi / 180.0;
}

// common headers

#include "ray.h"
#include "vec3.h"
