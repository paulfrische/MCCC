#include "window.h"
#include "GLFW/glfw3.h"
#include "base/base.h"
#include "base/logging.h"

GLFWwindow* init_window()
{
    if (!glfwInit()) {
        CRITICAL("failed to initialize GLFW");
    } else {
        DEBUG("initialized GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
    if (!window) {
        CRITICAL("failed to create GLFWwindow");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    u32 version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        CRITICAL("failed to init OpenGL context");
    } else {
        INFO("loaded OpenGL version %d.%d", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
    }
    return window;
}

void destroy_window()
{
    glfwTerminate();
    DEBUG("glfwTerminate");
}
