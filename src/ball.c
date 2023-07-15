#include "ball.h"
#include "rect.h"
#include "util.h"
#include "window.h"

#define BALL_SPEED 512

static rect_t ball_rect;
float ball_dir[2];

void ball_init(void)
{
	ball_rect.x = WIN_WIDTH >> 1;
	ball_rect.y = WIN_HEIGHT >> 1;
	ball_rect.w = 16;
	ball_rect.h = 16;

	ball_dir[0] = randf() * 2 - 1;
	ball_dir[1] = randf() * 2 - 1;
	vec2_normalize(ball_dir);
}

void ball_draw(void)
{
	rect_draw(ball_rect, (rgbf_t){1, 1, 1});
}

void ball_update(double dt, paddle p)
{
	ball_rect.x += ball_dir[0] * dt * BALL_SPEED;
	ball_rect.y += ball_dir[1] * dt * BALL_SPEED;

	if(ball_rect.y + ball_rect.h >= WIN_HEIGHT || ball_rect.y < 0)
		ball_dir[1] *= -1;

	if(rect_contains_point(p.rect, (float[2]){ball_rect.x, ball_rect.y}))
		ball_dir[0] *= -1;
}
