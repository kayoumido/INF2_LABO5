#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stats(unsigned tab[], unsigned valMax, unsigned nbThrows) {

    for (unsigned i = 0; i < valMax; ++i) {
        *(tab + i) = 0;
    }

    srand(time(0));

    for (unsigned i = 0; i < nbThrows; ++i) {

        unsigned val = rand() % valMax;
        *(tab + val) += 1;
    }
    
}

void affichageTab(const unsigned *tab, unsigned taille, unsigned nbLances) {
    char buffer[12];
    for (unsigned i = 0; i < taille; ++i) {
        unsigned tempPourcent = (*(tab + i) * 100) / nbLances;
        sprintf(buffer, "tableau [%d]", i);
        printf("%-16s%-8d", buffer, tempPourcent);
        for (size_t j = 0; j < tempPourcent; ++j) {
            printf("=");
        }
        printf("\n");
    }
}


int main() {

    const int SIZE = 0;
    int *sizePtr = &SIZE;
    unsigned nbElementsTab = 0,
             nbLances = 0;
    char refaire;

//    do {
    printf("nbre d'elements    [0..100] : ");
    scanf("%d", &nbElementsTab);

    *sizePtr = nbElementsTab;
    unsigned tab[SIZE];

    printf("nbre de lances   [0..10000] : ");
    scanf("%d", &nbLances);

    stats(tab, nbElementsTab, nbLances);

    affichageTab(tab, nbElementsTab, nbLances);

    //randomize(tab, sizeof(tab) / sizeof(unsigned));
    //affichagerTab(tab, sizeof(tab) / sizeof(unsigned));

//        printf("voulez-vous recommencer [o:n] :");
//        scanf("%c", refaire);

//    } while (refaire != 'n');

    return 0;
}

