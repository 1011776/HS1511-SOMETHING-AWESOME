// C4Game.c
// Created by Alistair Parkinson
// 28/4/2018

#include "C4Game.h"

typedef struct _c4Game {
    char cells[NUM_COLS][NUM_ROWS];
    char turnNumber;
} c4Game;

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
    new->turnNumber = 0;
    return new;
}

char getCell (C4Game game, int col, int row) {
    assert (col >= 0);
    assert (col < NUM_COLS);
    assert (row >= 0);
    assert (row < NUM_ROWS);

    return game->cells[col][row];
}

int getTurnNumber (C4Game game) {
    return game->turnNumber;
}

char whoseTurn (C4Game game) {
    assert (getTurnNumber >= 0);

    char turn;
    if (getTurnNumber (game) % 2 == 0) {
        turn = PLAYER_1;
    } else {
        turn = PLAYER_2;
    }
    return turn;
}

int hasSpace (C4Game game, int col) {
    assert (col >= 0);
    assert (col < NUM_COLS);
    
    int output;
    if (getCell (game, col, NUM_ROWS - 1) == EMPTY_CELL) {
        output = TRUE;
    } else {
        output = FALSE;
    }
    return output;
}

void dropIntoColumn (C4Game game, int col) {
    assert (col >= 0);
    assert (col < NUM_COLS);
    assert (hasSpace (game, col));

    int i = 0;
    while (getCell (game, col, i) != ' ') {
        i++;
    } 
    
    game->cells[col][i] = whoseTurn (game);
    game->turnNumber++;
}

int getState (C4Game game) {
    int state;

    
    int i = 0;
    int count = 0;
    while (i < NUM_COLS) {
        if (hasSpace (game, i)) {
            count++;
        }
        i++;
    }
    if (count == NUM_COLS) {
        state = TIE;
    } else {
        state = GAME_NOT_OVER;
    }

    return state;
}
