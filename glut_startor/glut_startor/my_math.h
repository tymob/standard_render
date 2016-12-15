#pragma once
#include <math.h>
typedef struct vec2 {
	float x;
	float y;
} vec2;

typedef struct vec3 {
	float x;
	float y;
	float z;
} vec3;
typedef struct vec4 {
	float w;
	float x;
	float y;
	float z;
} vec4;
typedef struct mat4_4 {
	vec4 r1;
	vec4 r2;
	vec4 r3;
	vec4 r4;
} mat4_4;


class my_math
{
public:
	my_math();
	~my_math();
	mat4_4 reset(mat4_4 m);
	float norm(vec3 v);
	vec3 v_munis(vec3 v1, vec3 v2);
	float cross(vec3 v1,vec3 vec2);
	vec3 dot(vec3 v1, vec3 v2);
	vec3 vec3_divide_scalar(vec3 v1, float scalar);

	

};
// 例:三次元ベクトルクラス




