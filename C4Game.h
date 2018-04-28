// C4Game.h
// Created by Alistair Parkinson
// 28/4/2018

#define NUM_COLUMNS 7
#define NUM_ROWS 6

typedef struct _c4Game *C4Game;

C4Game newC4Game (char player1, char player2);

void showGame (C4Game game);

int hasSpace (C4Game game, int column);

void dropIntoColumn (C4Game game, int column);
