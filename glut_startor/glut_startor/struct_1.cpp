#include "struct_1.h"



struct_1::struct_1()
{
}

struct_1::prPoints struct_1::prCreatePtObj(char *name, int num)
{
	std::cout << num << std::endl;
	return struct_1::prPoints{
	num,name,1.0,1.0,1.0,1.0
	};
}

void struct_1::test(char *name, int num)
{
	std::cout << num << std::endl;
}

struct_1::~struct_1()
{
}
