#ifndef VERTEX_H
#define VERTEX_H

#include <glad/gl.h>

#include "base/base.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 s;
    f32 t;
} Vertex;

#define vert(X, Y, Z, T, V)                                                                                            \
    (Vertex) { X, Y, Z, T, V }

#endif // !VERTEX_H
