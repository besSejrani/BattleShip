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

// POSITIONS
#define MODIFICATION_EXPECTED 2

// DEFINE PLAYER AND AI
#define PLAYER 1
#define AI 2

// PLAYER POSITION
int positionX = -1;
int positionY = -1;

int gridArray[GRID_COLUMNS][GRID_ROWS];
int gridArrayAi[GRID_COLUMNS][GRID_ROWS];

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
