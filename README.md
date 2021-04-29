# STL Benchmark

STL benchmark comparing C++ and Julia ⏱

For more information: [STL Benchmark Comparison: C++ vs. Julia](https://aaronang.github.io/2018/stl-benchmark-comparison-cpp-vs-julia/).

## Getting Started

```console
$ git clone --recurse-submodules git@github.com:aaronang/stl-benchmark.git
```

From the `cpp` directory:

```console
$ export CC=/usr/bin/clang
$ export CXX=/usr/bin/clang++
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make -j
$ ./stl_benchmark
2018-10-06 12:35:31
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
ParseStl       429234 ns     409210 ns       1729
```

From the `julia` directory:

```console
$ julia -O3
julia> ]
(v1.5) pkg> add BenchmarkTools
(v1.5) pkg> *press backspace*
julia> using BenchmarkTools
julia> include("stl.jl")
julia> @btime STL.parse("nist.stl")
  140.942 μs (14 allocations: 347.30 KiB)
```

From the `python` directory:

```console
$ python benchmark.py
25150.930999999986 μs
```

> Note: Python 3.7.0 is required.

## Results

| Language | Time       |
|----------|------------|
| C++      | 409.210 μs |
| Julia    | 211.641 μs |
| Python   | 25150.9 μs |

## Disclaimer

I am neither a C++ nor Julia expert. Please let me know if I biased the results
by implementing something obviously inefficiently.
