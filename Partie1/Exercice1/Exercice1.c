#include <stdio.h>
#include "usef.h"
#include "recherche.h"
#include <stdlib.h>
void main(void){
    int n = demanderTaille();
    int *t = (int *) malloc(sizeof(int) * n);
    remplirTab(t,n);
    rechercheSeq3(t,n);
}
