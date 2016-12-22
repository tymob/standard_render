#include "bitmap.h"
void bitmap::reset(bitmap bi)
{
	for (int i = 0; i < 10; i++)
	{
		bi.bi.headder[i] = 0;
	}
	for (int i = 0; i < 20; i++)
	{
		bi.bi.dummy[i] = 0;
	}
	bi.bi.image_startpoint = 54;
	bi.bi.headder_size = 54;
	bi.bi.plane = 3;
	bi.bi.color_size = 24;
	bi.bi.compressed_format = 0;
}
void bitmap::set(bitmap bi,int width,int height)
{
	bi.bi.width = width;
	bi.bi.height = height;
}