// C4Game.h
// Created by Alistair Parkinson
// 28/4/2018

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define NOT_OVER 0
#define PLAYER_1_WINS 1
#define PLAYER_2_WINS 2
#define TIE 3

#define CONNECT_TO_WIN 4
#define NUM_COLS 7
#define NUM_ROWS 6
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY_CELL ' '

typedef struct _c4Game *C4Game;

C4Game newC4Game (void);

C4Game copyC4Game (C4Game game);

void freeC4Game (C4Game game);

char getCell (C4Game game, int col, int row);

int turnNumber (C4Game game);

char whoseTurn (C4Game game);

int hasSpace (C4Game game, int column);

void dropIntoColumn (C4Game game, int column);

int getState (C4Game game);

int hasWon (C4Game game, char player);
