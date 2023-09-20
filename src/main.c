#include "base/base.h"
#include "base/filesystem.h"
#include "base/logging.h"
#include "base/memory.h"
#include "base/string.h"
#include "shader.h"
#include "vertex.h"
#include "window.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Arena* arena = ArenaInit();
    GLFWwindow* window = init_window();

    Vertex vertices[] = { vert(-0.5f, -0.5f, 0.0f), vert(0.5f, -0.5f, 0.0f), vert(0.0f, 0.5f, 0.0f) };

    u32 VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    u32 VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    Shader shader = create_shader("./res/vertex.glsl", "./res/fragment.glsl");
    use_shader(shader);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    destroy_window();
    arena_free(arena);
    return EXIT_SUCCESS;
}
