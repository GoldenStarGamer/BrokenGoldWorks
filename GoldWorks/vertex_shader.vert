#version 460

vec2 positions[3] = vec2[] (
	vec2(0.0,-0.5),
	vec2(1.0,0.5),
	vec2(-1.0,0.3)
);

void main() {
	gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
}