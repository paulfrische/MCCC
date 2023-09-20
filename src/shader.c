#include <glad/gl.h>
#include <stddef.h>

#include "base/filesystem.h"
#include "base/logging.h"
#include "base/memory.h"
#include "base/string.h"
#include "shader.h"

void check_compile(u32 shader)
{
    i32 success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        CRITICAL("%s", infoLog);
    }
}

Shader create_shader(const char* vertex, const char* fragment)
{
    Arena* scratch = ArenaInit();
    const char* vertexSource = str_to_c_str(scratch, filesystem_read_file(scratch, str_from_c_str(scratch, vertex)));
    const char* fragmentSource
        = str_to_c_str(scratch, filesystem_read_file(scratch, str_from_c_str(scratch, fragment)));

    u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
    u32 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    check_compile(vertexShader);

    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    check_compile(fragmentShader);

    u32 program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    i32 success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        CRITICAL("%s", infoLog);
    }

    arena_free(scratch);

    Shader s = {
        .id = program,
    };
    return s;
}

void shader_set_bool(Shader s, const char* name, bool value)
{
    glUniform1i(glGetUniformLocation(s.id, name), (u32)value);
}

void shader_set_u32(Shader s, const char* name, u32 value) { glUniform1i(glGetUniformLocation(s.id, name), value); }

void shader_set_f32(Shader s, const char* name, f32 value) { glUniform1f(glGetUniformLocation(s.id, name), value); }

void use_shader(Shader s) { glUseProgram(s.id); }
