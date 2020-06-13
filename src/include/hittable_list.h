//
//  hittable_list.h
//  cpp_raytracer
//
//  Created by Matthew Spear on 13/06/2020.
//

#pragma once

#include "hittable.h"

#include <memory>
#include <vector>

class hittable_list : public hittable {

public:
  std::vector<shared_ptr<hittable>> objects;

public:
  hittable_list() {}
  hittable_list(shared_ptr<hittable> object) { add(object); }

  virtual bool hit(const ray &r, double tmin, double tmax, hit_record &rec) const;

  void clear() { objects.clear(); }
  void add(shared_ptr<hittable> object) { objects.push_back(object); }
};

bool hittable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {

  hit_record temp_rec;
  bool hit_anything = false;
  auto closest_so_far = t_max;

  for (const auto &object : objects) {
    if (object->hit(r, t_min, closest_so_far, temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }
  return hit_anything;
}
