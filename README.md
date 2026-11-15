# Fuze Cell Simulation using OpenFOAM

This repository contains the OpenFOAM case setups and a modified solver used to study the fluid behaviour inside a **fuze cell** under 
(a) constant gravity and 
(b) time-varying gravity experienced during projectile motion.

The work uses the Volume-of-Fluid (VOF) based **`interFoam`** solver for two-phase, incompressible, isothermal flow, along with a custom-modified version of it that supports a varying gravitational acceleration **g**.

---

## Repository Structure

```
.
├── fixed_rotating/                  # Baseline case: constant g, standard interFoam
├── myInterFoam-modified_solver/     # Modified interFoam solver source code (varying g)
└── projectile_motion/               # Case setup for varying g using the modified solver
```

### 1. `fixed_rotating/`
Baseline simulation of the fuze cell with a **constant gravitational acceleration (g)** using the standard **`interFoam`** solver.
This case serves as the reference against which the varying-g results are compared.

### 2. `myInterFoam-modified_solver/`
Source code of the **modified `interFoam` solver**. The modification allows the gravitational acceleration to **vary during the simulation** instead of being a fixed constant, so that the effective body force acting on the fluid can follow the projectile's motion.

Main files typically include:
- `myInterFoam.C` – main solver file
- `createFields.H` – field and variable definitions
- `updateGravity.H` – varying g is calculated and updated
- `UEqn.H`, `alphaEqn.H`, `pEqn.H` – momentum, phase-fraction and pressure equations
- `Make/files`, `Make/options` – compilation configuration

### 3. `projectile_motion/`
Complete case setup (`0/`, `constant/`, `system/`) for the fuze cell under **varying g**, run with the modified solver from `myInterFoam-modified_solver`. It represents the loading experienced by the fuze cell during projectile motion.

---

## Requirements

- Linux (or WSL on Windows)
- OpenFOAM (specify version, e.g. OpenFOAM-v2012 / OpenFOAM-9)
- A working OpenFOAM environment sourced in the terminal

---

## Usage

### A. Constant g case (standard interFoam)

```bash
cd fixed_rotating
blockMesh            # to setup the mesh
topoSet              # to define the porous regions
setFields            # initialise the phase fraction 
interFoam            # run the solver
```

### B. Varying g case (modified solver)

**Step 1 – Compile the modified solver**

```bash
cd myInterFoam-modified_solver
wclean
wmake
```

**Step 2 – Run the projectile motion case**

```bash
cd ../projectile_motion
blockMesh
topoSet
setFields
myInterFoam          # name of the compiled executable (check Make/files)
```

**Step 3 – Post-processing**

```bash
paraFoam             # or: touch case.foam && open in ParaView
```

---

## Results & Comparison

The two setups allow comparison of:
- Interface/free-surface shape and phase distribution inside the fuze cell
- Pressure and velocity fields
- Effect of varying g versus constant g on fluid motion

---

## Notes

- Make sure the modified solver is compiled **before** running the `projectile_motion` case.
- The solver executable name must match the entry in `Make/files`.
- The `application` entry in `system/controlDict` of `projectile_motion` must be set to the modified solver name.

---

