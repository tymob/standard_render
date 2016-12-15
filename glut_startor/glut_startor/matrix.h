/*
matrix.h

Copyright(c) 1995 - 2002 ASANO Ichiro
*/

#include <iostream>    // for 'err' and 'cout' stream and 'ostream' class.
#include <stdlib.h>      // for 'exit()' function in operator ().
using namespace std;
class MAT {
public:
	MAT(int, int, double init = 0.0);
	MAT(const MAT &);
	MAT(void) :row(0), column(0), dat(0) {};
	~MAT();
	MAT &operator =(const MAT &);
	double &operator ()(int, int) const;
	double Cofactor(int, int) const;
	double Minor(int, int) const;
	int Row(void) const { return row; };
	int Column(void) const { return column; };
	friend ostream & operator << (ostream &, const MAT &);
	friend MAT &operator +(const MAT &, const MAT &);
	friend MAT &operator -(const MAT &, const MAT &);
	friend MAT &operator *(const MAT &, const MAT &);
	friend MAT &operator *(const MAT &, double);
	friend MAT &operator *(double f, const MAT &m) { return m * f; };
	friend MAT &operator /(const MAT &m, double f) { return m * (1.0 / f); };
	friend MAT &T(const MAT &);
	friend MAT &INV3(const MAT &);
	friend MAT &INV(const MAT &);
	friend MAT &INV2(const MAT &);
	friend double D(const MAT &);
protected:
	int row, column;
	double *dat;
	void SwapColumn(int, int);
	void SwapRow(int, int);
};

inline double &MAT::operator ()(int i, int j) const {
	if (i < 0 || i >= row || j  < 0 || j >= column) {
		cerr << "MAT operator ():Subscript is out of range.\n";
		exit(EXIT_FAILURE);
	}
	return dat[i * column + j];
}