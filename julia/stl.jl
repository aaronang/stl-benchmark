module STL

struct Vertex
    x::Float32
    y::Float32
    z::Float32
end

const Normal = Vertex

struct Triangle
    normal::Normal
    v1::Vertex
    v2::Vertex
    v3::Vertex
end

function parse(path::AbstractString)
    open(path) do stl
        skip(stl, 80)  # skip header

        trianglecount = read(stl, UInt32)
        triangles = Array{Triangle, 1}(undef, trianglecount)

        for i in 1:trianglecount
            normal = Normal(read(stl, Float32), read(stl, Float32), read(stl, Float32))
            v1 = Vertex(read(stl, Float32), read(stl, Float32), read(stl, Float32))
            v2 = Vertex(read(stl, Float32), read(stl, Float32), read(stl, Float32))
            v3 = Vertex(read(stl, Float32), read(stl, Float32), read(stl, Float32))
            triangles[i] = Triangle(normal, v1, v2, v3)

            skip(stl, 2)  # skip attribute byte count
        end

        @assert eof(stl)
        return triangles
    end
end

export parse

end # module
