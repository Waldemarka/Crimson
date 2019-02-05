#ifndef DECOR_HPP
#define DECOR_HPP

#include "header.hpp"
#include "parents.hpp"
#include "object.hpp"

class Decor : public Object
{
private:
	int	_num_text;
public:
	Decor();
	~Decor();
	int		get_num_texture();
	void	alive();
	bool	is_touch(int start_x, int start_y);
};

#endif