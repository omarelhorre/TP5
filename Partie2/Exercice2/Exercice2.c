#include <stdlib.h>
#include "usef.h"
#include "recherche.h"
void main(void){
    int n = demanderTaille();
    int *t = (int *) malloc(sizeof(int) * n);
    remplirTab(t,n);
    int x;
    x = lireVal();
    rechercheDico1(t,n,x);
    free(t);
}