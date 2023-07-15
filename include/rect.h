#ifndef RECT_H_
#define RECT_H_

#include "util.h"

typedef struct {
	float x, y, w, h;
} rect_t;

extern uint rect_vao, rect_vbo, rect_ebo;

void rect_init(void);
void rect_draw(rect_t r, rgbf_t c);
void rect_terminate(void);

#endif /* RECT_H_ */
