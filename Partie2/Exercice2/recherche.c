#include <stdio.h>
#include "sort.h"
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
    printf("la premiere ocurrence dans le tableau trie est %d",result);
    else 
    printf("element introuvable");
}