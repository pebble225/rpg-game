#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <windows.h>

#include "../include/imgdata.h"

/*

Notes about VS config will go here!



*/

#ifdef _DEBUG

void CloseConsole()
{
	std::cout << "Running in debug mode. Console active." << std::endl;
}

#else

void CloseConsole()
{
	FreeConsole();
}

#endif

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
	CloseConsole();

	int bootState = SDL_Init(SDL_INIT_EVERYTHING);

	if (bootState < 0)
	{
		std::cout << "SDL failed to initialize." << std::endl;

		return -1;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "SDL image failed to initialize." << std::endl;

		return -1;
	}

	window = SDL_CreateWindow("Window Application",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1600, 900,
		SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "SDL failed to create a window." << std::endl;
		
		return -1;
	}

	buffer = SDL_GetWindowSurface(window);

	g = SDL_CreateRenderer(window, -1, 0);
	
	//imgData::initialize(); //This don't work

	SDL_SetRenderDrawColor(g, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(g);
	SDL_RenderPresent(g);

	while (running)
	{
		input();
	}

	//imgData::uninitialize(); //This don't work either

	SDL_DestroyRenderer(g);
	SDL_FreeSurface(buffer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();

	return 0;
}