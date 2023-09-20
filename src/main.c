#include "base/base.h"
#include "base/filesystem.h"
#include "base/logging.h"
#include "base/memory.h"
#include "base/string.h"
#include "window.h"

#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    GLFWwindow* window = init_window();

    while (!glfwWindowShouldClose(window)) {

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    destroy_window();
    return EXIT_SUCCESS;
}
