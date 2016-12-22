#pragma once
#include <string>
#include "struct_1.h"
typedef struct fram_buffer {
	int width;
	int height;
	float *RGBA; /*charはintの短いバージョンとして扱う*/
	/*どの場所にRGBを指定するか*/
	float *z_buffer; /*img*/
	int **frame_pos;

} fram_buffer;

class Frame_Buffer
{
public:
	Frame_Buffer();
	~Frame_Buffer();
	void Frame_Buffer::frame_alloc(int width,int height);
	void Frame_Buffer::z_alloc(int width, int height);
	void Frame_Buffer::Point_to_2D(float view_width, float view_height, float z_front, float z_back, struct_1 *data);
	fram_buffer frame;
	struct_1 point;
	bool Frame_Buffer::check_clip(int x_pos, int y_pos, float z_pos, float z_front, float z_back);
};

