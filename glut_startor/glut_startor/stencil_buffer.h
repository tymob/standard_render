#pragma once
#include <string>
#define ptPointer32 int/*pointだけ64bitマシンの時に自動的に8bitに変換されてしまうので、defしておく。*/
typedef struct stencil {
	int width;
	int height;
	float *normal;
	float *val;
	int *objectid;
} stencil;

class stencil_buffer
{
public:
	stencil_buffer();
	~stencil_buffer();
	void stencil_buffer::stencil_alloc(int width, int height);
	stencil stencil;

};

