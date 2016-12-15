#pragma once
#include "my_math.h"
#include "matrix.h"
typedef struct camera_info {
	vec3 lookvector;/*up,front,right*/
	vec3 pos;
	vec3 origin_pos;
} camera_info;


class camera
{
public:
	camera();
	~camera();
	my_math m;

	mat4_4 set_camera_value(vec3 up, vec3 dist, vec3 origin);/*視点、注視点、カメラ点*/

};

