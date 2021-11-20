# STL Benchmark

STL benchmark comparing C++ and Julia ⏱

For more information: [STL Benchmark Comparison: C++ vs. Julia](https://aaronang.github.io/2018/stl-benchmark-comparison-cpp-vs-julia/).

## Getting Started

```console
git clone --recurse-submodules git@github.com:XInvisib1eX/stl-benchmark.git
```

From the `cpp` directory:

```console
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j
./stl_benchmark
```

Sample output

```console
Running ./stl_benchmark
Run on (12 X 4500 MHz CPU s)
CPU Caches:
  L1 Data 32K (x6)
  L1 Instruction 32K (x6)
  L2 Unified 256K (x6)
  L3 Unified 12288K (x1)
--------------------------------------------------
Benchmark           Time           CPU Iterations
--------------------------------------------------
ParseStl       237056 ns     236744 ns       2912
```

From the `julia` directory:

```console
$ julia -O3
julia> ]
(v1.6) pkg> add BenchmarkTools
julia> using BenchmarkTools
julia> include("stl.jl")
julia> using Main.STL
julia> @btime parse_to_stack("nist.stl")
  110.646 μs (14 allocations: 347.30 KiB)
```

From the `python` directory:

```console
$ python benchmark.py
13513.513993530069 μs μs
```

> Note: Python 3.7.0 is required.

## Results

| Language | Time       |
|----------|------------|
| C++      | 237.056 μs |
| Julia    | 110.646 μs |
| Python   | 13513.5 μs |
