# Accelerated Rocket Simulator

This project aims to accelerate Skyward's rocket simulator with GPUs and FPGAs, and to answer these questions:
- How difficult is it to accelerate the simulator?
- Can the accelerated implementation be integrated into the original simulator used by the Skyward team?
- Is it better to use a GPU or an FPGA?
- Can it be implemented onboard the rocket?

## How Skyward's simulator works

> Skyward's rocket simulator is available in the [`MSA Toolkit` repository](https://git.skywarder.eu/afd/msa/msa-toolkit) on Skyward's GitLab server, and a documentation report is available [here](https://git.skywarder.eu/afd/msa/msa-toolkit/-/blob/master/documentation.pdf).

The simulator is originally developed in MatLab and has three main components:
- The single simulation integrates the rocket model's ODEs (Ordinary Differential Equations) from an initial state, where the rocket starts from the launchpad, until landing
- A stochastic simulation randomizes some of the parameters and runs $N$ simulations
- The results of the stochastic simulation are analyzed and visualized with plots. For example the launch rail elevation is compared to the apogee altitude, or how different wind conditions affect the landing position, or the rocket stability when leaving the launch rail

## How we intend to approach the project

### GPU section
- Create kernels for accelerating the stochastic simulations of the following models:
  - Ascent model
  - Descent 3DoF model
  - Descent 6DoF model
  - Parafoil model
- Create kernels to reduce and present the data produced from the stochastic simulations (?)

### FPGA section
- Create an FPGA implementation for accelerating single simulations of the following models:
  - Ascent model
  - Descent 3DoF model
  - Descent 6DoF model
  - Parafoil model

Or
- Create an FPGA implementation of the MPC algorithm that runs on-board during flight
