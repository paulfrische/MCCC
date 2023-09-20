#include "window.h"
#include "base/base.h"
#include "base/logging.h"
#include <GLFW/glfw3.h>

GLFWwindow* init_window()
{
    if (!glfwInit()) {
        CRITICAL("failed to initialize GLFW");
    } else {
        DEBUG("initialized GLFW");
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
    if (!window) {
        CRITICAL("failed to create GLFWwindow");
        glfwTerminate();
    }


    glfwMakeContextCurrent(window);
    return window;
}

void destroy_window() { glfwTerminate(); }
