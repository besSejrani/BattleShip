/*
* \title: main.c
* \brief: Battleship game in C
* \author: Besjan Sejrani
* \version: 0.1
* \date: 28.01.2020
*/

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "global.h"
#include "game.h"


/**
 * @name main
 * @description Main function, acts like an orchestrator.
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
