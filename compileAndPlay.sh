#!/usr/bin/env bash
echo "Compiling game..."
gcc C4GameAI.c C4GameAI.h C4Game.h C4Game.c playC4Game.c -o game
echo "Starting!"
./game
