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
int main()
{
	
	struct_1 st;
	struct_1 *p;
	p = new struct_1();
	p->pt_alloc("test", 5);
	std::cout << p->data.name << std::endl;
	std::string str;
	std::cin >> str;
	return 1;

}
/*作成->g1232219@tcu.ac.jp*/