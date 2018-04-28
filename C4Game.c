// C4Game.c
// Created by Alistair Parkinson
// 28/4/2018

#include "C4Game.h"

typedef struct _c4Game {
    char cells[NUM_COLS][NUM_ROWS];
    char whoseTurn;
} c4Game;

static void switchTurns (C4Game game);
static void printLine (void);

C4Game newC4Game (void) { 
    C4Game new = malloc (sizeof (c4Game));
    assert (new != NULL);
    int i = 0;
    while (i < NUM_COLS) {
        int j = 0;
        while (j < NUM_ROWS) {
            new->cells[i][j] = EMPTY_CELL;
            j++;
        }
        i++;
    }
    new->whoseTurn = PLAYER_1;
    return new;
}

void showGame (C4Game game) {
    int row = NUM_ROWS - 1;
    while (row >= 0) { 
        printLine ();
        int col = 0;
        while (col < NUM_COLS) {
            printf ("| %c ", getCell (game, col, row));
            col++;
        }
        printf ("|\n");
        row--;
    }
    printLine ();
}

char getCell (C4Game game, int col, int row) {
    assert (col >= 0);
    assert (col < NUM_COLS);
    assert (row >= 0);
    assert (row < NUM_ROWS);

    return game->cells[col][row];
}

char whoseTurn (C4Game game) {
    return game->whoseTurn; 
}

int hasSpace (C4Game game, int col) {
    assert (col >= 0);
    assert (col < NUM_COLS);
    int output;
    if (game->cells[col][NUM_ROWS - 1] == EMPTY_CELL) {
        output = TRUE;
    } else {
        output = FALSE;
    }
    return output;
}

void dropIntoColumn (C4Game game, int col) {
    
}

static void switchTurns (C4Game game) {
    assert (whoseTurn (game) == PLAYER_1 
        || whoseTurn (game) == PLAYER_2);
    if (game->whoseTurn == PLAYER_1) {
        game->whoseTurn = PLAYER_2;
    } else {
        game->whoseTurn = PLAYER_1;
    }
}

static void printLine (void) {
    int i  = 0;
    while (i < NUM_COLS)
    {
        printf("+---");
        i++;
    }
    printf("+\n");
}
