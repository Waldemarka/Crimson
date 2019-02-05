#include "Display.hpp"

int main()
{
	srand(time(NULL));
	Display display(200, 200);
	display.Create_window();
	return 0;
}