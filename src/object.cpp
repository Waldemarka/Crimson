#include "object.hpp"

Object::Object(){}
Object::~Object(){}

bool	Object::get_flag()
{
	return (this->_in_zone);
}

void	Object::set_flag(int _start_x, int _start_y)
{
	if ((_pos_x > _start_x - 100 && _pos_x < _start_x + 600)
		&& (_pos_y > _start_y - 160 && _pos_y < _start_y + 600))
		this->_in_zone = true;
	else
		this->_in_zone = false;
}

int		Object::get_pos_x() const
{
	//printf("%d----\n", _pos_x);
	return (this->_pos_x);
}

void	Object::set_xy(int x, int y)
{
	this->_pos_x = x;
    this->_pos_y = y;
}

int		Object::get_pos_y() const
{
	return (this->_pos_y);
}
