#pragma once
#include "camera.h"
#include "struct_1.h"

class render
{
public:
	render();
	~render();
	camera camera;
	struct_1 point;
	struct_1 convert(mat4_4 view_matrix, struct_1 *p2);
};

