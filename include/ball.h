#ifndef BALL_H
#define BALL_H

#include "paddle.h"

void ball_init(void);
void ball_draw(void);
void ball_update(double dt, paddle l, paddle r);

#endif /* BALL_H */
