// playC4Game.c
// Created by Alistair Parkinson
// 25/5/2018

#include "C4GameAI.h"

typedef struct _node *link;

typedef struct _node {
    C4Game game;
    int state;
    link childNodes[NUM_COLS];
} node;

static void generateChildNodes (node *parentNode);
static void freeNode (node *parentNode);

int mrPass (C4Game game) {
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
    link head = malloc (sizeof (node));
    head->game = copyC4Game (game);
    head->state = NOT_OVER;
    generateChildNodes (head);
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
