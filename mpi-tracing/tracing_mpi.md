# Tracing MPI

Small guide on how to profile MPI applications.

## Installation

We use the [Akypuera](https://github.com/schnorr/akypuera) library. This will
assume a standard MPI installation (tested with `ompi`).
```bash
git clone --recursive https://github.com/schnorr/akypuera.git
cd akypuera; mkdir build; cd build
cmake ..; make
```

## Usage

Below is an example to be run with vanilla LAMMPS:
```bash
# Run the actual script
LD_PRELOAD=~/akypuera/build/libaky.so mpirun -np 4 ./lmp -in ../examples/controller/in.controller.wall

# Transform the log files to a readable format
~/akypuera/build/aky_converter rastro-*.rst > mpi_trace.log

# Parse using an ugly python script
```
