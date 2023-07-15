#include "ball.h"
#include "rect.h"
#include "util.h"
#include "window.h"
#include <stdio.h>

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

static void _ball_handle_wall_collision(void)
{
	float ball_pos[2] = {ball_rect.x, ball_rect.y};

	if(ball_pos[0] >= WIN_WIDTH || ball_pos[0] - ball_rect.w < 0) {
		ball_init();
		return;
	}

	if(ball_pos[1] + ball_rect.h < WIN_HEIGHT && ball_pos[1] >= 0)
		return;

	ball_dir[1] *= -1;
	vec2_normalize(ball_dir);
}

static void _ball_handle_paddle_collision(paddle p)
{
	float ball_pos[2] = {ball_rect.x, ball_rect.y};
	ball_pos[0] += ball_rect.w * (p.side == PAD_RIGHT);

	if(!rect_collision(p.rect, ball_rect))
		return;

	ball_dir[0] *= -1;
	//ball_dir[1] = ((p.rect.y + (p.rect.h / 2)) - ball_rect.y) / p.rect.h;
	ball_dir[1] = randf() * 2 - 1;
	vec2_normalize(ball_dir);
	//printf("%f\n", );
}

void ball_update(double dt, paddle l, paddle r)
{
	ball_rect.x += ball_dir[0] * dt * BALL_SPEED;
	ball_rect.y += ball_dir[1] * dt * BALL_SPEED;

	_ball_handle_wall_collision();
	_ball_handle_paddle_collision(l);
	_ball_handle_paddle_collision(r);
}
