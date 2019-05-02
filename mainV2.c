#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VIDER_BUFFER    while( getchar() != '\n')

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
    char buffer[13];
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

unsigned saisieUtilisateur(unsigned min, unsigned max, char* text)
{
    bool        ok;
    unsigned    saisie;
    const char* ERREUR = "/!\\ erreur de saisie\n";
    
    do {

        printf ("%s [%d-%d] : ",text, min, max);
        ok = scanf ("%u", &saisie);
        VIDER_BUFFER;
        
    } while ( (!ok || saisie<min || saisie>max)
                && printf ("%s", ERREUR));
    
    return saisie;
}

int main() {

    unsigned nbElementsTab = 0,
             nbLances = 0;
    char refaire;
    const unsigned MAX_ELEMENT = 100;
    const unsigned MIN_ELEMENT = 0;
    const unsigned MAX_LANCE = 1000;
    const unsigned MIN_LANCE = 0;
    do {

    nbElementsTab = saisieUtilisateur(MIN_ELEMENT,MAX_ELEMENT, "nbre d'elements ");

    unsigned tab[nbElementsTab];

    nbLances= saisieUtilisateur(MIN_LANCE,MAX_LANCE, "nbre de lances");

    stats(tab, nbElementsTab, nbLances);

    affichageTab(tab, nbElementsTab, nbLances);

       printf("voulez-vous recommencer [o:n] :");
        scanf("%c", &refaire);

    } while (refaire != 'n');

    return 0;
}

