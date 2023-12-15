#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "common.h"

// Define screen dimensions
#define FACTOR          120
#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

SDL_Rect **init_display(size_t rows, size_t cols) {
    SDL_Rect **display = NULL;
    display = malloc(rows * sizeof(SDL_Rect*));
    for(int i = 0; i < rows; i++) {
        display[i] = malloc(cols *sizeof(SDL_Rect));
    }

    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            SDL_Rect new_pixel;
            new_pixel.w = SCREEN_WIDTH  / cols+1;
            new_pixel.h = SCREEN_HEIGHT / rows+1;
            new_pixel.x = j * new_pixel.w;
            new_pixel.y = i * new_pixel.h;
            display[i][j] = new_pixel;    
        }
    }

    return display;
}

void refresh_display(SDL_Rect **display, size_t rows, size_t cols, SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
    int count = 0;
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++) {
            if((count % 2) == 0 ) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            }
            SDL_RenderFillRect(renderer, &display[i][j]);   
            count++; 
        }
        count++;
    }
    SDL_RenderPresent(renderer);
}

void destroy_display(SDL_Rect **display, size_t rows, size_t cols) {
    for(int i = 0; i < rows; i++) {
        free(display[i]);
    }
    free(display);
}


int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow
    (
        "8chip", 
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    SDL_Renderer* renderer = SDL_CreateRenderer
    (
        window, 
        -1, 
        SDL_RENDERER_PRESENTVSYNC | 
        SDL_RENDERER_ACCELERATED
    );
    
    // This is the display
    SDL_Rect **display = NULL;
    size_t rows = 32;
    size_t cols = 64;
    display = init_display(rows, cols);

    bool quit = false;

    // Main Loop
    while(!quit) {
            SDL_Event event;
            SDL_PollEvent(&event);
            if(event.type == SDL_QUIT) {
                quit = true;
            }
            refresh_display(display, rows, cols, renderer);
    }

    destroy_display(display, rows, cols);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

