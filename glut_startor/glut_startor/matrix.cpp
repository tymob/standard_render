/*
matrix.cpp

Copyright (c) 1995-2002 ASANO Ichiro
*/

#include <math.h>          // for 'fabs()' and 'pow()' funtions.
#include "matrix.h"

MAT::MAT(int r, int c, double init) :row(r), column(c) {
	if (row <= 0 || column <= 0) {
		cerr << "constructor MAT(int,int):invailed matrix size.\n";
		exit(EXIT_FAILURE);
	}
	long size = row * column;
	dat = new double[size];
	if (!dat) {
		cerr << "constructor MAT(int,int):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; i++)
		dat[i] = init;   // initialize to 'init'.
}

MAT::MAT(const MAT &m) :row(m.row), column(m.column) {
	long size = row * column;
	dat = new double[size];
	if (!dat) {
		cerr << "constructor MAT(MAT &):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; i++)
		dat[i] = m.dat[i];   // copy 'MAT &m' to new matrix.
}

MAT::~MAT() {
	if (dat)   delete[] dat;
}

MAT &MAT::operator =(const MAT &m) {
	long size = m.row * m.column;
	if (!dat) {
		row = m.row;
		column = m.column;
		dat = new double[size];
		if (!dat) {
			cerr << "MAT operator =:Can not allocate memory.\n";
			exit(EXIT_FAILURE);
		}
	}
	else if (row != m.row || column != m.column) {
		cerr << "MAT operator =:Size differ from another.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < size; i++)
		dat[i] = m.dat[i];
	return *this;
}

/* double MAT::Cofactor(int,int) : cofactor */

double MAT::Cofactor(int r, int c) const {
	return pow(-1.0, r + c) * Minor(r, c);
}

/* double MAT::Minor(int,int) : minor determinant */

double MAT::Minor(int r, int c) const {
	MAT m(row - 1, column - 1);
	int i, j, x, y;
	for (i = 0, x = 0; i < row; i++) {
		if (i == r)   continue;
		for (j = 0, y = 0; j < column; j++) {
			if (j == c)   continue;
			m(x, y) = (*this)(i, j);
			y++;
		}
		x++;
	}
	return D(m);
}

ostream &operator << (ostream &s, const MAT &m) {
	const double min = pow(10.0, -15);
	s << '\n';
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.column; j++) {
			s.width(11);
			if (fabs(m(i, j)) < min)
				s << 0.0;
			else
				s << m(i, j);
		}
		s << '\n';
	}
	return s;
}

MAT &operator +(const MAT &a, const MAT &b) {
	if (a.row != b.row || a.column != b.column) {
		cerr << "MAT operator +:Size differ from another.\n";
		exit(EXIT_FAILURE);
	}
	MAT *pc = new MAT(a.row, a.column);
	if (!pc) {
		cerr << "MAT operator +:Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < a.row * a.column; i++)
		pc->dat[i] = a.dat[i] + b.dat[i];
	return *pc;
}

MAT &operator -(const MAT &a, const MAT &b) {
	if (a.row != b.row || a.column != b.column) {
		cerr << "MAT operator -:Size differ from another.\n";
		exit(EXIT_FAILURE);
	}
	MAT *pc = new MAT(a.row, a.column);
	if (!pc) {
		cerr << "MAT operator -:Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < a.row * a.column; i++)
		pc->dat[i] = a.dat[i] - b.dat[i];
	return *pc;
}

MAT &operator *(const MAT &a, const MAT &b) {
	if (a.column != b.row) {
		cerr << "MAT operator *(MAT &,MAT &):Invailed matrix size.\n";
		exit(EXIT_FAILURE);
	}
	MAT *pc = new MAT(a.row, b.column);
	if (!pc) {
		cerr << "MAT operator *(MAT &,MAT &):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < b.column; j++) {
			register double f = 0.0;
			for (int k = 0; k < a.column; k++)
				f += a(i, k) * b(k, j);
			(*pc)(i, j) = f;
		}
	}
	return *pc;
}

MAT &operator *(const MAT &a, double f) {
	MAT *pb = new MAT(a.row, a.column);
	if (!pb) {
		cerr << "MAT operator *(MAT &,double):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < a.row * a.column; i++)
		pb->dat[i] = a.dat[i] * f;
	return *pb;
}

/* MAT &T(const MAT &) : transpose */

MAT &T(const MAT &a) {
	MAT *pb = new MAT(a.column, a.row);
	if (!pb) {
		cerr << "MAT T(MAT &):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < a.row; i++)
		for (int j = 0; j < a.column; j++)
			(*pb)(j, i) = a(i, j);
	return *pb;
}

/* MAT &INV3(const MAT &) : inverse - sweep out method */

MAT &INV3(const MAT &a) {
	if (a.row != a.column) {
		cerr << "MAT INV3(MAT &):Invailed matrix size.\n";
		exit(EXIT_FAILURE);
	}
	MAT *c = new MAT(a.row, a.column);
	MAT *b = new MAT(a.row, a.column);
	if (!b || !c) {
		cerr << "MAT INV3(MAT &):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	int h, i, j;
	for (i = 0; i < b->row; i++) {
		for (j = 0; j < a.column; j++) {
			(*b)(i, j) = a(i, j);
			(*c)(i, j) = (i == j) ? 1.0 : 0.0;
		}
	}
	for (h = 0; h < b->row; h++) {
		double p = (*b)(h, h);
		if (p != 1.0) {
			if (p == 0.0) {
				cerr << "MAT INV3(MAT &):Can not calculate inverse.\n";
				exit(EXIT_FAILURE);
			}
			for (j = 0; j < b->column; j++) {
				(*b)(h, j) /= p;
				(*c)(h, j) /= p;
			}
		}
		for (i = 0; i < b->row; i++)
			if (i != h && (p = (*b)(i, h)) != 0.0)
				for (j = 0; j < b->column; j++) {
					(*b)(i, j) -= p * (*b)(h, j);
					(*c)(i, j) -= p * (*c)(h, j);
				}
	}
	delete b;
	return *c;
}

/* MAT &INV3(const MAT &) : inverse - sweep out method - old */
/*
MAT &INV3(const MAT &a){
if(a.row != a.column){
cerr << "MAT INV(MAT &):Invailed matrix size.\n";
exit(EXIT_FAILURE);
}
MAT *c = new MAT(a.row,a.column);
MAT *b = new MAT(a.row,a.column * 2);
if(!b || !c) {
cerr << "MAT INV(MAT &):Can not allocate memory.\n";
exit(EXIT_FAILURE);
}
int h,i,j;
for(i = 0;i < b->row;i++){
for(j = 0;j < a.column;j++)
(*b)(i,j) = a(i,j);
for(j = a.column;j < b->column;j++)
(*b)(i,j) = ((j - a.column) == i) ? 1.0 : 0.0;
}
for(h = 0;h < b->row;h++){
double p = (*b)(h,h);
if(p != 1.0){
if(!b || !c){
cerr << "MAT INV(MAT &):Can not calculate inverse.\n";
exit(EXIT_FAILURE);
}
for(j = 0;j < b->column;j++)
(*b)(h,j) /= p;
}
for(i = 0;i < b->row;i++)
if(i != h && (p = (*b)(i,h)) != 0.0)
for(j = h;j < b->column;j++)
(*b)(i,j) -= p * (*b)(h,j);
}
for(i = 0;i < c->row;i++)
for(j = 0;j < c->column;j++)
(*c)(i,j) = (*b)(i,j + c->column);
delete b;
return *c;
}
*/

static void Swap(int &a, int &b) {
	register int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

static void Swap(double &a, double &b) {
	register double tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void MAT::SwapColumn(int a, int b) {
	if (a < 0 || a >= column || b < 0 || b >= column) {
		cerr << "MAT::SwapColumn(int,int):Subscript is out of range.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < row; i++)
		Swap((*this)(i, a), (*this)(i, b));
}

void MAT::SwapRow(int a, int b) {
	if (a < 0 || a >= row || b < 0 || b >= row) {
		cerr << "MAT::SwapRow(int,int):Subscript is out of range.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < column; i++)
		Swap((*this)(a, i), (*this)(b, i));
}

/* MAT &INV(const MAT &) : inverse */

MAT &INV(const MAT &a) {
	if (a.row != a.column) {
		cerr << "MAT INV(MAT &):Not a square matrix.\n";
		exit(EXIT_FAILURE);
	}
	MAT *pb = new MAT(a);
	if (!pb) {
		cerr << "MAT INV(MAT &):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	int *list = new int[pb->column];
	int h, i, j;
	for (i = 0; i < pb->column; i++)
		list[i] = i;
	for (h = 0; h < pb->row; h++) {
		double max = 0.0;
		int max_column;
		for (j = h; j < pb->column; j++) {
			register double tmp = fabs((*pb)(h, j));
			if (max < tmp) {
				max = tmp;
				max_column = j;
			}
		}
		if (max == 0.0) {
			cerr << "MAT INV(MAT &):Can not calculate.\n";
			exit(EXIT_FAILURE);
		}
		if (max_column != h) {
			Swap(list[h], list[max_column]);
			pb->SwapColumn(h, max_column);
		}
		double p = (*pb)(h, h);
		for (j = 0; j < pb->column; j++)
			(*pb)(h, j) /= p;
		(*pb)(h, h) = 1.0 / p;
		for (i = 0; i < pb->row; i++)
			if (i != h && (p = (*pb)(i, h)) != 0) {
				for (j = 0; j < pb->column; j++)
					(*pb)(i, j) -= p * (*pb)(h, j);
				(*pb)(i, h) = -p * (*pb)(h, h);
			}
	}
	for (i = 0; i < pb->column; i++)
		if (list[i] != i) {
			pb->SwapRow(i, list[i]);
			Swap(list[i], list[list[i]]);
		}
	return *pb;
}

/* MAT &INV2(const MAT &) : inverse */

MAT &INV2(const MAT &a) {
	if (a.row != a.column) {
		cerr << "MAT INV2(MAT &):Not a square matrix.\n";
		exit(EXIT_FAILURE);
	}
	MAT *pb = new MAT(a.row, a.column);
	if (!pb) {
		cerr << "MAT INV2(MAT &):Can not allocate memory.\n";
		exit(EXIT_FAILURE);
	}
	double d = D(a);
	if (!d) {
		cerr << "MAT INV2(MAT &):Can not calculate inverse.\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < pb->row; i++)
		for (int j = 0; j < pb->column; j++)
			(*pb)(i, j) = a.Cofactor(j, i) / d;
	return *pb;
}


/* double D(const MAT &) : determinant */

double D(const MAT &m) {
	if (m.row != m.column) {
		cerr << "MAT D(MAT &):Not a square matrix.\n";
		exit(EXIT_FAILURE);
	}
	if (m.row > 3) {
		double f = 0.0;
		for (int i = 0; i < m.row; i++)
			f += m.Cofactor(i, 0) * m(i, 0);
		return f;
	}
	else if (m.row == 3) {
		return    m(0, 0) * m(1, 1) * m(2, 2) + m(0, 1) * m(1, 2) * m(2, 0) +
			m(0, 2) * m(2, 1) * m(1, 0) - m(0, 2) * m(1, 1) * m(2, 0) -
			m(0, 1) * m(1, 0) * m(2, 2) - m(0, 0) * m(2, 1) * m(1, 2);
	}
	else if (m.row == 2) {
		return m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0);
	}
	else {
		cerr << "MAT D(MAT &):Can not calculate determinant.\n";
		exit(EXIT_FAILURE);
	}
	return 0.0;    //It's a dummy to suppress return value warning.
}