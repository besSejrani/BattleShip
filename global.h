
#ifndef GLOBAL_H
#define GLOBAL_H

#include "menu.h"
#include "game.h"



// DEFINE PLAYER AND AI
#define PLAYER 1
#define AI 2

// GRID
#define GRID_NULL 0
#define GRID_BOAT 1
#define GRID_BOAT_SUCCESS 2
#define GRID_BOAT_FAILURE 3
#define GRID_UNKNOWN "~"
#define GRID_TOUCHED_SUCCESS "X"
#define GRID_TOUCHED_FAILURE "O"

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


// MENU
#define MAX_NUMBER_MENU 3
#define MIN_NUMBER_MENU 1
#define USER_CHOICE_ONE 1
#define USER_CHOICE_TWO 2
#define USER_CHOICE_THREE 3

// QUIT
#define QUIT_GAME_OPTION_ZERO 0
#define QUIT_GAME_OPTION_ONE 1

// POSITIONS
#define MODIFICATION_EXPECTED 2

// DEFINE PLAYER AND AI
#define PLAYER 1
#define AI 2




#endif // GLOBAL_H
