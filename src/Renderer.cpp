#include "Renderer.hpp"

Renderer::Renderer(){}
Renderer::~Renderer(){}

Renderer::Renderer(int x, int y)
{
	_x = x;
	_y = y;
	_width = 600;
	_height = 600;
	_start_x = 0;
	_start_y = 0;
	_angle_bott = 0;
	init_lib();
}

void			Renderer::load_all()
{
	_back = parent.load_image("./media/back.png");
	_enemy = parent.load_image("./media/sprite.png");
	_image[0] = parent.LoadImage("./media/niz.png", renderer);
	_image[1] = parent.LoadImage("./media/verh.png", renderer);
	_decor[0] = parent.LoadImage("./media/decor/1.png", renderer);
	_decor[1] = parent.LoadImage("./media/decor/2.png", renderer);
	_decor[2] = parent.LoadImage("./media/decor/3.png", renderer);
	_decor[3] = parent.LoadImage("./media/decor/4.png", renderer);
	_decor[4] = parent.LoadImage("./media/decor/5.png", renderer);
	_decor[5] = parent.LoadImage("./media/decor/6.png", renderer);
	_decor[6] = parent.LoadImage("./media/decor/7.png", renderer);
	_decor[7] = parent.LoadImage("./media/decor/8.png", renderer);
	_decor[8] = parent.LoadImage("./media/decor/9.png", renderer);
}



void			Renderer::init_lib()
{
	if ((window = SDL_CreateWindow("Crimson",
		_x, _y, _width, _height, SDL_WINDOW_RESIZABLE)))
			if ((renderer = SDL_CreateRenderer(window, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
					if ((texture = SDL_CreateTexture(renderer,
						SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, _width, _height)))
					{
						std::cout << "It works!! " << std::endl;
					}
	int q = -1;
	while (++q < _width)
	{
		int i = -1;
		while (++i < _height)
		{
			buf[q][i] = 130000;
		}
	}
	load_all();
}

void			Renderer::mouse()
{
	SDL_PumpEvents();
	int x, y;
	CalcVector *vect = new CalcVector();
	SDL_GetMouseState(&x, &y);
	_angle = vect->angle(x - _width / 2, y - _height /2, _width / 2, 0);
	delete	vect;

}

bool			Renderer::touch_decor(int x, int y)
{
	for(int i = 0; i < 40; i++)
	{
		if (decor[i].get_flag() && decor[i].is_touch(_start_x + x, _start_y + y))
		{
			return (true);
			//printf("%d\n", i);
		}
	}
	return (false);
}

bool			Renderer::key_event()
{
	SDL_Event	event;
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return (true);
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			return (true);
	}
	if (keys[SDL_SCANCODE_W] && _start_y > 0 && !touch_decor(0, -2))
	{
		_start_y -= 2;
		_angle_bott = 180;
	}
	if (keys[SDL_SCANCODE_S] && _start_y < 2400 && !touch_decor(0, 2))
	{
		_start_y += 2;
		_angle_bott = 0;
	}
	if (keys[SDL_SCANCODE_A] && _start_x > 60 && !touch_decor(-2, 0))
	{
		_start_x -= 2;
		_angle_bott = 90;
	}
	if (keys[SDL_SCANCODE_D] && _start_x < 2400 && !touch_decor(2, 0))
	{
		_start_x += 2;
		_angle_bott = 270;
	}
	if (keys[SDL_SCANCODE_W] && keys[SDL_SCANCODE_A]
		&& _start_y > 0 && _start_x > 60)
		_angle_bott = 135;
	if (keys[SDL_SCANCODE_W] && keys[SDL_SCANCODE_D]
		&& _start_y > 0 && _start_x < 2400)
		_angle_bott = 225;
	if (keys[SDL_SCANCODE_S] && keys[SDL_SCANCODE_A]
		&& _start_y < 2400 && _start_x > 60)
		_angle_bott = 45;
	if (keys[SDL_SCANCODE_S] && keys[SDL_SCANCODE_D]
		&& _start_y < 2400 && _start_x < 2400)
		_angle_bott = 315;
	mouse();
	return (false);
}

void			Renderer::decor_draw()
{
	int q = -1;
	while (++q < 40)
	{
		decor[q].set_flag(_start_x, _start_y);
		if (q < 40 && decor[q].get_flag() == true)
		{
			parent.ApplySurface(decor[q].get_pos_x() - _start_x, decor[q].get_pos_y() - _start_y,
				_decor[decor[q].get_num_texture()],renderer);
		}
	}
}

void			Renderer::enemy_draw()
{
	int q = -1;
	while (++q < 80)
	{
		enemy[q].set_flag(_start_x, _start_y);
		if (enemy[q].get_flag() == true)
		{
			//enemy[q].change_pos(_start_x, _start_y);
			enemy[q].draw_enemy(buf, _start_x, _start_y, _enemy);
		}
	}
}

void			Renderer::enemy_alive()
{
	enemy = new Enemy[80];
	decor = new Decor[40];
	int q = -1;
	while (++q < 80)
	{
		enemy[q].alive();
		enemy[q].set_flag(_start_x, _start_y);
		if (q < 40)
		{
			decor[q].alive();
			decor[q].set_flag(_start_x, _start_y);
		}
	}
}

void			Renderer::game()
{
	bool q;

	q = true;
	enemy_alive();	
	SDL_RendererFlip flipType = SDL_FLIP_VERTICAL;
	while (q == true)
	{
		if (key_event() == true)
			q = false;
		parent.put_picture(_back, buf, _start_x, _start_y);
		enemy_draw();
		SDL_UpdateTexture(texture, NULL, buf, _width << 2);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		parent.fliping(278, 258, NULL, _angle_bott, NULL, flipType, _image[0], renderer);
		parent.fliping(278, 258, NULL, _angle, NULL, flipType, _image[1], renderer);
		decor_draw();
		SDL_RenderPresent(renderer);
	}
	system ("leaks crimson");
}














