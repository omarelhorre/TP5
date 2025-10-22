#include "recherche.h"
#include "sort.h"
#include "usef.h"
#include <stdio.h>
#include <stdlib.h>

void main(void){
    int n = demanderTaille();
    int *t = (int *) malloc(sizeof(int)*n);
    remplirTab(t,n);
    printf("entrer jusqu'a quelle element vous voulez arreter votre tri");
    int limTableauTrie;
    scanf("%d",&limTableauTrie);
    triSelect(t,n,limTableauTrie);
    afficheTab(t,n);
    // partie 2 de la qst 
    int x = lireVal();
    rechercheDicoTabTrie(t,limTableauTrie,x);
    rechercheSeq(t+limTableauTrie,n-limTableauTrie,x);


}

