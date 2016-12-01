#pragma once
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

typedef struct prPoints {
	int num;
	std::string name;
	float *xyz;
	float *color;
	float *normal;
	float *val;
} prPoints;
class struct_1
{
public:
	struct_1();
	~struct_1();
	prPoints data;
	void set_xyz(int num,float x,float y,float z);
	void set_color(int num, float r, float g, float b);
	void set_normal(int num, float nx, float ny, float nz);
	void set_val(int num, float v1);
	void pt_alloc(char *name, int num);//必要数のポイントをallocする。
	void test(char *name, int num);
	int datapos(int length, int num, int order);
	void default_sphere();

	//calc
	double degree_to_rad(float degree);
};

