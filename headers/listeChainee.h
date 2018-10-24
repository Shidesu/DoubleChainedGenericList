//
// Created by Alexandre on 23/10/2018.
//

#ifndef LISTECHAINEE_LISTECHAINEE_H
#define LISTECHAINEE_LISTECHAINEE_H

#include <stdlib.h>

typedef struct Node Node;
struct Node {
    Node *previous;
    Node *next;
    void *data;
};

typedef struct ListeChainee ListeChainee;

struct ListeChainee {
    size_t size;
    Node *head;
    Node *tail;
    Node **adresses;

    void (*addToTail)(ListeChainee *listeChainee, void *data);

    void (*addToHead)(ListeChainee *listeChainee, void *data);

    void (*insertAt)(ListeChainee *listeChainee, void *data, int index);

    void (*getAll)(ListeChainee *listeChainee, void (*function)(void *values[], int size));

    void (*removeAll)(ListeChainee *listeChainee);

    void (*remove)(ListeChainee *listeChainee, Node *node);

    void (*removeAt)(ListeChainee *listeChainee, int index);

    void (*clean)(ListeChainee *listeChainee);

    Node *(*get)(ListeChainee *listeChainee, int index);
};

void initialiseList(ListeChainee *listeChainee);

void printIntValues(void *values[], int size);

void printFloatValues(void *values[], int size);

#endif //LISTECHAINEE_LISTECHAINEE_H
