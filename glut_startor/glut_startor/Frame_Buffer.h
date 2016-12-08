#pragma once
#include <string>
typedef struct fram_buffer {
	int width;
	int height;
	unsigned char *RGBA; /*char‚Íint‚Ì’Z‚¢ƒo[ƒWƒ‡ƒ“‚Æ‚µ‚Äˆµ‚¤*/
	float z_buffer; /*img*/

} fram_buffer;

class Frame_Buffer
{
public:
	Frame_Buffer();
	~Frame_Buffer();
	void Frame_Buffer::frame_alloc(int width,int height);
	fram_buffer frame;
};

