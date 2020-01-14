#include <stdio.h>
#include <stdlib.h>

#include "global.h"

// GLOBAL ARRAYS
int gridColumn[] = COLUMNS;
int gridRow[] = ROWS;
int gridArray[GRID_COLUMNS][GRID_ROWS];
int gridArrayAi[GRID_COLUMNS][GRID_ROWS];

// AI POSITION
int positionXAi = 0;
int positionYAi = 0;

int baseGridArray[GRID_COLUMNS][GRID_ROWS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

/**
 * Render the grid.
 */
void renderGrid()
{
    int iterativeI = 0;
    int iterativeJ = 0;
    int iterativeK = 0;

    system("cls");

    printf("  ");
    for (iterativeK = 0; iterativeK < GRID_COLUMNS; iterativeK++)
    {
        printf("%d ", gridColumn[iterativeK]);
    }

    printf("\n");

    for (iterativeI = 0; iterativeI < GRID_COLUMNS; iterativeI++)
    {

        printf("%d ", gridRow[iterativeI]);
        for (iterativeJ = 0; iterativeJ < GRID_ROWS; iterativeJ++)
        {
            if (gridArray[iterativeI][iterativeJ] == GRID_NULL || gridArray[iterativeI][iterativeJ] == GRID_BOAT)
            {
                printf(GRID_UNKNOWN);
            }
            if (gridArray[iterativeI][iterativeJ] == 2)
            {
                printf(GRID_TOUCHED_SUCCESS);
            }
            if (gridArray[iterativeI][iterativeJ] == 3)
            {
                printf(GRID_TOUCHED_FAILURE);
            }
            printf(" ");
        }
        printf("\n");
    }
}

/**
 * Renders the grid of the AI.
 */
void renderAiGrid()
{
    int iterativeI = 0;
    int iterativeJ = 0;
    int iterativeK = 0;

    system("cls");
    printf("  ");
    for (iterativeK = 0; iterativeK < GRID_COLUMNS; iterativeK++)
    {
        printf("%d ", gridColumn[iterativeK]);
    }

    printf("\n");

    for (iterativeI = 0; iterativeI < GRID_COLUMNS; iterativeI++)
    {

        printf("%d ", gridRow[iterativeI]);
        for (iterativeJ = 0; iterativeJ < GRID_ROWS; iterativeJ++)
        {
            if (gridArrayAi[iterativeI][iterativeJ] == GRID_NULL || gridArrayAi[iterativeI][iterativeJ] == GRID_BOAT)
            {
                printf(GRID_UNKNOWN);
            }
            if (gridArrayAi[iterativeI][iterativeJ] == 2)
            {
                printf(GRID_TOUCHED_SUCCESS);
            }
            if (gridArrayAi[iterativeI][iterativeJ] == 3)
            {
                printf(GRID_TOUCHED_FAILURE);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("AI targets position X: %d Y: %d\n", positionXAi, positionYAi);
    system("pause");
}

/**
 * Checks if the AI has shot the user's battleships, if so, the AI shots again.
 */
void shotAi()
{

    srand(time(NULL));

    int continueRandom = 1;
    while (continueRandom)
    {
        positionXAi = rand() % GRID_COLUMNS;
        positionYAi = rand() % GRID_ROWS;
        if (gridArrayAi[positionYAi][positionXAi] != 2 || gridArrayAi[positionYAi][positionXAi] != 3)
        {
            continueRandom = 0;
        }
    }

    if (gridArrayAi[positionYAi][positionXAi] == 1)
    {
        printf("SUCCESS!\n");
        gridArrayAi[positionYAi][positionXAi] = 2;
    }
    if (gridArrayAi[positionYAi][positionXAi] == 0)
    {
        printf("FAILURE!\n");
        gridArrayAi[positionYAi][positionXAi] = 3;
    }
}

/**
 * Fills the grid.
 */
void fillGrid()
{
    int iterativeI = 0;
    int iterativeJ = 0;

    for (iterativeI = 0; iterativeI < GRID_COLUMNS; iterativeI++)
    {
        for (iterativeJ = 0; iterativeJ < GRID_ROWS; iterativeJ++)
        {
            gridArray[iterativeI][iterativeJ] = baseGridArray[iterativeI][iterativeJ];
            gridArrayAi[iterativeI][iterativeJ] = baseGridArray[iterativeI][iterativeJ];
        }
    }
}
