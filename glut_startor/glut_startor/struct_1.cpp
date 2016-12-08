#include "struct_1.h"



struct_1::struct_1()
{
}


void struct_1::test(char *name, int num)
{
	std::cout << num << std::endl;
}
void struct_1::pt_alloc(char *name, int num)
{
	data.name = name;
	data.num = num;
	data.xyz = (float *)malloc(num * sizeof(float) * 3);
	data.color = (float *)malloc(num * sizeof(float) * 3);
	data.normal = (float *)malloc(num * sizeof(float) * 3);
	data.val = (float *)malloc(num * sizeof(float) * 1);
}
int struct_1::datapos(int length,int num, int order)
//length is member length.ex xyz is 3. val is 1. order should be 0,1,2
{
	return length*num + order;
}
void struct_1::set_xyz(int num, float x, float y, float z)
{
	
	data.xyz[datapos(3, num, 0)] = x;
	data.xyz[datapos(3, num, 1)] = y;
	data.xyz[datapos(3, num, 2)] = z;
}
//void struct_1::set_color(int num, float r, float g, float b);
//void struct_1::set_normal(int num, float nx, float ny, float nz);
//void struct_1::set_val(int num, float v1);
struct_1::~struct_1()
{
}
float struct_1::degree_to_rad(float degree)
{
	return degree*M_PI / 180;
}
void struct_1::default_sphere()
{
	float x=1;
	float y = 2;
	float r = 3;
	float z = 0;
	float flat_r = 0;//輪切り上のr
	pt_alloc("sphere", 20*20);//球のポイントをすべて取る
	//ここから輪切り
	for (int cut = 0; cut < 20; cut++)
	{
		//円柱にならないためにZ,rを計算
		z = -r + ((2 * r / 20)*(cut + 0.5));//20での端数のために0.5
		std::cout << "z=" << -r << "((2*" << r << "/20)*(" << cut << "+0.5))" << std::endl;
		std::cout << "z=" << (2 * r / 20) << "*" << (cut + 0.5) << std::endl;
		std::cout << z << std::endl;
		flat_r = sqrt(abs(r*r - z*z));
		for (int circle = 0; circle < 20; circle++)//輪切りの量
		{
			float degree = circle * 360 / 20;//20 should max value.
			float tmp_pos_x = x + flat_r*cos(degree_to_rad(degree));
			float tmp_pos_y = y + flat_r*sin(degree_to_rad(degree));
			float tmp_pos_z = z;
			data.xyz[datapos(3, cut * 20 + circle, 0)] = tmp_pos_x;//setX
			data.xyz[datapos(3, cut * 20 + circle, 1)] = tmp_pos_y;//setY
			data.xyz[datapos(3, cut * 20 + circle, 2)] = tmp_pos_z;//setZ

			//TEST実装
			data.color[datapos(3, cut * 20 + circle, 0)] = data.xyz[0] + data.xyz[1] + data.xyz[2];
			data.color[datapos(3, cut * 20 + circle, 1)] = data.xyz[0] + data.xyz[1] + data.xyz[2];
			data.color[datapos(3, cut * 20 + circle, 2)] = data.xyz[0] + data.xyz[1] + data.xyz[2];
		}
	}
	
}
