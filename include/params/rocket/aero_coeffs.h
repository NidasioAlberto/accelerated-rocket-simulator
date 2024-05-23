#pragma once

#include <vector>

// This struct contains the values corresponding to each axis of the aerodynamic
// coefficient array.
struct AeroState {
  // Angles of attack
  float alpha;

  // Sideslip angles
  float beta;

  // Mach number
  float mach;

  // Altitudes (m)
  float altitude;

  // Airbrakes exposed lengths (m)
  float airbrakes_length;

  // Center of mass positions (m)
  float xcg_position;
};

struct AeroCoefficients {
  // Axial force
  float C_A;

  // Normal force
  float C_N;

  // Normal force derivative wrt angle of attack
  float C_Na;

  // Side force
  float C_Y;

  // Side force derivative wrt sideslip angle
  float C_Yb;

  // Rolling moment
  float C_l;

  // Rolling moment derivative wrt roll rate
  float C_lp;

  // Pitching moment
  float C_M;

  // Pitching force derivative wrt angle of attack
  float C_ma;

  // Pitching moment derivative wrt rate of change of angle of attack
  float C_Madot;

  // Pitching moment derivative wrt pitch rate
  float C_Mq;

  // Yawing moment
  float C_n;

  // Yawing moment derivative wrt sideslip angle
  float C_nb;

  // Yawing moment derivative wrt yaw rate
  float C_nr;

  // Yawing moment derivative wrt roll rate
  float C_np;
};

// The aerodynamic coefficients are stored in a 6-dimensional array.
//
// Dimensions:
// 1. Angle of attack (alpha)
// 2. Sideslip angle (beta)
// 3. Mach number
// 4. Altitude (msl)
// 5. Airbrakes exposed length
// 6. Center of mass position
struct AeroCoeffsArray {
  std::vector<AeroCoefficients> coeffs;
  std::vector<float> alphas;
  std::vector<float> betas;
  std::vector<float> machs;
  std::vector<float> altitudes;
  std::vector<float> airbrakes_lengths;
  std::vector<float> xcg_positions;
};
