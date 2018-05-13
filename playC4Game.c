// playC4Game.h
// Created by Alistair Parkinson
// 28/4/2018

#include <stdio.h>
#include <stdlib.h>
#include "C4Game.h"

void showGame (C4Game game);
void printLine (void);

int main(int argc, char *argv[]) {
    C4Game game = newC4Game();
    
    int i = 0;

    while (i < 20) {
        showGame(game);
        i++;
    }

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
