#pragma once
#include <iostream>
#include <string>
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

	void pt_alloc(char *name, int num);//必要数のポイントをallocする。
	void test(char *name, int num);
};

