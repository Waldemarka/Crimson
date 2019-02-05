#include "Enemy.hpp"
#include "parents.hpp"
#include "CalcVector.hpp"

Enemy::Enemy(){}
Enemy::~Enemy(){}

void	Enemy::draw_enemy(int (&buf)[600][600], int _start_x, int _start_y, SDL_Surface *surf)
{
	int	view;
	int q = -1;
	static int a;

	_pos_x = get_pos_x();
	_pos_y = get_pos_y();

	if (_start_x + 300 < _pos_x)
		view = 720;
	else
		view = 210;
	Parents *parent = new Parents();
	while (++q < 60)
	{
		int i = -1;
		while (++i < 61)
		{
			int pixel = parent->get_pixel_int(surf, (a * 65) + q, view + i);
			if (pixel != 0 && (_pos_y - _start_y + i > 0 && _pos_y - _start_y + i < 600)
				&& (_pos_x - _start_x + q > 0 && _pos_x - _start_x + q < 600))
				buf[_pos_y - _start_y + i][_pos_x - _start_x + q] = pixel;
		}
	}
	if (clock() - _t0 > 70000)
	{
		a++;
		_t0 = clock();
	}
	if (a > 8)
		a = 0;
	delete parent;
}

void	Enemy::change_pos(int st_x, int st_y)
{
	CalcVector *vect = new CalcVector();
	vect->change(st_x + 300, st_y + 300, _pos_x, _pos_y);
	delete vect;
}

void	Enemy::alive()
{
	set_xy(rand() % 3000, rand() % 3000);
	_in_zone = false;
	_t0 = clock();
}














