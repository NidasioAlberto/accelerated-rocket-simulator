#pragma once

#include <optional>
#include <string>

#include "engine.h"
#include "launchpad.h"
#include "rocket/rocket.h"
#include "wind.h"

struct Mission {
  std::string name;

  // Rocket parameters (mass and geometry)
  Rocket rocket;

  // Engine parameters
  Engine engine;

  // Launchpad position and launch rail geometry
  Launchpad launchpad;

  // Wind model parameters
  std::optional<Wind> wind;
};
