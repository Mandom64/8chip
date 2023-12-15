#ifndef CHIP8_H
#define CHIP8_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MEM_SIZE 4096

typedef struct {
	bool pixel[32][64];
	size_t rows;
	size_t cols;
} Display;

typedef struct {
	int MEM[MEM_SIZE];
	size_t mem_used;
} Memory;

typedef struct {
	uint16_t pc;
	uint16_t I;
	Display disp;
	Memory RAM;
} Chip8;

#endif // CHIP8_H