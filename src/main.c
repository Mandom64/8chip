#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>

// Define screen dimensions
#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

SDL_Window *gWindow = NULL;
SDL_Surface *gSurface = NULL;

int main(int argc, char **argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("[ERROR]: SDL_Init failed with error code %s\n", SDL_GetError());
		return EXIT_FAILURE;
	} else {
		gWindow = SDL_CreateWindow(
			"8Chip", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, 
			SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN);
		
		if(gWindow == NULL) {
			printf("[ERROR]: SDL_CreateWindow failed with error code %s\n", SDL_GetError());
			return EXIT_FAILURE;
		} else {
			gSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	SDL_Event event;
	bool quit = false;

	while(!quit) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					quit = true;
					break;
			}
		}
		
	}

	return EXIT_SUCCESS;
}