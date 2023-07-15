#version 330 core

uniform vec3 u_col;

out vec4 frag_col;

void main()
{
	frag_col = vec4(u_col, 1.0);
}
