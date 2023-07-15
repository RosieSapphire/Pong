#include "util.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

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
