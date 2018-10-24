//
// Created by Kao on 23/10/2018.
//

#include "../headers/listeChainee.h"
#include <stdio.h>

Node *get(ListeChainee *listeChainee, int index);

void addToTail(ListeChainee *listeChainee, void *data);

void addToHead(ListeChainee *listeChainee, void *data);

void insertAt(ListeChainee *listeChainee, void *data, int index);

void getAll(ListeChainee *listeChainee, void(*function)(void *values[], int size));

void clear(ListeChainee *listeChainee);

void removeNode(ListeChainee *listeChainee, Node *node);

void removeNodeAt(ListeChainee *listeChainee, int index);

void clean(ListeChainee *listeChainee);


void addToTail(ListeChainee *listeChainee, void *data) {
    size_t *listSize = &listeChainee->size;
    Node ***adresses = &listeChainee->adresses;
    Node **head = &listeChainee->head;
    Node **tail = &listeChainee->tail;

    Node *temp = calloc(1, sizeof(Node));
    temp->data = data;

    if (*listSize == 0) {
        *head = temp;
        *tail = temp;
        (*listSize)++;
        *adresses = realloc(*adresses, *listSize * sizeof(Node *));
        (*adresses)[*listSize - 1] = temp;
    } else {
        temp->previous = *tail;
        (*tail)->next = temp;
        temp->previous = *tail;
        *tail = temp;
        (*listSize)++;
        *adresses = realloc(*adresses, *listSize * sizeof(Node *));
        (*adresses)[*listSize - 1] = temp;
    }
}

void addToHead(ListeChainee *listeChainee, void *data) {
    size_t *listSize = &listeChainee->size;
    Node ***adresses = &listeChainee->adresses;
    Node **head = &listeChainee->head;
    Node **tail = &listeChainee->tail;

    Node *temp = calloc(1, sizeof(Node));
    temp->data = data;

    for (int i = 0; i < listeChainee->size; i++)
        printf("%zu\n", listeChainee->adresses[i]);


    if (*listSize == 0) {
        *head = temp;
        *tail = temp;
        (*listSize)++;
        *adresses = realloc(*adresses, *listSize * sizeof(Node *));
        (*adresses)[0] = temp;
    } else {
        Node *currentNode = *head;

        temp->next = *head;
        (*head)->previous = temp;
        *head = temp;
        (*listSize)++;
        *adresses = realloc(*adresses, *listSize * sizeof(Node *));
        (*adresses)[0] = temp;

        for (int i = 1; i < *listSize; i++) {
            (*adresses)[i] = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void insertAt(ListeChainee *listeChainee, void *data, int index) {
    Node *temp = calloc(1, sizeof(Node));
    Node *tempBeforeIndex = NULL;
    Node **oldTable = NULL;
    Node *tempIndex = NULL;
    temp->data = data;
    int i;

    if (listeChainee->size < 0 || index > listeChainee->size || index < 0) return;

    oldTable = calloc(listeChainee->size, sizeof(Node *));

    for (int j = 0; j < listeChainee->size; j++) {
        oldTable[j] = listeChainee->adresses[j];
    }

    listeChainee->adresses = realloc(listeChainee->adresses, ++listeChainee->size * sizeof(Node));
    if (index == 0) {
        listeChainee->head = temp;
    } else {
        tempBeforeIndex = listeChainee->adresses[index - 1];
        tempBeforeIndex->next = temp;
    }

    tempIndex = listeChainee->adresses[index];

    tempIndex->previous = temp;
    temp->previous = tempBeforeIndex;
    temp->next = tempIndex;

    for (i = 0; i < index; i++) {
        listeChainee->adresses[i] = oldTable[i];
    }
    i++;
    listeChainee->adresses[i] = temp;

    for (; i < listeChainee->size; i++) {
        listeChainee->adresses[i] = oldTable[i - 1];
    }

    free(oldTable);
}

void getAll(ListeChainee *listeChainee, void(*function)(void *values[], int size)) {
    Node *temp;
    void **values = calloc(0, sizeof(void *));
    int size = 0;

    if (listeChainee->size > 0) {
        temp = listeChainee->head;
        while (temp->next != NULL) {
            size++;
            values = realloc(values, size * sizeof(void *));
            values[size - 1] = temp->data;
            temp = temp->next;
        }
        size++;
        values = realloc(values, size * sizeof(void *));
        values[size - 1] = temp->data;
        (*function)(values, size);
    }
    free(values);
}

void printIntValues(void *values[], int size) {
    printf("Printing values as integers.\n");

    for (int i = 0; i < size; i++) {
        printf("Valeur n›%d : %d\n", i + 1, *(int *) values[i]);
    }

    printf("\n");
}

void printFloatValues(void *values[], int size) {
    printf("Printing values as double.\n");

    for (int i = 0; i < size; i++) {
        printf("Valeur n›%d : %f\n", i + 1, *(float *) values[i]);
    }

    printf("\n");
}

void clear(ListeChainee *listeChainee) {
    Node *temp;
    Node *tempPrev;

    if (listeChainee->size > 0) {
        temp = listeChainee->tail;
        while (temp->previous != NULL) {
            tempPrev = temp->previous;
            free(temp);
            temp = tempPrev;
        }
        free(temp);
        listeChainee->size = 0;
    }
}

void removeNode(ListeChainee *listeChainee, Node *node) {
    Node *tempPrev = NULL, *tempNext = NULL;

    free(node->data);

    if (node->previous != NULL)
        tempPrev = node->previous;
    if (node->next != NULL)
        tempNext = node->next;

    if (tempPrev != NULL)
        tempPrev->next = tempNext;
    else
        listeChainee->head = tempNext;

    if (tempNext != NULL)
        tempNext->previous = tempPrev;
    else
        listeChainee->tail = tempPrev;

    listeChainee->size--;

    free(listeChainee->adresses);

    listeChainee->adresses = calloc(listeChainee->size, sizeof(Node *));

    if (listeChainee->head != NULL) {
        Node *currentNode = listeChainee->head;

        for (int i = 0; i < listeChainee->size; i++) {
            listeChainee->adresses[i] = currentNode;
            currentNode = currentNode->next;
        }
    }

    free(node);
}

void removeNodeAt(ListeChainee *listeChainee, int index) {
    if (index < listeChainee->size) {
        Node *oldTable = calloc(listeChainee->size, sizeof(Node));
        for (int i = 0; i < listeChainee->size; i++) {
            oldTable[i] = *listeChainee->adresses[i];
        }

        Node *node = listeChainee->adresses[index];

        removeNode(listeChainee, node);

        free(oldTable);
    }
}

void removeAll(ListeChainee *listeChainee) {
    for (int i = 0; i < listeChainee->size; i++) {
        removeNodeAt(listeChainee, 0);
    }
    free(listeChainee->adresses);
}

void clean(ListeChainee *listeChainee) {
    int *temp;
    for (int i = 0; i < listeChainee->size; i++) {
        free(listeChainee->adresses[i]->data);
        temp = calloc(1, sizeof(void *));
        *temp = 0;
        listeChainee->adresses[i]->data = temp;
    }
}

void initializeList(ListeChainee *listeChainee) {
    listeChainee->head = NULL;
    listeChainee->tail = NULL;
    listeChainee->size = 0;
    listeChainee->adresses = calloc(0, sizeof(Node *));

    listeChainee->addToTail = addToTail;
    listeChainee->addToHead = addToHead;
    listeChainee->insertAt = insertAt;
    listeChainee->getAll = getAll;
    listeChainee->removeAll = removeAll;
    listeChainee->remove = removeNode;
    listeChainee->removeAt = removeNodeAt;
    listeChainee->clean = clean;
    listeChainee->get = get;
}

Node *get(ListeChainee *listeChainee, int index) {
    if (index < listeChainee->size)
        return listeChainee->adresses[index];
    else
        return NULL;
}
