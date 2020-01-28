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


// PLAYER POSITION
int positionX = -1;
int positionY = -1;

int gridArray[GRID_COLUMNS][GRID_ROWS];
int gridArrayAi[GRID_COLUMNS][GRID_ROWS];


int baseGridArray[GRID_COLUMNS][GRID_ROWS] = {
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/**
 * @name renderGrid
 * @description Render the grid.
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

            gridArray[iterativeI][iterativeJ] == GRID_NULL || gridArray[iterativeI][iterativeJ] == GRID_BOAT ? printf(GRID_UNKNOWN): "";

            gridArray[iterativeI][iterativeJ] == 2 ? printf(GRID_TOUCHED_SUCCESS): "";

            gridArray[iterativeI][iterativeJ] == 3 ? printf(GRID_TOUCHED_FAILURE): "";

            printf(" ");
        }
        printf("\n");
    }
}

/**
 * @name renderAiGrid
 * @description Renders the grid of the AI.
 */
void renderAiGrid()
{
    int iterativeI = 0;
    int iterativeJ = 0;
    int iterativeK = 0;

    system("cls");
    printf("  ");

    iterativeK = 0; iterativeK < GRID_COLUMNS; iterativeK++ ? printf("%d ", gridColumn[iterativeK]): "";
    printf("\n");

    for (iterativeI = 0; iterativeI < GRID_COLUMNS; iterativeI++)
    {
        printf("%d ", gridRow[iterativeI]);

        for (iterativeJ = 0; iterativeJ < GRID_ROWS; iterativeJ++)
        {

            gridArrayAi[iterativeI][iterativeJ] == GRID_NULL || gridArrayAi[iterativeI][iterativeJ] == GRID_BOAT ?  printf(GRID_UNKNOWN):"";

            gridArrayAi[iterativeI][iterativeJ] == 2 ? printf(GRID_TOUCHED_SUCCESS) : "";

            gridArrayAi[iterativeI][iterativeJ] == 3 ? printf(GRID_TOUCHED_FAILURE): "";

            printf(" ");
        }
        printf("\n");
    }
    printf("AI targets position X: %d Y: %d\n", positionXAi, positionYAi);
    system("pause");
}

/**
 * @name shotAi
 * @description Checks if the AI has shot the user's battleships, if so, the AI shots again.
 */
void shotAi()
{
    srand(time(NULL));
    int continueRandom = 1;

    while (continueRandom)
    {
        positionXAi = rand() % GRID_COLUMNS;
        positionYAi = rand() % GRID_ROWS;

        gridArrayAi[positionYAi][positionXAi] != 2 || gridArrayAi[positionYAi][positionXAi] != 3 ? continueRandom = 0 : "";

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
 * @name fillGrid
 * @description Fills the grid.
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

/**
 * @name askPosition
 * @description Ask the coordinates to the user.
 */
void askPosition()
{
    int positionXValueChanged = 0;
    int positionYValueChanged = 0;
    int error = 0;

    while (error != 1)
    {
        fflush(stdin);
        printf("Position X: ");
        positionXValueChanged = scanf("%d", &positionX);

        fflush(stdin);
        printf("Position Y: ");
        positionYValueChanged = scanf("%d", &positionY);

        positionXValueChanged + positionYValueChanged == MODIFICATION_EXPECTED ? error = 1 : "";

    }
}



/**
 * @name checkTouched
 * @description Check if player's target has been touched.
 */
void checkTouched()
{

    if (positionX != -1 && positionY != -1)
    {
        if (gridArray[positionY][positionX] == 2 || gridArray[positionY][positionX] == 3)
        {
            printf("You have already targeted this position.\n");
        }

        if (gridArray[positionY][positionX] == 1)
        {
            printf("SUCCESS!\n");
            gridArray[positionY][positionX] = 2;
        }

        if (gridArray[positionY][positionX] == 0)
        {
            printf("FAILURE!\n");
            gridArray[positionY][positionX] = 3;
        }

        positionX = -1;
        positionY = -1;
    }
}


/**
 * @name aiPlays
 * @description Call all this functions to guarantee the AI's turn.
 */
void aiPlays()
{
    shotAi();
    renderAiGrid();
}


/**
 * @name playerPlays
 * @description Call all this functions to guarantee the player's turn.
 */
void playerPlays()
{
    renderGrid();
    askPosition();
    checkTouched();
    renderGrid();
}

/**
 * @name checkFinish
 * @description Checks if the game is finished.
 */
int checkFinish()
{
    int iterativeI = 0;
    int iterativeJ = 0;

    int bateauxRestantsJoueur = 0;
    int bateauxRestantsIA = 0;
    int winner = 0;

    for (iterativeI = 0; iterativeI < GRID_COLUMNS; iterativeI++)
    {
        for (iterativeJ = 0; iterativeJ < GRID_ROWS; iterativeJ++)
        {
            gridArray[iterativeI][iterativeJ] == GRID_BOAT ? bateauxRestantsJoueur++ : "";
        }
    }

    for (iterativeI = 0; iterativeI < GRID_COLUMNS; iterativeI++)
    {
        for (iterativeJ = 0; iterativeJ < GRID_ROWS; iterativeJ++)
        {
            gridArrayAi[iterativeI][iterativeJ] == GRID_BOAT ? bateauxRestantsIA++:"";
        }
    }

    bateauxRestantsJoueur == 0 ? winner = PLAYER : "";
    bateauxRestantsIA == 0 ? winner = AI:"";
    bateauxRestantsIA > 0 && bateauxRestantsJoueur > 0 ? winner=0:"";

    return winner;
}

/**
 * @name checkTurnGame
 * @description Check if it's the player's turn of the AI.
 */
void checkTurnGame()
{
    int turn = 1;
    int gameInProgress = 1;
    int winner = 0;

    fillGrid();

    while (gameInProgress)
    {

     turn %2 == 1 ? playerPlays(): "";
     turn %2 == 0 ? aiPlays(): "";

     winner = checkFinish();
     turn++;

     winner == PLAYER || winner == AI ? gameInProgress = 0 : "";
    }

    showWinner(winner);
}

/**
 * @name showWinner
 * @description Prints to the user a success or failure message.
 */
void showWinner(int gameInProgress)
{

    if (gameInProgress == 1)
    {
        printf(R"EOF(
 __      __                         __       __                            __
/  \    /  |                       /  |  _  /  |                          /  |
$$  \  /$$/______   __    __       $$ | / \ $$ |  ______   _______        $$ |
 $$  \/$$//      \ /  |  /  |      $$ |/$  \$$ | /      \ /       \       $$ |
  $$  $$//$$$$$$  |$$ |  $$ |      $$ /$$$  $$ |/$$$$$$  |$$$$$$$  |      $$ |
   $$$$/ $$ |  $$ |$$ |  $$ |      $$ $$/$$ $$ |$$ |  $$ |$$ |  $$ |      $$/
    $$ | $$ \__$$ |$$ \__$$ |      $$$$/  $$$$ |$$ \__$$ |$$ |  $$ |       __
    $$ | $$    $$/ $$    $$/       $$$/    $$$ |$$    $$/ $$ |  $$ |      /  |
    $$/   $$$$$$/   $$$$$$/        $$/      $$/  $$$$$$/  $$/   $$/       $$/



)EOF");

printf("\n");
    }
    else
    {
 printf(R"EOF(
 __      __                         __                              __            __
/  \    /  |                       /  |                            /  |          /  |
$$  \  /$$/______   __    __       $$ |        ______    _______  _$$ |_         $$ |
 $$  \/$$//      \ /  |  /  |      $$ |       /      \  /       |/ $$   |        $$ |
  $$  $$//$$$$$$  |$$ |  $$ |      $$ |      /$$$$$$  |/$$$$$$$/ $$$$$$/         $$ |
   $$$$/ $$ |  $$ |$$ |  $$ |      $$ |      $$ |  $$ |$$      \   $$ | __       $$/
    $$ | $$ \__$$ |$$ \__$$ |      $$ |_____ $$ \__$$ | $$$$$$  |  $$ |/  |       __
    $$ | $$    $$/ $$    $$/       $$       |$$    $$/ /     $$/   $$  $$/       /  |
    $$/   $$$$$$/   $$$$$$/        $$$$$$$$/  $$$$$$/  $$$$$$$/     $$$$/        $$/


                                                                                    )EOF");

printf("\n");
    }

    system("pause");
}





