## A Large-Scale Study of MPI Usage in Open-Source HPC Applications

### Summary
+ While advanced features of MPI exist ... a large proportion of MPI programs do not use these features.
+ The majority of MPI programs use only a small set of features from the standard.
+ C++ is the dominant language in MPI programs.
+ They use 110 unique MPI programs and perform a static code analysis.
+ These applications are obtained through a crawling mechanism considering:
  + Programs from USA HPC centers
  + Programs from EU HPC centers
  + Programs from Asian HPC centers
  + Crawling from Github
  + Crawling from Gitlab
+ C++ is used primarly and in combination with C.
+ The authors don't count _frequency_ of the MPI calls, only if they are being used or not.
+ From our pre-defined list of applications, I can see that they have also analyzed: LAMMPS, Gromacs, WRF, and horovod.
+ The process management feature is only rarely used in MPI programs (_Note to self: could this be used as a dynamic group management tool?_)
+ The majority of MPI programs surveyed only use a small set of features from the MPI standard. A considerable number of applciations use only point-to-point and collective communcation features.
+ `MPI_Allreduce` is the most used collective routine.
+ Applications use more non-blocking point-to-point calls than blocking calls.
+ C++ is the most significant programming language in MPI programs whereas C appears to be the least significant.
+ `OpenMP` is by far the most prevalent MPI+X solution used for multi-threading.

### Take Aways
+ They don't share their static analysis method.
+ However the method is a static analyzer, i.e. a Python-based parser.
+ They don't count the _total_ number of calls to a specific MPI routine, only whether an application makes use of it or not.
+ Found the [repo](https://github.com/LLNL/MPI-Usage)
