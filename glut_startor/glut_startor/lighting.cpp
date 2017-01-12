#include "lighting.h"



lighting::lighting()
{

}

struct_1 lighting::diffuse(struct_1 *p)
{
	for (int i = 0; i < p->data.num; i++)
	{

	float x = p->data.xyz[p->datapos(3, i, 0)];//1バイト255
	float y = p->data.xyz[p->datapos(3, i, 1)]; //1バイト255
    float z = p->data.xyz[p->datapos(3, i, 2)]; //1バイト255
	vec3 v = { x,y,z };
	float Nx = m.nomarlize(x, v);
	float Ny = m.nomarlize(y, v);
	float Nz = m.nomarlize(z, v);
	vec3 Nv = { Nx,Ny,Nz };
	vec3 light1 = { 1,1,1 };
	float lx = m.nomarlize(light1.x, light1);
	float ly = m.nomarlize(light1.y, light1);
	float lz = m.nomarlize(light1.z, light1);
	vec3 lv = { lx,ly,lz };

	vec3 light_value = m.dot(Nv, lv);
    light_value = { -light_value.x,-light_value.y,-light_value.z };//対面するから
	float intencity = Nv.x * lv.x + Nv.y * lv.y + Nv.z * lv.z;
	if (intencity < 0)intencity = 0;
	//デフォルトで書いてあるdata.colorにライトの数値をかける
	p->data.color[p->datapos(3, i, 0)] *= light_value.x*intencity;
	p->data.color[p->datapos(3, i, 1)] *= light_value.y*intencity;
	p->data.color[p->datapos(3, i, 2)] *= light_value.z*intencity;
	
	}
	return *p;
}
lighting::~lighting()
{
}
