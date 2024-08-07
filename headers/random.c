#include "random.h"

int randomArray(int *array, int length, int seed)
{
    // length of array cannot be zero or less, if the user provides that, length will be 1
    length = length <= 0 ? 1 : length;
    srand(seed);
    randomSum ++;

    return array[rand() % (length + 1)];
}

int randomInt(int max, int seed)
{
    srand(seed);
    randomSum ++;

    return rand() % (max + 1);
}
