#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "header.hpp"
#include "object.hpp"

class Enemy : public Object
{
private:
	int		_pos_x;
	int		_pos_y;
	bool	_in_zone;
	clock_t _t0;

public:
	Enemy();
	~Enemy();
	void	alive();
	void	change_pos(int st_x, int st_y);
	void	draw_enemy(int (&buf)[600][600], int _start_x, int _start_y, SDL_Surface *Texture);
};

#endif