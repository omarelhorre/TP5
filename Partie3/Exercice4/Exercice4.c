#define L 4
#define C 4
#include <stdio.h>
#include <stdlib.h>
void rechercheMat(int t[L][C], int x);
void main (void){
    int t[L][C] = {
        {1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}
    };
    for(int i = 0; i<L; i++)
    {
        for(int j = 0; j<C;j++){
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }

    int x;
    printf("Quel element vous chercher?");
    scanf("%d",&x);
    rechercheMat(t,x);
}

void rechercheMat(int t[L][C], int x){
    int i = 0, j = C-1, p = -1;
    while(i<=L && j>=0){
        if(t[i][j] == x){
                p=0;
                break;   
        }
        else if(t[i][j] > x){
            j--;
        }
        else {
            i++;
        }
    }
    if(p==0)printf("trouvé, indice %d %d",i,j);
    else if (p==-1) printf("introuvable");
}