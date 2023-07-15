#ifndef WINDOW_H_
#define WINDOW_H_

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdbool.h>

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

extern GLFWwindow *window_handle;

void window_init(void);
bool window_is_open(void);
float window_get_time(void);
void window_clear(void);
void window_poll_and_swap(void);
void window_terminate(void);

#endif /* WINDOW_H_ */
