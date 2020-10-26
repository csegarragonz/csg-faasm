## [Ray 1.0 Architecture](https://docs.google.com/document/d/1lAy0Owi-vPz2jEqBSaHNQcy2IBSDEHyXNOQZlGuj93c/preview#heading=h.iyrm5j2gcdoq)

### Introduction
+ Ray aims to provide a universal API for distributed computing.
  + Provide simple but general programming abstractions.
  + Enable the development of apps like: coarse-grained elastic workloads (serverless), machine learning training, online serving, data processing, ..
+ Main goal on API simplicity, generality, performance, and reliability
  + Performance: built on top of gRPC (like Faasm)
  + Reliability: ensure correctness during failures and distributed ref.counting to ensure memory safety.

### Architecture Overview
+ IMO nothing sounds super novel.
+ [Distributed Reference Counting](https://docs.google.com/document/d/1S7rsDwFk3udIFeVUPC0_7F25lp5JWKXWrFVO3VimCEA/edit)

### A Note on Multi-Tenancy
+ It's still a [WIP](https://github.com/ray-project/ray/pull/10573)
+ Their notion of multi-tenancy is supporting different enviroment variables for workers.
