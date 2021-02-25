#include <SDL.h>
#include <iostream>

SDL_Window* window;
SDL_Surface* buffer;
SDL_Renderer* g;

bool running = true;

void input()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			running = false;
		}
	}
}

int main(int argc, char* args[])
{
	window = SDL_CreateWindow("Window Application",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1600, 900,
		SDL_WINDOW_SHOWN);

	buffer = SDL_GetWindowSurface(window);

	g = SDL_CreateRenderer(window, -1, 0);
	
	while (running)
	{
		input();
	}

	return 0;
}