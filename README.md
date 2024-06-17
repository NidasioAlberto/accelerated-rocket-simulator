# Accelerated Rocket Simulator

This project aims to accelerate Skyward's rocket simulator with GPUs and FPGAs, and to answer these questions:
- How difficult is it to accelerate the simulator?
- Can the accelerated implementation be integrated into the original simulator used by the Skyward team?

## Skyward's Simulator

> Skyward's rocket simulator is available in the [**MSA Toolkit**](https://git.skywarder.eu/afd/msa/msa-toolkit) repository on Skyward's GitLab server, and a documentation report is available [here](https://git.skywarder.eu/afd/msa/msa-toolkit/-/blob/master/documentation.pdf).

The goal of the simulator is to reproduce, as closely to reality as possible, a rocket launch such that different design decisions can be evaluated during the project's early phases (e.g. knowing the weight and geometry of the rocket, an optimal size for the fins can be found while respecting stability constraints).

The rocket model is implemented with different ODEs (Ordinary Differential Equations):
- The **ascending fase** (from liftoff to apogee) is modeled with the `ascent` ODE, which takes into account the rocket's engine thrust, the fuselage aerodynamics and wind contributions;
- The **descending phase** can follow different models, depending on which parachute (if any) is used, and lasts until the rocket reaches the ground:
  - If a **ballistic flight** needs to be simulated (i.e. no parachute is ejected), the `ascent` ODE continues to be integrated
  - For **normal parachutes** either a 3DoF or a 6DoF model can be selected with different drag coefficents. Multiple parachutes can be used at different altitudes to model dual deployment setups (i.e. a small parachute, called *drogue*, is first opened to keep the velocity under control, and then a bigger one is deployed closer to the ground to achieve a soft landing)
  - For the **parafoil** (i.e. an airfoil that allows it's payload to glide through the air toward a target) a different custom model is used. Although already implemented, the current model does not properly model the behaviour of the parafoil. This is because the system has not yet been fully characterized and is still under testing. For this reason the model parameters, as well as the equations, could change anytime

![](images/simulator_diagram.svg)

The simulator is originally developed in MatLab and has three main components:
- The single simulation integrates the rocket model's ODEs from an initial state, where the rocket starts from the launchpad, until landing
- A stochastic engine randomizes some of the parameters and runs $N$ simulations
- The results of the simulations are analyzed and results are visualized on many different plots.

Use case example can be to compare the launch rail elevation with the apogee altitude, or how different wind conditions affect the landing position, or the rocket stability when leaving the launch rail.

## Model challenges

> TODO: Talk about the aerodynamic coefficients

> TODO: Talk abount analysis and results reduction

## How we intend to approach the project

- Create one kernel for each ODE. They are: `ascent`, `descent3DoF`, `descent6DoF`, `parafoil`
- Understand how the parameters randomization for the stochastic simulation can be implemented efficiently

- Create kernels for accelerating the stochastic simulations of the following models:
  - Ascent model
  - Descent 3DoF model
  - Descent 6DoF model
  - Parafoil model
- Create kernels to reduce and present the data produced from the stochastic simulations (?)
