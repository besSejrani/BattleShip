#ifndef GRID_H
#define GRID_H

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

void renderGrid();
void shotAi();
void fillGrid();

#endif // GRID_H
