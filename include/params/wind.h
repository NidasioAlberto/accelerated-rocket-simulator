#pragma once

// Model of constant wind
struct Wind {
  // Wind azimuth from north (deg)
  float azimuth;

  // Wind elevation (deg)
  float elevation;

  // Wind magnitude (m/s)
  float magnitude;
};
