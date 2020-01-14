#include <stdio.h>
#include <stdlib.h>

#include "global.h"

/**
 * Show the menu to the user.
 */
int menuChoice()
{
    int error = 0;
    int userChoice = 0;

    while (error < 1)
    {
        system("cls");

        printf(R"EOF(
 _______              __      __      __                      __        __
|       \            |  \    |  \    |  \                    |  \      |  \
| $$$$$$$\  ______  _| $$_  _| $$_   | $$  ______    _______ | $$____   \$$  ______
| $$__/ $$ |      \|   $$ \|   $$ \  | $$ /      \  /       \| $$    \ |  \ /      \
| $$    $$  \$$$$$$\\$$$$$$ \$$$$$$  | $$|  $$$$$$\|  $$$$$$$| $$$$$$$\| $$|  $$$$$$\
| $$$$$$$\ /      $$ | $$ __ | $$ __ | $$| $$    $$ \$$    \ | $$  | $$| $$| $$  | $$
| $$__/ $$|  $$$$$$$ | $$|  \| $$|  \| $$| $$$$$$$$ _\$$$$$$\| $$  | $$| $$| $$__/ $$
| $$    $$ \$$    $$  \$$  $$ \$$  $$| $$ \$$     \|       $$| $$  | $$| $$| $$    $$
 \$$$$$$$   \$$$$$$$   \$$$$   \$$$$  \$$  \$$$$$$$ \$$$$$$$  \$$   \$$ \$$| $$$$$$$
                                                                           | $$
                                                                           | $$
                                                                            \$$
)EOF");
        printf("\n\n");

        printf(R"EOF(

   __              _______   __
 _/  \            |       \ |  \
|   $$            | $$$$$$$\| $$  ______   __    __
 \$$$$            | $$__/ $$| $$ |      \ |  \  |  \
  | $$            | $$    $$| $$  \$$$$$$\| $$  | $$
  | $$            | $$$$$$$ | $$ /      $$| $$  | $$
 _| $$_  __       | $$      | $$|  $$$$$$$| $$__/ $$
|   $$ \|  \      | $$      | $$ \$$    $$ \$$    $$
 \$$$$$$ \$$       \$$       \$$  \$$$$$$$ _\$$$$$$$
                                          |  \__| $$
                                           \$$    $$
                                            \$$$$$$

        )EOF");
        printf("\n");

        printf(R"EOF(
  ______             __    __            __
 /      \           /  |  /  |          /  |
/$$$$$$  |          $$ |  $$ |  ______  $$ |  ______
$$____$$ |          $$ |__$$ | /      \ $$ | /      \
 /    $$/           $$    $$ |/$$$$$$  |$$ |/$$$$$$  |
/$$$$$$/            $$$$$$$$ |$$    $$ |$$ |$$ |  $$ |
$$ |_____  __       $$ |  $$ |$$$$$$$$/ $$ |$$ |__$$ |
$$       |/  |      $$ |  $$ |$$       |$$ |$$    $$/
$$$$$$$$/ $$/       $$/   $$/  $$$$$$$/ $$/ $$$$$$$/
                                            $$ |
                                            $$ |
                                            $$/
)EOF");
        printf("\n");

        printf(R"EOF(
  ______             ______             __    __
 /      \           /      \           /  |  /  |
/$$$$$$  |         /$$$$$$  | __    __ $$/  _$$ |_
$$ ___$$ |         $$ |  $$ |/  |  /  |/  |/ $$   |
  /   $$<          $$ |  $$ |$$ |  $$ |$$ |$$$$$$/
 _$$$$$  |         $$ |_ $$ |$$ |  $$ |$$ |  $$ | __
/  \__$$ |__       $$ / \$$ |$$ \__$$ |$$ |  $$ |/  |
$$    $$//  |      $$ $$ $$< $$    $$/ $$ |  $$  $$/
 $$$$$$/ $$/        $$$$$$  | $$$$$$/  $$/    $$$$/
                        $$$/


)EOF");
        printf("\n");
        fflush(stdin);
        error = scanf("%d", &userChoice);
        if (userChoice < MIN_NUMBER_MENU || userChoice > MAX_NUMBER_MENU)
        {
            error = 0;
        }
    }

    return userChoice;
}

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
