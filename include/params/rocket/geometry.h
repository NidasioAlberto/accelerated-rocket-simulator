#pragma once

struct Geometry {
  // Caliber (fuselage diameter) (m)
  float caliber;

  // Position of the rocket's upper pin from the nosecone base (m)
  float upper_pin;

  // Inertia when the motor is empty (Kg*m^2)
  float inertia_dry[3];

  // Inertia when the motor is full (Kg*m^2)
  float inertia_wet[3];

  // Center of mass position from nosecone base when the motor is empty (m)
  float xcg_dry;

  // Center of mass position from nosecone base when the motor is full (m)
  float xcg_wet;

  // Structural mass (Kg)
  float structural_mass;
};
