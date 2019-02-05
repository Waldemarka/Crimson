#ifndef OBJECT_HPP
# define OBJECT_HPP

#include <iostream>

class Object
{
public:
	Object();
	~Object();
	bool 	get_flag();
	void	set_flag(int _start_x, int _start_y);
	int		get_pos_x() const;
	int		get_pos_y() const;
	void	set_xy(int x, int y);
protected:
	int		_pos_x;
	int		_pos_y;
	bool	_in_zone;
};

#endif