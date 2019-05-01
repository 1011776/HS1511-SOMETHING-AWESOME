# How To Play:
If you want to recompile the source on run, use `./compileAndPlay.sh`
If you just want to play the game, you can execute `./play.sh` or `./game` NOTE: There must be an executable called "game" for this code to work

# TODO:
1. Create header for game
2. Create game struct in C4Game.c
3. Write tests for testC4Game.c
4. Write the game
5. Make it playable for two human players
6. Create a mrPass.c
7. Improve AI 

User Interface Idea:
```
          CONNECT 4
          
+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+
|   |   | X |   |   |   |   |
+---+---+---+---+---+---+---+
| O | X | O | X | O | X |   |
+---+---+---+---+---+---+---+
| O | O | O | X | X | O |   |
+---+---+---+---+---+---+---+
| O | X | X | O | O | X |   |
+---+---+---+---+---+---+---+
| X | O | O | X | X | X | O |
+---+---+---+---+---+---+---+

  0   1   2   3   4   5   6  
```
