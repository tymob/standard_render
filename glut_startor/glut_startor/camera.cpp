#include "camera.h"



camera::camera()
{
}


camera::~camera()
{
}
void camera::set_camera_value(vec3 up,vec3 dist,vec3 origin)
{
	vec3 lookvec;
	lookvec = m.norm(m.v_munis(dist, up));
	float r = (m.cross(lookvec , up)/m.norm(m.cross(lookvec,up))//*垂直な単位ベクトル*/
	view_matrix.r3={lookvec.x,lookvec.y,lookvec.z,0}

	camera_value.lookvector = m.norm(lookvector);
	camera_value.pos = pos;
	camera_value.origin_pos = origin_pos;

}

