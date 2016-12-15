#include "camera.h"



camera::camera()
{
}


camera::~camera()
{
}
mat4_4 camera::set_camera_value(vec3 up,vec3 dist,vec3 origin)
{
	mat4_4 view_matrix;
	vec3 f = m.vec3_divide_scalar(m.v_munis(dist, up),m.norm(m.v_munis(dist, up))); /*f_value*/
	vec3 r = m.vec3_divide_scalar(m.dot(f, up) ,m.norm(m.dot(f, up)));//*垂直な単位ベクトル*/
	vec3 u = m.dot(r,f);
	view_matrix.r1 = { r.x,r.y,r.z,-1 * m.cross(r,origin) };
	view_matrix.r2 = { u.x,u.y,u.z,-1 * m.cross(u,origin) };
	view_matrix.r3 = { f.x,f.y,f.z,-1 * m.cross(f,origin) };
	view_matrix.r4 = {0,0,0,1 };
	
	//camera_value.lookvector = m.norm(lookvector);
	//camera_value.pos = pos;
	//camera_value.origin_pos = origin_pos;
	return view_matrix;

}



