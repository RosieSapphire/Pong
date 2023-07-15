#include "paddle.h"
#include "window.h"

#define PADDLE_SPEED 512

paddle paddle_create(enum paddle_side side)
{
	int x = 0;
	switch(side) {
	case PAD_LEFT:
		x = 16;
		break;

	case PAD_RIGHT:
		x = WIN_WIDTH - 16 - 32;
		break;
	}

	return (paddle){.rect = {x, 16, 32, 128}, side};
}

void paddle_draw(paddle p)
{
	rect_draw(p.rect, (rgbf_t){1, 1, 1});
}

void paddle_update(paddle *p, double dt)
{
	bool inputs[2][2] = {
		{glfwGetKey(window_handle, GLFW_KEY_S),
			glfwGetKey(window_handle, GLFW_KEY_W)},
		{glfwGetKey(window_handle, GLFW_KEY_DOWN),
			glfwGetKey(window_handle, GLFW_KEY_UP)},
	};

	if(inputs[p->side][0])
		p->rect.y += dt * PADDLE_SPEED;

	if(inputs[p->side][1])
		p->rect.y -= dt * PADDLE_SPEED;

	if(p->rect.y < 0)
		p->rect.y = 0;

	if(p->rect.y + p->rect.h > WIN_HEIGHT)
		p->rect.y = WIN_HEIGHT - p->rect.h;
}
