#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
	                                      SDL_WINDOW_SHOWN);

	SDL_Renderer* render = SDL_CreateRenderer(window, -1, NULL);

	SDL_SetRenderDrawColor(render, 100, 100, 100, 255);

	SDL_RenderClear(render);

	SDL_RenderPresent(render);

	SDL_Delay(3000);

	return 0;
}
