#include "Frame_Buffer.h"



Frame_Buffer::Frame_Buffer()
{
	
}


Frame_Buffer::~Frame_Buffer()
{
}

void Frame_Buffer::frame_alloc(int width, int height)
{
	frame.width = width;
	frame.height = height;
	frame.RGBA = (unsigned char *)malloc(width*height * sizeof(unsigned char) * 4);
}


