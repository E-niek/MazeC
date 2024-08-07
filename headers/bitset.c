#include "bitset.h"

bitset writeBit(bitset array, int index, int value)
{    
    int biteIndex = index % (sizeof(uint8_t) * 8);
    index = (int)floor(index / (sizeof(uint8_t) * 8));

    if((!value && !readBit(array, index)) || (value && readBit(array, index)))
    {
        return array;
    }else
    {
        (value == false) ? (array[index] = 1 << biteIndex | ~array[index]) : (array[index] = 1 << biteIndex ^ ~array[index]);
        array[index] = ~array[index];
    }

    return array;
}

uint8_t readBit(bitset arrary, int index)
{
    int biteIndex = index % (sizeof(uint8_t) * 8);
    index = (int)floor(index / (sizeof(uint8_t) * 8));

    return (arrary[index] & 1 << biteIndex) != 0 ? true : false;
}

bitset fillBytes(bitset array, int length)
{
    for(int i = 0; i < length; i++)
    {
        array[i] = UINT8_MAX;
    }

    return array;
}

bitset emptyBytes(bitset array, int length)
{
    for(int i = 0; i < length; i++)
    {
        array[i] = 0;
    }

    return array;
}
