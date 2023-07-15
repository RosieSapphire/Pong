#include "util.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void rand_init(void)
{
	srand(time(0));
}

char *file_load(const char *path)
{
	FILE *f = fopen(path, "r");
	if(!f) {
		fprintf(stderr, "Failed to load file from '%s'\n", path);
		exit(1);
	}

	fseek(f, 0, SEEK_END);
	size_t len = ftell(f);
	rewind(f);
	char *buf = malloc(len);
	fread(buf, len, 1, f);
	fclose(f);
	buf[len - 1] = 0;
	return buf;
}

float randf(void)
{
	return (float)rand() / (float)RAND_MAX;
}

void vec2_normalize(float v[2])
{
	float mag = sqrtf(v[0] * v[0] + v[1] * v[1]);
	if(!mag)
		return;

	v[0] /= mag;
	v[1] /= mag;
}
