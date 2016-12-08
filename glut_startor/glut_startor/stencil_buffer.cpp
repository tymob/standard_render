#include "stencil_buffer.h"



stencil_buffer::stencil_buffer()
{
}


stencil_buffer::~stencil_buffer()
{
}

void stencil_buffer::stencil_alloc(int width, int height)
{
	stencil.width = width;
	stencil.height = height;
	stencil.normal = (float *)malloc(width*height * sizeof(float) * 3);
	stencil.val = (float *)malloc(width*height * sizeof(float) * 1);
	stencil.objectid = (int *)malloc(width*height * sizeof(int) * 1);
}
