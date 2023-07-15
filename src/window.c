#include "window.h"

GLFWwindow *window_handle = NULL;

void window_init(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
	window_handle = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT,
			"Pong", NULL, NULL);
	glfwMakeContextCurrent(window_handle);

	gladLoadGL((GLADloadfunc)glfwGetProcAddress);
}

bool window_is_open(void)
{
	return !glfwWindowShouldClose(window_handle);
}

float window_get_time(void)
{
	return glfwGetTime();
}

void window_clear(void)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void window_poll_and_swap(void)
{
	glfwPollEvents();
	glfwSwapBuffers(window_handle);
}

void window_terminate(void)
{
	glfwDestroyWindow(window_handle);
	glfwTerminate();
}
