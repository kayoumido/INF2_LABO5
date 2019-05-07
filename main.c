/*
-----------------------------------------------------------------------------------
Laboratoire : 05
Fichier     : main.cpp
Auteur(s)   : Loïc Geinoz, Doran Kayoumi, David Oliveira Monteiro
Date        : 07.05.2019
But         : Effectue des statistiques sur des valeurs générées aléatoirement.
Remarque(s) : -
Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define VIDER_BUFFER while( getchar() != '\n')

/**
 * @brief Initialise an array wit a default value
 *
 * @param tab           array to initialise
 * @param size          size of the array
 * @param defaultValue  default value to set
 */
void initArray(unsigned *tab, unsigned size, unsigned defaultValue) {
    for (unsigned i = 0; i < size; ++i) {
        *(tab + i) = defaultValue;
    }
}

/**
 * @brief   Fill an array with the number of times a number was
 *          randomly generated
 *
 * @param tab       array to fill
 * @param valMax    max value that can be generated
 * @param nbThrows  number of "throws" to do
 */
void generateRandom(unsigned *tab, unsigned valMax, unsigned nbThrows) {

    initArray(tab, valMax, 0);

    srand(time(0));

    for (unsigned i = 0; i < nbThrows; ++i) {

        unsigned val = rand() % valMax;
        *(tab + val) += 1;
    }

}

/**
 * @brief Calculate de percentage value of a value
 *
 * @param value to convert to percent
 * @param total 100%
 *
 * @return the percentage value
 */
unsigned calculatePercentage(unsigned value, unsigned total) {
    return (!total ? total : (value * 100) / total);
}

/**
 * @brief display an array
 *
 * @param tab       array to display
 * @param taille    size of the array
 * @param nbThrows  max number of throws done
 */
void displayTab(const unsigned *tab, unsigned taille, unsigned nbThrows) {
    char buffer[13];

    printf("\n");

    for (unsigned i = 0; i < taille; ++i) {
        unsigned percentage = calculatePercentage(*(tab + i), nbThrows);

        sprintf(buffer, "tableau [%d]", i);
        printf("%-16s%-8d", buffer, percentage);

        for (size_t j = 0; j < percentage; ++j) {
            printf("=");
        }

        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Get user input
 *
 * @param min   value that can be inputed
 * @param max   value that can be inputed
 * @param text  to display
 * @return the user input
 */
unsigned userInput(unsigned min, unsigned max, char *text) {
    bool ok;
    unsigned saisie;
    const char *ERREUR = "/!\\ erreur de saisie\n";

    do {

        printf("%s [%d-%d] : ", text, min, max);
        ok = scanf("%u", &saisie);
        VIDER_BUFFER;

    } while ((!ok || saisie < min || saisie > max)
             && printf("%s", ERREUR));

    return saisie;
}

int main() {

    unsigned nbElements = 0,
             nbThrows = 0;

    char restart;
    const unsigned MAX_ELEMENT = 100;
    const unsigned MIN_ELEMENT = 0;
    const unsigned MAX_THROW = 1000;
    const unsigned MIN_THROW = 0;

    do {

        nbElements = userInput(MIN_ELEMENT, MAX_ELEMENT, "nbre d'elements ");

        unsigned tab[nbElements];

        nbThrows = userInput(MIN_THROW, MAX_THROW, "nbre de lances");

        generateRandom(tab, nbElements, nbThrows);

        displayTab(tab, nbElements, nbThrows);

        printf("voulez-vous recommencer [o:n] :");
        scanf("%c", &restart);
        VIDER_BUFFER;

    } while (restart != 'n');

    return 0;
}

