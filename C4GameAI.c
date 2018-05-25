// playC4Game.c
// Created by Alistair Parkinson
// 25/5/2018

#include "C4GameAI.h"

void mrPass (C4Game game) {
    int move;
    int i = 0;
    while(i < NUM_COLS) {
        if (hasSpace (game, i)) {
            move = i;
        }
        i++;
    }
    dropIntoColumn (game, move);
}

void miniMax (C4Game game, int depth) {

}
