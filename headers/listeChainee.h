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

/**
 * A structure handling a list and common operations to apply to it.
 */
struct ListeChainee {
    size_t size;
    Node *head;
    Node *tail;
    Node **adresses;

    void (*addToTail)(ListeChainee *listeChainee, void *data);

    void (*addToHead)(ListeChainee *listeChainee, void *data);

    void (*insertAt)(ListeChainee *listeChainee, void *data, int index);

    void (*getAll)(ListeChainee *listeChainee, void (*function)(void *values[], int size));

    /**
     * Remove all the elements from the list.
     *
     * @param listeChainee  A pointer to the list to edit.
     */

    void (*removeAll)(ListeChainee *listeChainee);

    /**
     * Remove the given element from the list.
     *
     * @param listeChainee  A pointer to the list to edit.
     * @param node          Pointer to the node you want to remove.
     */

    void (*remove)(ListeChainee *listeChainee, Node *node);

    /**
     * Remove the element at given index from the list.
     *
     * @param listeChainee  A pointer to the list to edit.
     * @param index         Index of the value you want to remove.
     */
    void (*removeAt)(ListeChainee *listeChainee, int index);

    void (*clean)(ListeChainee *listeChainee);

    /**
     *
     * Get the element at the given index from the list.
     *
     * @param listeChainee A pointer to the list that contains your data/
     * @param index        Index of the element you want to get.
     * @return             A pointer to the retrieved element or NULL if not found.
     */
    Node *(*get)(ListeChainee *listeChainee, int index);
};

/**
 * Initializing the list.
 *
 * @param listeChainee The chained list to initialize.
 */

void initializeList(ListeChainee *listeChainee);

/**
 * A function to consider the generic pointed data as integers
 * and then printing it on the console.
 *
 * @param values  An array of generic pointers.
 * @param size    Size of the array.
 */

void printIntValues(void *values[], int size);

void printFloatValues(void *values[], int size);

#endif //LISTECHAINEE_LISTECHAINEE_H
