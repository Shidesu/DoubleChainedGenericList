//
// Created by Alexandre on 23/10/2018.
//

#ifndef LISTECHAINEE_LISTECHAINEE_H
#define LISTECHAINEE_LISTECHAINEE_H

#include <stdlib.h>

typedef struct Node Node;

/**
 * A structure representing a node/element of the list.
 */
struct Node {
    /// Pointer to the previous element. NULL if there's none.
    Node *previous;
    /// Pointer to the next element. NULL if there's none.
    Node *next;
    /// Pointer to the data the element is "storing".
    void *data;
};

typedef struct ListeChainee ListeChainee;

/**
 * A structure handling a list and common operations to apply to it.
 */
struct ListeChainee {
    
    /// Size of the list.
    size_t size;
    /// Pointer to the head of the list.
    Node *head;
    /// Pointer to the tail of the list.
    Node *tail;
    /// An array of pointers to the nodes of the list.
    Node **adresses;
    
    
    /**
     * blabla
     *
     * @param listeChainee truc
     * @param data         MUCHE
     */
    void (*addToTail)(ListeChainee *listeChainee, void *data);
    
    /**
     * Add the given data to the head of the list. Previous head is
     * conserved and deplaced from one index.
     *
     * @param listeChainee A pointer to the list to edit.
     * @param data         Data to add to the list.
     */
    void (*addToHead)(ListeChainee *listeChainee, void *data);
    
    /**
     * Insert the given data at the given index of the list.
     * It's creating a new node, not replacing the old one.
     * The old one is moved from
     *
     * @param listeChainee A pointer to the list to edit.
     * @param data         Data to add at given index.
     * @param index        Index where the data should be added.
     */
    void (*insertAt)(ListeChainee *listeChainee, void *data, int index);
    
    /**
     * Get all the elements from the list and pass them to the given function.
     *
     * @param listeChainee A pointer to the list to get data from
     * @param function     The function to apply to the data.
     */
    void (*getAll)(ListeChainee *listeChainee, void(*function)(void *values[], int size));
    
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
    
    /**
     * Don't use it. Not done.
     *
     * @param listeChainee
     */
    void (*clear)(ListeChainee *listeChainee);
    
    /**
     * Get the element at the given index from the list.
     *
     * @param listeChainee A pointer to the list that contains your data/
     * @param index        Index of the element you want to get.
     * @return             A pointer to the retrieved element or NULL if not found.
     */
    Node *(*get)(ListeChainee *listeChainee, int index);
    
    /**
     * Set the value of the given index to the new value passed to the function.
     *
     * @param listeChainee A pointer to the list to edit.
     * @param index        Index of the value to set.
     * @param value        New value to set.
     */
    void (*set)(ListeChainee *listeChainee, int index, void *value);
    
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
