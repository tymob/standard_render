#include "my_math.h"



my_math::my_math()
{
}
mat4_4 my_math::reset(mat4_4 m)
{
	m.r1.w = 1; m.r1.x = 0; m.r1.y = 0; m.r1.z = 0;
	m.r2.w = 0; m.r2.x = 1; m.r2.y = 0; m.r2.z = 0;
	m.r3.y = 0; m.r3.x = 0; m.r3.y = 1; m.r3.z = 0;
	m.r4.z = 0; m.r4.x = 0; m.r4.y = 0; m.r4.z = 1;
	return m;
}
float my_math::norm(vec3 v)
{
	vec3 v1;
	float vector_value;
	vector_value = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return vector_value;
}
float my_math::nomarlize(float n, vec3 v)
{
	return n / (v.x*v.x + v.y*v.y + v.z*v.z);
}
vec3 my_math::v_munis(vec3 v1,vec3 v2)
{
	return vec3{ v1.y*v2.z - v1.z*v2.y,  v1.z* v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x };
}
float my_math::cross(vec3 v1, vec3 v2)
{
	return{v1.x*v2.x+v1.y+v2.y+v1.z*v2.z};
}

vec3 my_math::dot(vec3 v1, vec3 v2)
{
	return{ v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,  v1.x*v2.y - v1.y * v2.x };
}
vec3 my_math::vec3_divide_scalar(vec3 v1, float scalar)
{
	return{ v1.x / scalar,v1.y / scalar,v1.z / scalar };
}
my_math::~my_math()
{
}
