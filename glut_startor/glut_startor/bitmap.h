/*----------------------bitmap.h----------------------*/
#include        <stdio.h>
#include <string>
using namespace std;

typedef struct {
	char bfType[2];
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int image_startpoint;
	unsigned int headder_size;
	unsigned int width;
	unsigned int height;
	unsigned short plane;
	unsigned short color_size;
	unsigned int compressed_format;
	unsigned int channel;
	char dummy[20];
}bitmap_info;
class bitmap
{
public:
	bitmap_info bi;
	float *RGBA;
	void reset();
	void set(int width, int height);
	void write_binary(float *RGBA,char *filename);
};