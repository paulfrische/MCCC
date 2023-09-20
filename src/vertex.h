#ifndef VERTEX_H
#define VERTEX_H

#include "base/base.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vertex;

#define vert(X, Y, Z)                                                                                                  \
    (Vertex) { X, Y, Z }

#endif // !VERTEX_H
