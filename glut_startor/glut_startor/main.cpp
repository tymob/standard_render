/*C5-1.c*/

/*���ϐ��Ƃ����l�����Ƀv���W�F�N�g�P�ʂœ����B
OPENGL���L�̃��C�u�����ŁA�����N�G���[��������̂͏����Ă������͂��B
�Ȃ̂ŁA�R�s�[����̂́Ainclude�̕��͈ȊO�����Α��v�Bdefine�͂�����񂢂��B*/
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
/*�쐬->g1232219@tcu.ac.jp*/