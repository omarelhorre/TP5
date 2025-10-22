#include <stdlib.h>
#include "usef.h"
void main(void){
    int n = demanderTaille();
    int *t = (int *) malloc(sizeof(int) * n);
    remplirTab(t,n);
     int x;
    x = lireVal();
    rechercheSeqOcc(t,n,x);
}