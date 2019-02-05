#ifndef PARENTS_HPP
#define PARENTS_HPP

#include "header.hpp"

class Parents
{
public:
	Parents();
	~Parents();
	unsigned int	get_pixel_int(SDL_Surface *surface, int x, int y);
	void			put_picture(SDL_Surface *surface, int (&x)[600][600],
					int start_x, int start_y);
	void			fliping(int x, int y, SDL_Rect* clip, double angle,
					SDL_Point* center, SDL_RendererFlip flip, SDL_Texture *surf,
					SDL_Renderer	*gRenderer);
	SDL_Surface		*load_image(const char *path);
	SDL_Texture		*LoadImage(std::string file, SDL_Renderer *renderer);
	void			 ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
};

#endif