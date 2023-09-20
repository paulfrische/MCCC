#ifndef SHADER_H
#define SHADER_H

#include "base/base.h"
#include "base/memory.h"


typedef struct {
    u32 id;
} Shader;

Shader create_shader(const char* vertex, const char* fragment);
void use_shader(Shader s);

#endif // !SHADER_H
