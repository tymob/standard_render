#pragma once
#include "my_math.h"
typedef struct camera {
	vec3 lookvector;/*up,front,right*/
	vec3 pos;
	vec3 origin_pos;
} camera;
mat4_4 view_matrix;
camera camera_value;
class camera
{
public:
	camera();
	~camera();
	my_math m;
	void set_camera_value(vec3 up, vec3 dist, vec3 origin);/*視点、注視点、カメラ点*/
	void normalize()
};

