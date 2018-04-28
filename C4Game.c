// C4Game.c
// Created by Alistair Parkinson
// 28/4/2018

#include "C4Game.h"

typedef struct _c4Game {
    char cells[NUM_COLUMNS][NUM_ROWS]
    char whoseTurn;
    char player1;
    char player2;
} c4Game;


C4Game newC4Game (char player1, char player2) { C4Game game; return game; }

void showGame (C4Game game) {}

int hasSpace (C4Game game, int column) { return 1; }

void dropIntoColumn (C4Game game, int column) {}
