#pragma once
typedef struct vec3 {
	float x;
	float y;
	float z;
} vec3;
class primitive
{
public:
	vec3 *lists;
	primitive();
	~primitive();
	void defalut_sphere();
	
};

