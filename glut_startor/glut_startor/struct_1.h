#pragma once
#include <iostream>
class struct_1
{
public:
	struct_1();
	~struct_1();

	typedef struct prPoints {
		int num;
		char *name;
		float xyz;
		float color;
		float normal;
		float val;
	} prPoints;

	prPoints b;
	prPoints a;
	prPoints prCreatePtObj(char *, int);
	void struct_1::test(char *name, int num);
};

