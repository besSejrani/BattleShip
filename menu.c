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