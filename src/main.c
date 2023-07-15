#include "window.h"
#include "paddle.h"

int main(void)
{
	window_init();
	rect_init();

	paddle pad_left = paddle_create((rgbf_t){1, 1, 1});
	double time_last = window_get_time();
	while(window_is_open())
	{
		double time_now = window_get_time();
		double dt = time_now - time_last;
		time_last = time_now;

		window_clear();
		paddle_draw(pad_left);
		paddle_update(&pad_left, dt);
		window_poll_and_swap();
	}

	rect_terminate();
	window_terminate();
}
