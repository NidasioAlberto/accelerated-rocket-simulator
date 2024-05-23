#pragma once

#include <string>
#include <vector>

struct EngineData;

// Model for COTS solid motors
struct Engine {
  // Engine name
  std::string name;

  // Producer
  std::string producer;

  // Total impulse (N*s)
  float total_impulse;

  // Propellant initial mass (Kg)
  float propellant_mass;

  // Engine length (m)
  float length;

  // Engine diameter (m)
  float diameter;

  // Engine structural mass, i.e. the case mass (Kg)
  float structural_mass;

  // Engine profile
  std::vector<EngineData> profile;
};

struct COTSSolidData {
  // Data point timestamp (s)
  float time;

  // Thrust (N)
  float thrust;

  // Propellant mass (Kg)
  float mass;
};
