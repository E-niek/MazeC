#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include "bitset.h"
#include "random.h"

#define true 1
#define false 0

// typedef uint8_t* bitset;

extern int randomSum;

enum Direction {LEFT, RIGHT, UP, DOWN};

void newMaze();
void generatePath(bitset walls, bitset visited, int cell);
int* directions(bitset visited, int index);
void printMaze(bitset walls);

#endif