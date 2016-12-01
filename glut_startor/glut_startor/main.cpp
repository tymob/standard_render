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
int main()
{
	
	struct_1 st;
	struct_1 *p;
	struct_1 *p2;
 	p = new struct_1();
	p->pt_alloc("test", 5);
	p->set_xyz(2, 1, 2, 1);
	std::cout << p->data.xyz[p->datapos(3, 2, 0)] << std::endl;

	p2 = new struct_1();
	p2->default_sphere();

	std::ofstream ofs("Test.csv"); //ファイル出力ストリーム
	for (int i=0;i<400;i++)
	{ 
	ofs << p2->data.xyz[0+i*3] << "," << p2->data.xyz[1+i*3] << "," << p2->data.xyz[2+i*3] << "," << p2->data.color[0+i*3] << "," << p2->data.color[1+i*3] << "," <<  p2->data.color[2+i*3] << std::endl; //"<<"で流し込むだけ
	}

	std::string str;
	std::cin >> str;
	return 1;

}
/*作成->g1232219@tcu.ac.jp*/

/*datapos(int length,int num, int order)*/