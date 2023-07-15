#ifndef UTIL_H_
#define UTIL_H_

typedef unsigned int uint;

typedef struct {
	float r, g, b;
} rgbf_t;

void rand_init(void);
char *file_load(const char *path);
float randf(void);
void vec2_normalize(float v[2]);

#endif /* UTIL_H_ */
