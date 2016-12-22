/*----------------------bitmap.h----------------------*/
#include        <stdio.h>


typedef struct {
	char headder[10];
	unsigned int image_startpoint;
	unsigned int headder_size;
	unsigned int width;
	unsigned int height;
	unsigned short plane;
	unsigned short color_size;
	unsigned int compressed_format;
	char dummy[20];
}bitmap_info;
class bitmap
{
public:
	bitmap_info bi;
	void reset(bitmap bi);
	void set(bitmap bi, int width, int height);
}