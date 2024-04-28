# Memory Access Pattern Analysis and Virtual Memory Simulation
*This repository stores work done by Hongyu Chen and Ming Gong in CSC369 Operating Systems.*

## Introduction
This repository contains the code and instructions for investigating memory access patterns, simulating page tables operation, and implementing various page replacement algorithms. 

## Part 1: Memory Reference Traces
The directory `/u/csc369h/summer/pub/a3` on the `teach.cs` machines contains four different programs:

1. `simpleloop.c`: Loops over an array allocated in the heap.
2. `repeatloop.c`: Loops over a heap-allocated array multiple times.
3. `matmul.c`: Naive matrix multiplication with customizable element size.
4. `blocked.c`: Memory-aware matrix multiplication with potentially better hit rate under certain page replacement algorithms.

Valgrind, with a custom shell script `run.sh`, can be used to print memory reference traces. Special markers in the programs separate relevant memory access patterns. The resulting traces are stored in `/u/csc369h/summer/pub/a3/traces/`. Additionally, the `fastslim.py` program reduces trace size, focusing on page accesses.

## Part 2: Virtual to Physical Translation
This section involves implementing virtual-to-physical address translation and demand paging using a three-level page table. It includes four page replacement algorithms: FIFO, Clock, exact LRU, and MRU.

**Requirements:**
- Readings about memory, especially paging.
- Setup instructions for accessing starter code.

**Tasks:**
1. **Address Translation and Paging:** Implement virtual-to-physical address translation and demand paging.
2. **Page Replacement Algorithms:** Implement FIFO, Clock, exact LRU, and MRU algorithms.
3. **Testing:** Run provided traces and analyze results.

## Important Notes
- Algorithms must be implemented with efficiency in mind.
- Each trace file must follow specific naming and content requirements.
- Simulators and algorithms should adhere to provided output formats.

For detailed instructions and code, refer to the respective directories and files.
