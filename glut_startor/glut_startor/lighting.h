#pragma once
#include "struct_1.h"
#include "my_math.h"
class lighting
{
public:
	lighting();
	~lighting();
	my_math m;
	struct_1 diffuse(struct_1 *p);

};

