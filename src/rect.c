#include "rect.h"
#include "glad/gl.h"
#include <stdio.h>
#include <stdlib.h>
#include "window.h"

uint rect_vao, rect_vbo, rect_ebo;
static const uint rect_indis[6] = {0, 1, 2, 2, 1, 3};
static uint rect_shader = 0;

static uint _rect_shader_compile(char *src, uint type)
{
	uint shd = glCreateShader(type);
	glShaderSource(shd, 1, (const char **)&src, NULL);
	glCompileShader(shd);

	int stat;
	glGetShaderiv(shd, GL_COMPILE_STATUS, &stat);
	if(!stat) {
		char log[256];
		glGetShaderInfoLog(shd, 256, NULL, log);
		fprintf(stderr, "Failed to compile shader (%s): %s\n",
				(type == GL_VERTEX_SHADER) ?
				"Vertex" : "Fragment", log);
		exit(1);
	}

	return shd;
}

static uint _rect_shader_create(void)
{
	char *vert_src = file_load("shaders/rect.vert");
	char *frag_src = file_load("shaders/rect.frag");
	uint vert_shd =_rect_shader_compile(vert_src, GL_VERTEX_SHADER);
	uint frag_shd =_rect_shader_compile(frag_src, GL_FRAGMENT_SHADER);
	free(vert_src);
	free(frag_src);

	uint prog = glCreateProgram();
	glAttachShader(prog, vert_shd);
	glAttachShader(prog, frag_shd);
	glDeleteShader(vert_shd);
	glDeleteShader(frag_shd);
	glLinkProgram(prog);

	int stat;
	glGetProgramiv(prog, GL_LINK_STATUS, &stat);
	if(!stat) {
		char log[256];
		glGetProgramInfoLog(prog, 256, NULL, log);
		fprintf(stderr, "Failed to link program: %s\n", log);
		exit(1);
	}

	return prog;
}

void rect_init(void)
{
	glGenVertexArrays(1, &rect_vao);
	glBindVertexArray(rect_vao);

	glGenBuffers(1, &rect_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, rect_vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, NULL);
	glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &rect_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rect_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rect_indis),
			rect_indis, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	rect_shader = _rect_shader_create();
}

void rect_draw(rect_t r, rgbf_t c)
{
	float verts[4][2] = {
		{r.x         / WIN_WIDTH, r.y         / WIN_HEIGHT},
		{(r.x + r.w) / WIN_WIDTH, r.y         / WIN_HEIGHT},
		{r.x         / WIN_WIDTH, (r.y + r.h) / WIN_HEIGHT},
		{(r.x + r.w) / WIN_WIDTH, (r.y + r.h) / WIN_HEIGHT}
	};

	for(int i = 0; i < 4; i++) {
		verts[i][0] *= 2;
		verts[i][1] *= 2;
		verts[i][0] -= 1;
		verts[i][1] -= 1;
		verts[i][1] = 1.0f - verts[i][1] - 1.0f;
	}

	glBindVertexArray(rect_vao);
	glBindBuffer(GL_ARRAY_BUFFER, rect_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUseProgram(rect_shader);
	glUniform3fv(glGetUniformLocation(rect_shader, "u_col"), 1, (float *)&c);

	glDrawElements(GL_TRIANGLES, sizeof(rect_indis) / sizeof(*rect_indis),
			GL_UNSIGNED_INT, rect_indis);
	glBindVertexArray(0);
}

void rect_terminate(void)
{
	glDeleteProgram(rect_shader);
}
