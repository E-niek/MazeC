#include "main.h"

unsigned int rows = 5;
unsigned int columns = 5;
char wall = '#';
char path = ' ';

int randomSum = 0;

int main(int argc, char *argv[])
{
    newMaze();

    return 0;
}

void newMaze()
{
    // create a new bitset to store the walls
    int sizeWalls = (int)ceil(rows * columns * 2 + rows + columns / (sizeof(uint8_t) * 8));
    bitset walls = malloc(sizeWalls);
    walls = fillBytes(walls, sizeWalls);

    // create another bitset to store if a cell in the maze is visited
    int sizeVisited = (int)ceil(rows * columns / (sizeof(uint8_t) * 8));
    bitset visited = malloc(sizeVisited);
    visited = emptyBytes(visited, sizeVisited);

    generatePath(walls, visited, 0);
    free(walls);
    free(visited);
    printf("Free memory!\n");
}

/*
cell 1 LEFT = 7
cell 6 LEFT = 18
cell 11 LEFT = 29
cell 16 LEFT = 40
# # # # # # # # # # #
#   #   #   #   #   #
# # # # # # # # # # #
#   #   #   #   #   #
# # # # # # # # # # #
#   #   #   #   #   #
# # # # # # # # # # #
#   #   #   #   #   #
# # # # # # # # # # #
#   #   #   #   #   #
# # # # # # # # # # #
*/

void generatePath(bitset walls, bitset visited, int cell)
{
    int direction = randomArray(directions(visited, cell), directions(visited, cell)[4] - 1, time(0));

    switch(direction)
    {
        case LEFT:
            break;
        case RIGHT:
            break;
        case UP:
            break;
        case DOWN:
            break;
    }

    printMaze(walls);
}

int* directions(bitset visited, int index)
{
    int arrayIndex = 0;
    static int possibleDirections[5];

    if(index % columns != 0 && !readBit(visited, index)){possibleDirections[arrayIndex] = LEFT; arrayIndex++;}
    if((index + 1) % columns != 0 && !readBit(visited, index)){possibleDirections[arrayIndex] = RIGHT; arrayIndex++;}
    if((int)(index - columns) > 0 && !readBit(visited, index)){possibleDirections[arrayIndex] = UP; arrayIndex++;}
    if(index + columns < rows * columns - columns && !readBit(visited, index)){possibleDirections[arrayIndex] = DOWN; arrayIndex++;}

    possibleDirections[4] = arrayIndex;
    return possibleDirections;
}

void printMaze(bitset walls)
{
    int wallIndex = 0;
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            printf("%c %c ", wall, readBit(walls, wallIndex) ? wall : path);
            wallIndex ++;
        }
        printf("%c \n", wall);
        for(int column = 0; column < columns; column++)
        {
            printf("%c %c ", readBit(walls, wallIndex) ? wall : path, path);
            wallIndex ++;
        }
        printf("%c \n", readBit(walls, wallIndex) ? wall : path);
        wallIndex ++;
    }
    for(int column = 0; column < columns; column++)
    {
        printf("%c %c ", wall, readBit(walls, wallIndex) ? wall : path);
        wallIndex ++;
    }
    printf("%c \n", wall);
}