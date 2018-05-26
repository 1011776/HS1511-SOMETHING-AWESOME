// playC4Game.h
// Created by Alistair Parkinson
// 28/4/2018

#include <stdio.h>
#include <stdlib.h>
#include "C4Game.h"
#include "C4GameAI.h"

void showGame (C4Game game);
void printLine (void);

int main(int argc, char *argv[]) {
    C4Game game = newC4Game();
    int move;
    while (getState (game) == NOT_OVER) {
        showGame (game);
        printf ("  0   1   2   3   4   5   6\n");
        printf ("%c's turn: ", whoseTurn (game));
        scanf ("%d", &move);
        dropIntoColumn (game, move);
        if (getState (game) == 0) {
            showGame (game);
            printf ("  0   1   2   3   4   5   6\n");
            move = miniMax (game, 10); 
            printf ("%c's turn: %d\n", whoseTurn (game), move);
            dropIntoColumn (game, move);
        }
    }
    showGame (game);
    if (getState (game) == PLAYER_1_WINS) {
        printf ("%c WINS!\n", PLAYER_1);
    } else if (getState (game) == PLAYER_2_WINS) {
        printf ("%c WINS!\n", PLAYER_2);
    } else if (getState (game) == TIE) {
        printf ("TIE!\n");
    }
    
    freeC4Game (game);
    return EXIT_SUCCESS; 
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

void printLine (void) {
    int i  = 0;
    while (i < NUM_COLS)
    {
        printf("+---");
        i++;
    }
    printf("+\n");
}
