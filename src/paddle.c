#include "paddle.h"
#include "window.h"

#define PADDLE_SPEED 512

paddle paddle_create(rgbf_t col)
{
	return (paddle){.rect = {16, 16, 32, 128}, col};
}

void paddle_draw(paddle p)
{
	rect_draw(p.rect, p.col);
}

void paddle_update(paddle *p, double dt)
{
	if(glfwGetKey(window_handle, GLFW_KEY_S))
		p->rect.y += dt * PADDLE_SPEED;

	if(glfwGetKey(window_handle, GLFW_KEY_W))
		p->rect.y -= dt * PADDLE_SPEED;

	if(p->rect.y < 0)
		p->rect.y = 0;

	if(p->rect.y + p->rect.h > WIN_HEIGHT)
		p->rect.y = WIN_HEIGHT - p->rect.h;
}
