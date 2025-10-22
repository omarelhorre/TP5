#include <stdio.h>
#include <string.h>
int demanderTaille(void){
    printf("entrer la taille de votre tableau : ");
    int n;
    scanf("%d",&n);
    return n;
}

void afficheTab (char *t , int n ){
      for ( int i = 0; i < n; i ++)
printf ("[%d] = %s\n",i ,*( t+ i));
}
void echanger(int *a,int *b){
    int tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;

}
void remplirTab(char *t,int n){
    for(int i =0 ; i<n ; i++){
        printf("entrer le %d'%s element ",i+1, i==0? "er":"eme");
        scanf("%s",t[i]);
    }
}

int lireVal(void){
    printf("entrer la valeur que vous voulez chercher : ");
    int x;
    scanf("%d",&x);
    return x;
}
