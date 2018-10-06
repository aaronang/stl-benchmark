module Benchmark

using BenchmarkTools

include("stl.jl")

import .STL

@btime STL.parse(joinpath(@__DIR__, "nist.stl"))

end # module
