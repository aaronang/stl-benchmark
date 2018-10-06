module STL

Vertex = Tuple{Float32, Float32, Float32}
Normal = Vertex

struct Triangle
    normal::Normal
    v1::Vertex
    v2::Vertex
    v3::Vertex
end

function parse(path::AbstractString)
    triangles = Array{Triangle, 1}()

    open(path) do stl
        skip(stl, 80)  # skip header

        trianglecount = read(stl, UInt32)

        for _ in 1:trianglecount
            normal = read(stl, Float32), read(stl, Float32), read(stl, Float32)
            v1 = read(stl, Float32), read(stl, Float32), read(stl, Float32)
            v2 = read(stl, Float32), read(stl, Float32), read(stl, Float32)
            v3 = read(stl, Float32), read(stl, Float32), read(stl, Float32)
            push!(triangles, Triangle(normal, v1, v2, v3))

            skip(stl, 2)  # skip attribute byte count
        end

        @assert eof(stl)
    end

    triangles
end

export parse

end # module
