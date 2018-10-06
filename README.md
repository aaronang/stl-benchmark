# STL Benchmark

STL benchmark comparing C++ and Julia ⏱

## Getting Started

```console
$ git clone --recurse-submodules git@github.com:aaronang/stl-benchmark.git
```

From the `cpp` directory:

```console
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make -j
$ ./stl_benchmark
2018-10-05 22:44:31
Running ./stl_benchmark
Run on (8 X 2300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 6291K (x1)
--------------------------------------------------
Benchmark           Time           CPU Iterations
--------------------------------------------------
ParseStl      1857063 ns    1830176 ns        374
```

From the `julia` directory:

```console
$ julia
julia> ]
(v1.0) pkg> activate .
(benchmark) pkg> ^C
julia> include("src/Benchmark.jl")
  815.896 μs (26 allocations: 769.47 KiB)
Main.Benchmark
```
