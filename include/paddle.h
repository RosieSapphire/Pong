#ifndef PADDLE_H
#define PADDLE_H

#include "rect.h"

enum paddle_side {
	PAD_LEFT,
	PAD_RIGHT
};

typedef struct {
	rect_t rect;
	enum paddle_side side;
} paddle;

paddle paddle_create(enum paddle_side side);
void paddle_draw(paddle p);
void paddle_update(paddle *p, double dt);

#endif /* PADDLE_H */
