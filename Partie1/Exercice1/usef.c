#include <stdio.h>
int demanderTaille(void){
    printf("entrer la taille de votre tableau : ");
    int n;
    scanf("%d",&n);
    return n;
}

void remplirTab(int *t,int n){
    for(int i =0 ; i<n ; i++){
        printf("entrer le %d'%s element ",i+1, i==0? "er":"eme");
        scanf("%d",&t[i]);
    }
}
