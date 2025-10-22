#include "sort.h"
#include <stdio.h>
void rechercheSeq3(int *t,int n ){
    int max,max1,max2;
    max = -9999999;
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
        ind = i;
        break; 
        }
        else{
            ind = -1;
        }
    }

    if(ind == i ){
        printf("la premiere occurence de %d est %d \n",x,ind);
    }
    else if (ind ==-1){
        printf( "introuvable \n ");
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

