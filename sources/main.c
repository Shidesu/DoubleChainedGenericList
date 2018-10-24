#include <stdio.h>
#include "../headers/listeChainee.h"

int main() {
    ListeChainee maListe;


    initializeList(&maListe);

    int *test = calloc(1, sizeof(int));

    *test = 25;
    maListe.addToTail(&maListe, test);
    test = calloc(1, sizeof(int));
    *test = 30;
    maListe.addToHead(&maListe, test);
    test = calloc(1, sizeof(int));
    *test = 61;
    maListe.addToTail(&maListe, test);
    test = calloc(1, sizeof(int));
    *test = 73;
    maListe.addToHead(&maListe, test);
    test = calloc(1, sizeof(int));
    *test = 1;
    maListe.addToTail(&maListe, test);
    test = NULL;

    printf("Valeur … l'index 1 : %d\n", *(int *) maListe.get(&maListe, 1)->data);

    maListe.getAll(&maListe, printIntValues);

    maListe.remove(&maListe, maListe.head);

    test = calloc(1, sizeof(int));
    *test = 242;

    maListe.insertAt(&maListe, test, 3);

    maListe.getAll(&maListe, printIntValues);

    maListe.removeAt(&maListe, 0);

    maListe.getAll(&maListe, printIntValues);

    maListe.remove(&maListe, maListe.tail);

    maListe.getAll(&maListe, printIntValues);

    maListe.remove(&maListe, maListe.head);

    maListe.getAll(&maListe, printIntValues);

    maListe.removeAll(&maListe);

    maListe.getAll(&maListe, printIntValues);

    printf("Hello, World!\n");
    maListe.getAll(&maListe, printIntValues);

    system("pause");

    return 0;
}
