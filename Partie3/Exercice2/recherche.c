#include "sort.h"
#include <stdio.h>
void rechercheSeq3(int *t,int n ){
    int max,max1,max2;
    max = t[0];
    max1 = max;
    max2 = max1;
    for (int i =0 ; i<n ; i++){
        if(t[i] > max){
            max2 = max1;
            max1 = max;
            max = t[i];
        }
        else if(t[i] > max1 && t[i] !=max){
            max2 = max1;
            max1 = t[i];
        }
        else if(t[i] > max2 && t[i] !=max1 && t[i] !=max){
            max2 = t[i];
        }
    }
    printf("Les 3 valeurs maximales sont %d , %d et %d", max,max1,max2);
}

void rechercheSeq(int *t,int n,int x ){
    int i;
    int ind;
    for (i =0 ; i<n; i++){
        if(t[i] == x ){
        printf("l'element %d se trouve a la position %d dans le tableau non trie \n ",x,i);
        ind = 0;
        break; 
        }
        else{
            ind = -1;
        }
    }

    
    if (ind ==-1){
        printf( "introuvable dans la deuxieme partie\n ");
    }
    
}

void rechercheSeqInv(int *t,int n,int x ){
    int i;
    int ind;
    for (i =n-1 ; i>=0; i--){
        if(t[i] == x ){
        ind = i;
        break;
        }
        else{
            ind = -1;
        }

    }

    if(ind == i ){
        printf("la dernire occurence de %d est %d \n",x,ind);
    }

    
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
    if(occ>0)
    printf("Le nombre d'occurences de %d est %d",x,occ);
    
}

void rechercheDico1(int *t,int n,int x ){
    int inf = 0;
    int sup = n-1;
    int m;
    int result = -1;
    triFusion(t,inf,sup);
    while(inf <= sup){
        m = (sup+inf)/2;
        if(t[m] == x){
            result = m;
            sup = m-1;
        }
        else if(t[m] > x){
            sup = m-1;
        }

        else if(t[m] < x){
            inf = m+1;
        }
    }
    if (result != -1)
    printf("la premiere ocurrence est %d",result);
    else 
    printf("element introuvable");
}

void rechercheDicoTabTrie(int *t,int n,int x ){
    int inf = 0;
    int sup = n-1;
    int m;
    int res=-1;
    while(inf <= sup){
        m = (sup+inf)/2;
        if(t[m] == x){
            res = m;
            break;
        }
        else if(t[m] > x){
            sup = m-1;
        }

        else if(t[m] < x){
            inf = m+1;
        }
    }
    if(res != -1){
        printf("l'element %d est trouve dans la partie trie, son indice est %d \n",x,res);
    }
    else if(res == -1){
        printf("l'element est introuvable dans la partie trie \n");
    }
}