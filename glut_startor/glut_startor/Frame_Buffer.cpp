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
	frame.RGBA = (float *)malloc(width*height * sizeof(float) * 4);
	for (int i = 0; i < width*height*4; i++)
	{
		frame.RGBA[i] = 0;
	}
}

void Frame_Buffer::z_alloc(int width, int height)
{
	frame.width = width;
	frame.height = height;
	frame.z_buffer = (float *)malloc(width*height * sizeof(float));
	for (int i = 0; i < width*height; i++)
	{
		frame.z_buffer[i] = -FLT_MAX;
	}
}

void Frame_Buffer::Point_to_2D(float view_width,float view_height,float z_front,float z_back,struct_1 *data)
{
	float pixel_per_width = frame.width / (view_width);
	float pixel_per_height = frame.height / (view_height);
	for (int point_count=0; point_count < data->data.num; point_count++)
	{
		//datapos=worked
		float vx = data->data.xyz[point.datapos(3, point_count, 1)];
		float vy = data->data.xyz[point.datapos(3, point_count, 2)];
		float testx = (data->data.xyz[point.datapos(3, point_count, 1)] + view_width / 2)*pixel_per_width;
		
		int x_pos = (data->data.xyz[point.datapos(3, point_count, 1)] + view_width / 2)*pixel_per_width;
		int y_pos = (data->data.xyz[point.datapos(3, point_count, 2)] + view_height/ 2)*pixel_per_height;
		float tmp_z= (data->data.xyz[point.datapos(3, point_count, 3)]);
		
		if (check_clip(x_pos, y_pos,tmp_z,z_front, z_back) == true)//true is not clip
		{		
			std::cout << "not clip" << std::endl;
			if (frame.z_buffer[point_count] < tmp_z) { frame.z_buffer[point_count] = tmp_z; }//z_buffer‚Ì‘OŒã
			frame.RGBA[x_pos*y_pos] = data->data.color[point.datapos(3, point_count, 1)];//R
			frame.RGBA[x_pos*y_pos + frame.width*frame.height] = data->data.color[point.datapos(3, point_count, 2)];//G
			frame.RGBA[x_pos*y_pos + frame.width*frame.height * 2] = data->data.color[point.datapos(3, point_count, 3)];//B
			frame.RGBA[x_pos*y_pos + frame.width*frame.height * 3] = 0;//A
		}
	}
}

bool Frame_Buffer::check_clip(int x_pos, int y_pos,float z_pos,float z_front,float z_back)
{
	if (x_pos < 0 || x_pos >= frame.width) { return false; }
	if (y_pos < 0 || y_pos >= frame.height) { return false; }
	if (z_pos > z_front || z_back < z_back) { return false; }
	return true;
}


