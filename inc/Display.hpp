#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <string>
#include "Renderer.hpp"

class Display
{
private:
	Display();
	Renderer *render;
	int		_pos_x;
	int		_pos_y;
	int		_width;
	int		_height;

public:
	Display(int pos_x, int pos_y);
	~Display();
	void	Create_window();
};

#endif