#pragma once

#include <string>
#include <vector>

#include "aero_coeffs.h"
#include "geometry.h"
#include "parachute.h"

struct Rocket {
  std::string name;
  Geometry geometry;
  AeroCoeffsArray aero_coeffs;
  std::vector<ParachuteStage> parachute_stages;
};
