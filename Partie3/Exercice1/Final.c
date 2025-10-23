#include <stdlib.h>
#include "usef.h"
#include "recherche.h"
void main(void){
    int n = demanderTaille();
    int *t = (int *) malloc(sizeof(int) * n);
    remplirTab(t,n);
     int x;
    x = lireVal();
    rechercheSeq(t,n,x);
    rechercheSeqInv(t,n,x);
    rechercheSeqOcc(t,n,x);
    free(t);
}