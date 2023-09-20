#include "base/base.h"
#include "base/filesystem.h"
#include "base/logging.h"
#include "base/memory.h"
#include "base/string.h"

#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	if (!glfwInit()) {
		CRITICAL("failed to initialize GLFW");
		return EXIT_FAILURE;
	}
	
	DEBUG("initialized GLFW");

    return EXIT_SUCCESS;
}
