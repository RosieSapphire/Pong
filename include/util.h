#ifndef UTIL_H_
#define UTIL_H_

typedef unsigned int uint;

typedef struct {
	float r, g, b;
} rgbf_t;

char *file_load(const char *path);

#endif /* UTIL_H_ */
