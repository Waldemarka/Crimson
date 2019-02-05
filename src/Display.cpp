#include "Display.hpp"

Display::Display(){}
Display::~Display(){}

Display::Display(int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x > 2000 || pos_y < 0 || pos_y > 200)
	{
		std::cout << "bad widnow location" << std::endl;
		exit(1);
	}
	this->_pos_x = pos_x;
	this->_pos_y = pos_y;
	this->_width = 600;
	this->_height = 600;
	std::cout << "TYT" <<std::endl;
}

void		Display::Create_window()
{
	render = new Renderer(_pos_x, _pos_y);
	render->game();
}