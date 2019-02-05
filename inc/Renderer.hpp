#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "header.hpp"
#include "Enemy.hpp"
#include "parents.hpp"
#include "Player.hpp"
#include "CalcVector.hpp"
#include "Decor.hpp"

class Renderer
{
private:
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Enemy			*enemy;
	Player			*player;
	Decor			*decor;
	Parents 		parent;
	int				_x;
	int				_y;
	int				_width;
	int				_height;
	int				_start_x;
	int				_start_y;
	double			_angle;
	int				_angle_bott;
	SDL_Surface		*_back;
	SDL_Surface		*_enemy;
	SDL_Texture		*_image[3];
	SDL_Texture		*_decor[9];

public:
	int				buf[600][600];
	Renderer();
	Renderer(int x, int y);
	~Renderer();
	void			init_lib();
	SDL_Surface		*load_image(const char *path);
	void			load_all();
	bool			key_event();
	void			game();
	void			enemy_alive();
	void			enemy_draw();
	void			mouse();
	void			decor_draw();
	bool			touch_decor(int x, int y);

	//void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);

};

#endif