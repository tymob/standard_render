#include <stdio.h>

typedef struct prPoints {
	int num;
	char *name;
	float *xyz;
	float *color;
	float *normal;
	float *val;
} prPoints;

prPoints *prCreatePtObj( char *, int);

int main(){

	prPoints *b;
	prPoints a;

	a.num =5;
	printf(" a.num = %d\n", a.num);
	b = prCreatePtObj("myObj",5);
	return 0;
}
