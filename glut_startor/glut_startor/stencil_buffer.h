#pragma once
#include <string>
#define ptPointer32 int/*point����64bit�}�V���̎��Ɏ����I��8bit�ɕϊ�����Ă��܂��̂ŁAdef���Ă����B*/
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

