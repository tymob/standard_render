#include "bitmap.h"
void bitmap::reset()
{
    bi.bfType[0] = 'B';
	bi.bfType[1] = 'M';
	bi.bfReserved1 = 0;
	bi.bfReserved2 = 0;
	for (int i = 0; i < 20; i++)
	{
		bi.dummy[i] = 0;
	}
	bi.image_startpoint = 54;
	bi.headder_size = 40;
	bi.plane = 1;//常に位置
	bi.color_size = 24;
	bi.compressed_format = 0;
	bi.channel = bi.color_size / 8;
	
}
void bitmap::set(int width,int height)
{
	bi.width = width;
	bi.height = height;
	if (bi.color_size < 8) { fprintf(stderr,"error" ); }
	bi.bfSize = width*height*bi.channel + bi.image_startpoint;
	int a = 1;
}
void bitmap::write_binary(float *RGBA, char *filename)
{
	//リトルエンディアンのバイナリスワップそのまま
	FILE *fp;
	fp=fopen(filename, "wb");
	fwrite(bi.bfType, sizeof(char), 2, fp);//&つけなくても動く。
	fwrite(&bi.bfSize, sizeof(unsigned int), 1, fp);
	fwrite(&bi.bfReserved1, sizeof(char), 2, fp);
	fwrite(&bi.bfReserved2, sizeof(char), 2, fp);
	fwrite(&bi.image_startpoint, sizeof(unsigned int), 1, fp);//unsignedでも正にずらす
	fwrite(&bi.headder_size, sizeof(unsigned int), 1, fp);//unsignedでも正にずらす
	fwrite(&bi.width, sizeof(unsigned int), 1, fp);
	fwrite(&bi.height, sizeof(unsigned int), 1, fp);
	fwrite(&bi.plane, sizeof(unsigned short), 1, fp);
	fwrite(&bi.color_size, sizeof(unsigned short), 1, fp);
	fwrite(&bi.compressed_format, sizeof(unsigned int), 1, fp);
	fwrite(bi.dummy, sizeof(char), 20, fp);
	for (int i = 0; i < bi.width*bi.height; i++)
	{
		unsigned char value_r = RGBA[i] * 255; //1バイト255
		unsigned char value_g = RGBA[i+ bi.width*bi.height] * 100; //1バイト255
		unsigned char value_b = RGBA[i + bi.width*bi.height*2] * 100; //1バイト255
		unsigned char value_a = RGBA[i + bi.width*bi.height*3] * 100; //1バイト255
		fwrite(&value_r, sizeof(unsigned char), 1, fp);
		fwrite(&value_g, sizeof(unsigned char), 1, fp);
		fwrite(&value_b, sizeof(unsigned char), 1, fp);
	}
	


}