# New Scheduler for Faabric

## Execution Graph

### Graph Properties

+ Cyclic, directed, weighted graph.
+ Nodes:
+ Edges:
+ Weights:

### Some design choices

+ Introduce a notion of locality for memory sharing. This is, place nodes in a
"map" according to the memory they share, and introduce the concept of distance.

