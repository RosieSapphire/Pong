#ifndef PADDLE_H
#define PADDLE_H

#include "rect.h"

typedef struct {
	rect_t rect;
	rgbf_t col;
} paddle;

paddle paddle_create(rgbf_t col);
void paddle_draw(paddle p);
void paddle_update(paddle *p, double dt);

#endif /* PADDLE_H */
