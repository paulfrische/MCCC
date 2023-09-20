#ifndef SHADER_H
#define SHADER_H

#include "base/base.h"
#include "base/memory.h"


typedef struct {
    u32 id;
} Shader;

Shader create_shader(const char* vertex, const char* fragment);

void shader_set_bool(Shader s, const char* name, bool value);
void shader_set_u32(Shader s, const char* name, u32 value);
void shader_set_f32(Shader s, const char* name, f32 value);

void use_shader(Shader s);

#endif // !SHADER_H
