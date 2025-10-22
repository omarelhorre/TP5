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

int lireVal(void){
    printf("entrer la valeur que vous voulez chercher");
    int x;
    scanf("%d",&x);
    return x;
}


void rechercheSeqOcc(int *t,int n,int x ){
    int i;
    int occ;
    occ = 0;
    for (i =0 ; i<n; i++){
        if(t[i] == x ){
        occ++;
        }
    }
    printf("Le nombre d'occurences de %d est %d",x,occ);
    
}