#include "Decor.hpp"

Decor::~Decor(){}
Decor::Decor(){}

void	Decor::alive()
{
	set_xy(rand() % 3000, rand() % 3000);
	_in_zone = false;
	_num_text = rand() % 8;
}

int		Decor::get_num_texture()
{
	return this->_num_text;
}

bool	Decor::is_touch(int start_x, int start_y)
{
	int delta_x;
	int delta_y;

	delta_x = (_pos_x + 40) - (start_x + 300);
	delta_y = (_pos_y + 140) - (start_y + 300);
	if (sqrt(delta_x * delta_x + delta_y * delta_y) < 40)
	{
		//printf("%f\n", sqrt(delta_x * delta_x + delta_y * delta_y));
		//printf("-----------TOUCH--------------\n");
		return (true);
	}
	return (false);
}

/*



1) Батьківський клас 
2)	добавтти в декор нумер елемента і вертать це нумер
3) малювати декор
4) рухи по брезенхейму
5) крутить основу танку (якщо 4 сторни 6-)
6) перетаскувати картинку
7) убивать противників запуск (чи пересікають)




*/