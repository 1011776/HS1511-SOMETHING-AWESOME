// C4Game.h
// Created by Alistair Parkinson
// 28/4/2018

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY_CELL ' '
#define NUM_COLS 7
#define NUM_ROWS 6

typedef struct _c4Game *C4Game;

C4Game newC4Game (void);

void showGame (C4Game game);

char getCell (C4Game game, int col, int row);

char whoseTurn (C4Game game);

int hasSpace (C4Game game, int column);

void dropIntoColumn (C4Game game, int column);
