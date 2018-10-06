import struct

from dataclasses import dataclass
import timeit


@dataclass
class Vertex:
    x: float
    y: float
    z: float


@dataclass
class Triangle:
    normal: Vertex
    v1: Vertex
    v2: Vertex
    v3: Vertex


def parse(path: str):
    with open(path, 'rb') as stl:
        stl.seek(80)  # skip header
        trianglecount = struct.unpack('I', stl.read(4))[0]

        triangles = []
        for _ in range(trianglecount):
            fs = struct.unpack('f'*12, stl.read(48))
            normal = Vertex(fs[0], fs[1], fs[2])
            v1 = Vertex(fs[3], fs[4], fs[5])
            v2 = Vertex(fs[6], fs[7], fs[8])
            v3 = Vertex(fs[9], fs[10], fs[11])
            triangles.append(Triangle(normal, v1, v2, v3))
            stl.seek(2, 1)  # skip attribute byte count

        assert not stl.read()
        return triangles

def benchmark():
    parse('nist.stl')

time = min(timeit.Timer(benchmark).repeat(number=1, repeat=500)) * 1e6

print(str(time) + " μs")