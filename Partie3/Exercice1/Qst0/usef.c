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
void rechercheSeq(int *t,int n,int x ){
    int i;
    for (i =0 ; i<n; i++){
        if(t[i] == x ){
        break;
        }
    }
    printf("La premiere occurence de %d est d'indice %d",x,i);
    
}

void rechercheSeqInv(int *t,int n,int x ){
    int i;
    for (i =n-1 ; i>0; i--){
        if(t[i] == x ){
        break;
        }
    }
    printf("La derniere occurence de %d est d'indice %d",x,i);
    
}