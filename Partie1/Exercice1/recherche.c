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