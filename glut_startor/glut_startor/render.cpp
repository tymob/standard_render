#include "render.h"



render::render()
{
}

struct_1 render::convert(mat4_4 view_matrix, struct_1 *p2)
{
	for (int i = 0; i < p2->data.num; i++)
	{
		float x, y, z;
		p2->data.xyz[3 * i] = view_matrix.r1.w*p2->data.xyz[3 * i] + view_matrix.r1.x*p2->data.xyz[3 * i + 1] + view_matrix.r1.y*p2->data.xyz[3 * i + 2] + view_matrix.r1.z * 1;
		p2->data.xyz[3 * i + 1] = view_matrix.r2.w*p2->data.xyz[3 * i] + view_matrix.r2.x*p2->data.xyz[3 * i + 1] + view_matrix.r2.y*p2->data.xyz[3 * i + 2] + view_matrix.r2.z * 1;
		p2->data.xyz[3 * i + 2] = view_matrix.r3.w*p2->data.xyz[3 * i] + view_matrix.r3.x*p2->data.xyz[3 * i + 1] + view_matrix.r3.y*p2->data.xyz[3 * i + 2] + view_matrix.r3.z * 1;
	}
	
	return *p2;
	
}

render::~render()
{
}
