#include "CalcVector.hpp"

CalcVector::CalcVector(){}
CalcVector::~CalcVector(){}

double		CalcVector::angle( int x1, int y1, int x2, int y2)
{
	double angle = (x1*x2+y1*y2)/(sqrt((double)x1*x1+y1*y1)*sqrt((double)x2*x2+y2*y2));
	
	//printf("%f\n", angle);
	if (y1 >= 0)
	{
		return (acos(angle) * (180.0 / M_PI) - 90.0);
	}
	else
		return (270.0 - acos(angle) * (180.0 / M_PI));
}
/*_degree = 90.0 - acos(angle_cos) * (180.0 / M_PI);*/
void		CalcVector::change(int x0, int y0, int &x1, int &y1)
{
	int deltax = abs(x1 - x0);
	int deltay = abs(y1 - y0);
	int x_step = x1 >= x0 ? 1 : -1;
	int y_step = y1 >= y0 ? 1 : -1;
	int error;
	int q;
	int x;
	int y;
/*	if (deltax > deltay)
	{*/

		error = (deltay << 1) - deltax;
		x = x0 + x_step;
		y = y0;
		q = 1;
		//while (q <= 2)
		//{
			if (error > 0)
			{
				y += y_step;
				error += (deltay - deltax) << 1;
			}
			else
				error += deltay << 1;
			x += x_step;
			q++;
		//}
		x1 = x;
		y1 = y;
		
	/*}
	else
		for_dy(data);*/
}

/*void	for_dx()
{
}

void	for_dy()
{
	int error;
	int q;
	int x;
	int y;

	error = (deltax << 1) - deltay;
	y = y0 + y_step;
	x = x0;
	q = 1;
	mlx_pixel_put(mlx, win, x0, y0, color);
	while (q <= deltay)
	{
		if (error > 0)
		{
			error += (deltax - deltay) << 1;
			x += x_step;
		}
		else
			error += deltax << 1;
		y += y_step;
		q++;
	}
}*/

