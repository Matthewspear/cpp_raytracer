//
//  hittable.h
//  cpp_raytracer
//
//  Created by Matthew Spear on 13/06/2020.
//

#pragma once

#include "ray.h"

struct hit_record {
  point3 p;
  vec3 normal;
  double t;
  bool front_face;

  inline void set_face_normal(const ray &r, const vec3 &outward_normal) {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class hittable {
public:
  virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;
  virtual ~hittable(){};
};
