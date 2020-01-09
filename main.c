/*
* \title: main.c
* \brief: Battleship game in C
* \author: Besjan Sejrani
* \version: 0.1
* \date: 09.01.2020
*/

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global.h"

// FILL
#define GRID_COLUMNS 10
#define GRID_ROWS 10
#define COLUMNS                      \
    {                                \
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9 \
    }
#define ROWS                         \
    {                                \
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9 \
    }

// POSITIONS
#define MODIFICATION_EXPECTED 2

// GRID
#define GRID_NULL 0
#define GRID_BOAT 1
#define GRID_BOAT_SUCCESS 2
#define GRID_BOAT_FAILURE 3
#define GRID_UNKNOWN "~"
#define GRID_TOUCHED_SUCCESS "X"
#define GRID_TOUCHED_FAILURE "O"

// DEFINE PLAYER AND AI
#define PLAYER 1
#define AI 2

// GLOBAL ARRAYS
int gridColumn[] = COLUMNS;
int gridRow[] = ROWS;
int gridArray[GRID_COLUMNS][GRID_ROWS];
int gridArrayAi[GRID_COLUMNS][GRID_ROWS];

// PLAYER POSITION
int positionX = -1;
int positionY = -1;

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

int gridArray[GRID_COLUMNS][GRID_ROWS];
int gridArrayAi[GRID_COLUMNS][GRID_ROWS];

/**
 * Show the help menu.
 */
void showHelp()
{
    system("cls");
    printf("The battleship game opposes to player against each other.\n"
           "Each player has 5 battleships: 1 aircraft carrier (5 spaces), 1 cruiser (4 spaces), 1 destroyer (3 spaces), 1 submarine (3 spaces), 1 torpedo boat (2 spaces).\n\n"
           "The battleships aren't allowed to be cross positioned.\n"
           "Each player tries to sink the enemy's ships by entering an X value and a Y value.\n\n"
           "We count on you captain !\n\n");
    system("PAUSE");
}

/**
 * Confirms that the user wants to quit the game.
 */
int checkQuit()
{

    int error = 0;
    int userChoice = 0;

    while (error < 1)
    {
        system("cls");
        printf("Do you want to quit the game (0.NO / 1.YES) ?\n");
        fflush(stdin);
        error = scanf("%d", &userChoice);
        if (userChoice < QUIT_GAME_OPTION_ZERO || userChoice > QUIT_GAME_OPTION_ONE)
        {
            error = 0;
        }
    }
    return userChoice;
}

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
 * Ask the coordinates to the user.
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

        if (positionXValueChanged + positionYValueChanged == MODIFICATION_EXPECTED)
        {
            error = 1;
        }
    }
}

/**
 * Check if player's target has been touched.
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
 * Checks if the game is finished.
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
            if (gridArray[iterativeI][iterativeJ] == GRID_BOAT)
            {
                bateauxRestantsJoueur++;
            }
        }
    }

    for (iterativeI = 0; iterativeI < GRID_COLUMNS; iterativeI++)
    {
        for (iterativeJ = 0; iterativeJ < GRID_ROWS; iterativeJ++)
        {
            if (gridArrayAi[iterativeI][iterativeJ] == GRID_BOAT)
            {
                bateauxRestantsIA++;
            }
        }
    }

    if (bateauxRestantsJoueur == 0)
    {
        winner = PLAYER;
    }

    if (bateauxRestantsIA == 0)
    {
        winner = AI;
    }

    if (bateauxRestantsIA > 0 && bateauxRestantsJoueur > 0)
    {
        winner = 0;
    }

    return winner;
}

/**
 * Call all this functions to guarantee the AI's turn.
 */
void aiPlays()
{
    shotAi();
    renderAiGrid();
}

/**
 * Call all this functions to guarantee the player's turn.
 */
void playerPlays()
{
    renderGrid();
    askPosition();
    checkTouched();
    renderGrid();
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

/**
 * Prints to the user a success or failure message.
 */
void showWinner(int gameInProgress)
{
    if (gameInProgress == 1)
    {
        printf("YOU WON!");
    }
    else
    {
        printf("LOOSER!");
    }
    system("pause");
}

/**
 * Check if it's the player's turn of the AI.
 */
void checkTurnGame()
{
    int turn = 1;
    int gameInProgress = 1;
    int winner = 0;

    fillGrid();

    while (gameInProgress)
    {

        if (turn % 2 == 1)
        {
            playerPlays();
        }
        if (turn % 2 == 0)
        {
            aiPlays();
        }
        winner = checkFinish();
        turn++;
        if (winner == PLAYER || winner == AI)
        {
            gameInProgress = 0;
        }
    }
    showWinner(winner);
}

/**
 * Main function, acts like an orchestrator.
 */
int main()
{
    int quit = 0;

    while (quit == 0)
    {
        int userChoice = 0;

        userChoice = menuChoice();

        switch (userChoice)
        {

        case USER_CHOICE_ONE:
            checkTurnGame();
            break;

        case USER_CHOICE_TWO:
            showHelp();
            break;

        case USER_CHOICE_THREE:
            quit = checkQuit();
            break;

        default:
            break;
        }
    }

    return 0;
}
