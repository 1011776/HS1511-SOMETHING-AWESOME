// playC4Game.h
// Created by Alistair Parkinson
// 28/4/2018

#include <stdio.h>
#include <stdlib.h>
#include "C4Game.h"

int main(int argc, char *argv[]) {
    C4Game game = newC4Game();
    showGame(game);
    return EXIT_SUCCESS; 
}
