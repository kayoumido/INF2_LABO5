#include <stdio.h>

int main() {
   const int SIZE = 0;
   int* sizePtr = &SIZE;
   unsigned nbElementsTab, nbLances;
   char refaire;
   do
   {
      printf("nbre d'elements    [0..100] : ");
      scanf("%d", nbElementsTab);
      *sizePtr = nbElementsTab;
      int tab[SIZE];
      printf("nbre de lances   [0..10000] : ");
      scanf("%d", nbLances);
      randomize(tab, sizeof(tab)/sizeof(unsigned));
      affichagerTab(tab, sizeof(tab)/sizeof(unsigned));
      printf("voulez-vous recommencer [o:n] :");
      scanf("%c", refaire);
   } while (refaire != 'n');
    return 0;
}