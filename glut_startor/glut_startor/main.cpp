/*C5-1.c*/

/*環境変数とかを考えずにプロジェクト単位で動く。
OPENGL特有のライブラリで、リンクエラーがあるものは消しても動くはず。
なので、コピーするのは、includeの文章以外いれれば大丈夫。defineはもちろんいれる。*/
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <iostream>
#include "struct_1.h"

int main()
{
	struct_1 st;

	st.a.num = 5;
	//printf(" a.num = %d\n", st.a.num);
	//st.prCreatePtObj("myObj", 5);
	st.test("myObj", 5);

	return 0;

}
/*作成->g1232219@tcu.ac.jp*/