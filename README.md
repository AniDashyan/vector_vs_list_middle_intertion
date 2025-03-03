Here's a structured README for the code provided that explains the context and rationale behind the performance tests, along with the reason why `std::vector` outperforms `std::list`.

---

# Middle Insertions Performance Comparison

This repository contains a C++ program that measures the time taken to perform 10,000 insertions in the middle of two data structures: `std::vector<int>` and `std::list<int>`. The program demonstrates the difference in performance between these two containers when inserting elements into the middle.

## Problem Description

The program inserts elements into the middle of a `std::vector` and a `std::list` and records the time taken for these operations. Additionally, it performs a similar test with a **pre-allocated** `std::vector` to highlight the impact of memory allocation on performance.

### Goals:
- Measure the time taken for **10,000 middle insertions** for:
  - `std::vector<int>`
  - `std::list<int>`
  - Pre-allocated `std::vector<int>`
  
- Compare the performance of these containers to understand why `std::vector` may outperform `std::list` in terms of insertion speed, even though `std::vector` requires shifting elements.

## Code Overview

### Key Functions:
- **`middle_insertions_vector()`**: Inserts elements into the middle of a `std::vector<int>`, requiring elements to be shifted each time.
- **`middle_insertions_list()`**: Inserts elements into the middle of a `std::list<int>`, which involves finding the middle of the list and inserting elements without shifting.
- **`middle_insertions_vector_preallocated()`**: Similar to `middle_insertions_vector()`, but the vector's memory is pre-allocated to avoid reallocations during insertion.

### Performance Results:
Each function measures the time (in milliseconds) taken for 10,000 insertions and prints the result. The execution times are printed in a formatted table.

## Why `std::vector` May Outperform `std::list`

### Memory Layout and Cache Efficiency:
- **`std::vector<int>`** stores elements **contiguously** in memory. This means that accessing elements is very fast because modern CPUs utilize **cache locality** effectively. When elements are shifted during an insertion, the operation is performed in a single, continuous block of memory, which is efficient.
  
- **`std::list<int>`**, on the other hand, stores elements **non-contiguously** (as nodes, each pointing to the next one). This scattered memory layout increases the time taken to traverse the list to find the middle insertion point. Additionally, each insertion requires the allocation of a new node in memory, which introduces overhead.

### Fewer Memory Allocations:
- In `std::vector`, memory is allocated in larger blocks. Even though inserting in the middle requires shifting elements, **allocations are less frequent**, and copying elements in a contiguous block is generally fast.
  
- In `std::list`, every insertion requires a new memory allocation for the node, and this can be expensive in terms of time. Additionally, pointer manipulations for node connections take more time compared to memory shifts in `std::vector`.

### Pre-allocated Vector:
- Pre-allocating memory for a `std::vector` (using `reserve()`) improves performance by eliminating the need for dynamic memory reallocation during the insertion process. This makes insertions faster than a standard `std::vector` that reallocates memory when needed.

## Performance Observations
1. **`std::vector` with element shifting** may outperform `std::list` due to the efficient use of CPU caches and fewer memory allocations.
2. **Pre-allocating a `std::vector`** further enhances performance by reducing the overhead of reallocating memory during insertions.
3. **`std::list`**, though avoiding element shifting, incurs a performance penalty due to scattered memory and the overhead of finding the middle and allocating new nodes.

### 2. Build & Run

#### Requirements
- **C++ compiler**: A modern C++ compiler that supports the C++11 standard or later (e.g., GCC, Clang, or MSVC).
- **CMake**: Version 3.10 or later.
- **Git**: To clone the repository (optional if you have the source code).

#### Steps

1. **Clone the Repository and Navigate to the Directory**:

    ```bash
    git clone https://github.com/AniDashyan/vector_vs_list_middle_insertion.git && cd vector_vs_list_middle_insertion
    ```

2. **Generate Build Files for Release Mode**:

    ```bash
    cmake  -S . -B build
    ```

3. **Build the Project**:

    ```bash
    cmake --build build --config Release
    ```

4. **Run the Program in Terminal**:

    ```bash
    ./build/main
    ```



The program will output the time taken to insert elements in the middle of each container.

## Example Output

```
Performance Results:
--------------------
Vector Insertion Time:        3.1408 ms
List Insertion Time:          88.3616 ms
Pre-allocated Vector Time:    1.6442 ms
```

## Conclusion

Despite the need to shift elements, `std::vector` can often outperform `std::list` due to its contiguous memory layout and better cache utilization. Pre-allocating memory for a `std::vector` can further improve performance by reducing the need for dynamic reallocations during insertion operations.

---
