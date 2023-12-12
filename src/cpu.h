#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdint.h>

#define RAM_SIZE 4096

typedef struct {
	uint16_t pc;
	uint16_t I;
	
} CPU;

#endif // CPU_H