#include "base/base.h"
#include "base/filesystem.h"
#include "base/logging.h"
#include "base/memory.h"
#include "base/string.h"
#include "window.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    GLFWwindow* window = init_window();

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    destroy_window();
    return EXIT_SUCCESS;
}
