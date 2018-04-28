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
