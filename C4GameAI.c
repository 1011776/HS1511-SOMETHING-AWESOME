// playC4Game.c
// Created by Alistair Parkinson
// 25/5/2018

#include <assert.h>
#include "C4GameAI.h"

typedef struct _node *link;

typedef struct _node {
    C4Game game;
    int state;
    link childNodes[NUM_COLS];
} node;

static void generateChildNodes (node *parentNode);
static void generateToDepth (node *parentNode, int depth);
static void updateStates (node *parentNode);
static void freeNode (node *parentNode);

int mrPass (C4Game game) {
    assert (getState (game) == NOT_OVER);

    int move;
    int i = 0;
    while(i < NUM_COLS) {
        if (hasSpace (game, i)) {
            move = i;
        }
        i++;
    }
    return move;
}

int miniMax (C4Game game, int depth) {
    assert (getState (game) == NOT_OVER); 

    link head = malloc (sizeof (node));
    head->game = copyC4Game (game);
    head->state = NOT_OVER;
    generateToDepth (head, depth);
    updateStates (head);
    freeNode (head);
 
    return (mrPass (game));  
}

static void generateChildNodes (node *parentNode) { 
    assert (parentNode->state == NOT_OVER);
    int i = 0;
    while (i < NUM_COLS) {
        if (hasSpace (parentNode->game, i)) {
            link new = malloc (sizeof (node));
            new->game = copyC4Game (parentNode->game);
            dropIntoColumn(new->game, i);
            new->state = getState (new->game);
            parentNode->childNodes[i] = new;
        } else {
            parentNode->childNodes[i] = NULL;
        }
        i++;
    }
}

static void generateToDepth (node *parentNode, int depth) {
    assert (depth >= 0);    

    if (depth != 0 && parentNode->state == NOT_OVER) {
        generateChildNodes (parentNode);
        int i = 0;
        while (i < NUM_COLS) {
            generateToDepth(parentNode->childNodes[i], depth - 1);
            i++;
        }
    }
}

static void updateStates (node *parentNode) { 
    int turn = whoseTurn (parentNode->game);
    if (turn == PLAYER_1) {    
        parentNode->state = PLAYER_2_WINS;
    } else {
        parentNode->state = PLAYER_1_WINS;
    }

    int i = 0;
    while (i < NUM_COLS) {
        if(parentNode->childNodes[i] != NULL) {
            if (parentNode->childNodes[i]->state == NOT_OVER) {
                updateStates (parentNode->childNodes[i]);
            }
            
            // Check for win
            if (parentNode->state 
                == PLAYER_1_WINS && turn == PLAYER_1) {
                    parentNode->state = PLAYER_1_WINS;
            } else if (parentNode->childNodes[i]->state 
                == PLAYER_2_WINS && turn == PLAYER_2) {
                    parentNode->state = PLAYER_2_WINS;
            }

            // Check for tie or not over
            if ((parentNode->state == PLAYER_1_WINS 
                && turn == PLAYER_2)
                || (parentNode->state == PLAYER_2_WINS 
                && turn == PLAYER_1)) {
                if (parentNode->childNodes[i]->state == NOT_OVER) {
                    parentNode->state = NOT_OVER;
                } else if (parentNode->childNodes[i]->state == TIE) {
                    parentNode->state = TIE;
                }
            }
        }
        i++;
    }
}

static void freeNode (node *nodeToFree) {
    int i = 0;
    freeC4Game (nodeToFree->game);
    while (i < NUM_COLS) {
        if (nodeToFree->childNodes[i] != NULL) {
            freeNode (nodeToFree->childNodes[i]);
            free (nodeToFree->childNodes[i]);
            nodeToFree->childNodes[i] = NULL;
        }
        i++;
    }
}
