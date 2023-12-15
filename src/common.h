#ifndef COMMON_H
#define COMMON_H
#include <SDL.h>

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
} Color;

Color rand_color() {
    return (Color){.r = rand() % 255, .g = rand() % 255, .b = rand() % 255};
}

#endif // COMMON_H

