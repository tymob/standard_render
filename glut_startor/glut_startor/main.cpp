/*C5-1.c*/

/*環境変数とかを考えずにプロジェクト単位で動く。
OPENGL特有のライブラリで、リンクエラーがあるものは消しても動くはず。
なので、コピーするのは、includeの文章以外いれれば大丈夫。defineはもちろんいれる。*/
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <iostream>
#include "struct_1.h"
#include <string>
#include <fstream>
#include "render.h"
int main()
{
	
	struct_1 st;
	struct_1 *p;
	struct_1 *p2;
	struct_1 *points_converted;
	camera camera;
	render render;
	my_math m;
 	p = new struct_1();
	p->pt_alloc("test", 5);
	p->set_xyz(2, 1, 2, 1);
	std::cout << p->data.xyz[p->datapos(3, 2, 0)] << std::endl;

	p2 = new struct_1();
	p2->default_sphere();
	mat4_4 view_matrix =camera.set_camera_value(vec3{ 0,1,0 }, vec3{ 2,4, 0}, vec3{ 2,4,5 });//z dicide camera vector
	points_converted = new struct_1();
	*points_converted = render.convert(view_matrix, p2);
	std::ofstream ofs("Test_moved.csv"); //ファイル出力ストリーム
	for (int i = 0; i<400; i++)
	{
		ofs << points_converted->data.xyz[0 + i * 3] << "," << points_converted->data.xyz[1 + i * 3] << "," << p2->data.xyz[2 + i * 3] << "," << points_converted->data.color[0 + i * 3] << "," << points_converted->data.color[1 + i * 3] << "," << points_converted->data.color[2 + i * 3] << std::endl; //"<<"で流し込むだけ
	}
	
	return 1;

}
/*作成->g1232219@tcu.ac.jp*/

/*datapos(int length,int num, int order)*/