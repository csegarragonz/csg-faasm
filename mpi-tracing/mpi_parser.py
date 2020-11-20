#!/usr/bin/python3
from subprocess import run

AKYPUERA_BUILD_DIR = "/usr/local/faasm/openmpi/akypuera/build"


def _do_trace_conversion(data_dir="./mpi-profile-data"):
    cmd = ["{}/aky_converter", "{}/rastro-*.rst"]

    run(" ".join(cmd), shell=True, check=True)


# Most inefficient parser ever
lines = []
mpi_calls = {}
with open("data/mpi_trace.log") as fh:
    while True:
        line_orig = fh.readline()
        line = line_orig.strip().split(" ")
        for s in line:
            if s.startswith("MPI_"):
                if s in mpi_calls:
                    mpi_calls[s] += 1
                else:
                    mpi_calls[s] = 1
        if not line_orig:
            break

for k in sorted(mpi_calls, key=mpi_calls.get, reverse=True):
    print(k, mpi_calls[k])
