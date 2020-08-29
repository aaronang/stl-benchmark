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
    open(path;lock=false) do stl
        skip(stl, 80)  # skip header
        trianglecount = read(stl, UInt32)
        ref = Ref{Triangle}()
        triangles = map(1:trianglecount) do i
            read!(stl, ref)
            skip(stl, 2)  # skip attribute byte count
            ref[]
        end
        @assert eof(stl)
        return triangles
    end
end

export parse

end # module
