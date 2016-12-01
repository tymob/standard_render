#include "struct_1.h"



struct_1::struct_1()
{
}


void struct_1::test(char *name, int num)
{
	std::cout << num << std::endl;
}
void struct_1::pt_alloc(char *name, int num)
{
	data.name = name;
	data.num = num;
	data.xyz = (float *)malloc(num * sizeof(float) * 3);
	data.color = (float *)malloc(num * sizeof(float) * 3);
	data.normal = (float *)malloc(num * sizeof(float) * 3);
	data.val = (float *)malloc(num * sizeof(float) * 1);
}

struct_1::~struct_1()
{
}
