#ifndef BITSET_H
#define BITSET_H

#include <math.h>
#include <stdint.h>

#define true 1
#define false 0

typedef uint8_t* bitset;

bitset writeBit(bitset array, int index, int value);
uint8_t readBit(bitset arrary, int index);
bitset fillBytes(bitset array, int length);
bitset emptyBytes(bitset array, int length);

#endif