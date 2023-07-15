#include "util.h"
#include "window.h"
#include "paddle.h"
#include "ball.h"

int main(void)
{
	window_init();
	rand_init();
	rect_init();
	ball_init();

	paddle pad_left = paddle_create(PAD_LEFT);
	paddle pad_right = paddle_create(PAD_RIGHT);
	double time_last = window_get_time();
	while(window_is_open())
	{
		double time_now = window_get_time();
		double dt = time_now - time_last;
		time_last = time_now;

		window_clear();
		paddle_draw(pad_left);
		paddle_draw(pad_right);
		paddle_update(&pad_left, dt);
		paddle_update(&pad_right, dt);
		ball_draw();
		ball_update(dt, pad_left, pad_right);
		window_poll_and_swap();
	}

	rect_terminate();
	window_terminate();
}
