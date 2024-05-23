#pragma once

#include <ctime>
#include <string>

struct Launchpad {
  // Launchpad identifier name
  std::string name;

  // Date and time of the launch
  std::tm datetime;

  // Launchpad coordinates (m, deg, deg)
  float altitude;
  float latitude;
  float longitude;

  // Launch rail route length (m)
  float route_length;

  // Launch rail elevation angle (deg)
  float elevation;

  // Launch rail azimuth angle (deg)
  float azimuth;
};
