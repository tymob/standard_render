/*C5-1.c*/

/*���ϐ��Ƃ����l�����Ƀv���W�F�N�g�P�ʂœ����B
OPENGL���L�̃��C�u�����ŁA�����N�G���[��������̂͏����Ă������͂��B
�Ȃ̂ŁA�R�s�[����̂́Ainclude�̕��͈ȊO�����Α��v�Bdefine�͂�����񂢂��B*/
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
/*�쐬->g1232219@tcu.ac.jp*/