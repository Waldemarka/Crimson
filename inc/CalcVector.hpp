#ifndef	CALCVECTOR_HPP
# define CALCVECTOR_HPP

#include <cmath>
#include <iostream>

class CalcVector
{
public:
	CalcVector();
	~CalcVector();
	double		angle( int x1, int y1, int x2, int y2);
	void		change(int x0, int y0, int &x1, int &y1);
};

#endif