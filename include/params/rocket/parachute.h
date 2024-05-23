#pragma once

#include <optional>
#include <string>

struct Parachute {
  std::string name;

  // Cross surface (m^2)
  float surface;

  // ;ass (Kg)
  float mass;

  // Drag coefficient
  float C_D;
};

struct ParachuteStage {
  Parachute parachute;

  // Altitude where this parachute is cut off during the flight (m)
  std::optional<float> cutoff_altitude;
};
