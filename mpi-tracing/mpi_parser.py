#!/usr/bin/python3

lines = []
mpi_calls = set([])
with open("mpi_trace.log") as fh:
    while True:
        line_orig = fh.readline()
        line = line_orig.strip().split(' ')
        # print(line)
        for s in line:
            if (s.startswith('MPI_')):
                mpi_calls.add(s)
        if not line_orig:
            break

for call in mpi_calls:
    print(call)
