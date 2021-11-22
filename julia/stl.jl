module STL

export parse, parse_malloc

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

function parse(path)
    open(path; lock = false) do io
    	skip(io, 80) # skip header 
        triangle_count = read(io, UInt32)
    	triangles = Vector{Triangle}(undef, triangle_count) # preallocate memory for triangles 
    	dest = Base.unsafe_convert(Ptr{Triangle}, triangles) # destination pointer
    	unsafe_read(io, dest, sizeof(Triangle)) # copying first triangle
        for _ in 2:triangle_count
            skip(io, 2)
            dest += sizeof(Triangle) # moving to the next trianlge in dest
            unsafe_read(io, dest, sizeof(Triangle))
        end
        triangles
    end
end

function parse_malloc(path)
    open(path; lock = false) do io
        skip(io, 80)
        triangle_count = read(io, UInt32)
        triangles = convert(Ptr{Triangle}, Base.Libc.malloc(48triangle_count))
        dest = triangles
        unsafe_read(io, dest, sizeof(Triangle)) # copying first triangle
        for _ in 2:triangle_count
            skip(io, 2)
            dest += sizeof(Triangle) # moving to the next trianlge in dest
            unsafe_read(io, dest, sizeof(Triangle))
        end
        Base.unsafe_wrap(Array, triangles, triangle_count; own = true)
    end
end

end #module STL
