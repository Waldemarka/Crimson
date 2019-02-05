#include "parents.hpp"

Parents::Parents(){}
Parents::~Parents(){}

unsigned int	Parents::get_pixel_int(SDL_Surface *surface, int x, int y)
{
	unsigned int	*pixels;

	pixels = (unsigned int*)surface->pixels;
	return (pixels[(y * surface->w) + x]);
}

void			Parents::put_picture(SDL_Surface *surface, int (&x)[600][600], int start_x, int start_y)
{
	int q = -1;
	int tmp = start_y;
	while (++q < 600)
	{
		int i = -1;
		start_y = tmp;
		while (++i < 600)
		{
			int pixel = get_pixel_int(surface, start_x % 128, start_y % 128);
			if (pixel != 0)
				x[i][q] = pixel;
		start_y++;
		}
		start_x++;
	}

}

void			Parents::fliping(int x, int y, SDL_Rect* clip, double angle,
				SDL_Point* center, SDL_RendererFlip flip, SDL_Texture *surf,
				SDL_Renderer	*gRenderer)
{
	SDL_Rect renderQuad = { x, y, 70, 70};

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx( gRenderer, surf, clip, &renderQuad, angle, center, flip );
}

void			 Parents::ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend)
{
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
   SDL_RenderCopy(rend, tex, NULL, &pos);
}

SDL_Texture *Parents::LoadImage(std::string file, SDL_Renderer *renderer)
{
	SDL_Surface *loadedImage = nullptr;
	SDL_Texture *texture = nullptr;
	loadedImage = load_image(file.c_str());
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else
		std::cout << SDL_GetError() << std::endl;
	return texture;
}

SDL_Surface		*Parents::load_image(const char *path)
{
	SDL_Surface	*texture;

	texture = IMG_Load(path);
	if (texture == NULL)
	{
			std::cout << "bad load" << std::endl;
			exit(1);
	}
	return (texture);
}