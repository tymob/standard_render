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

	std::ofstream ofs("Test.csv"); //�t�@�C���o�̓X�g���[��
	for (int i=0;i<400;i++)
	{ 
	ofs << p2->data.xyz[0+i*3] << "," << p2->data.xyz[1+i*3] << "," << p2->data.xyz[2+i*3] << "," << p2->data.color[0+i*3] << "," << p2->data.color[1+i*3] << "," <<  p2->data.color[2+i*3] << std::endl; //"<<"�ŗ������ނ���
	}

	std::string str;
	std::cin >> str;
	return 1;

}
/*�쐬->g1232219@tcu.ac.jp*/

/*datapos(int length,int num, int order)*/