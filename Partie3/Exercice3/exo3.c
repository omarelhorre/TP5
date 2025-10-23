#define max 51 // en tenant compte de \0
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void trierChaine(char **t,int n);
void rechercheDico(char **t, int n,char *mot);
void main(void){
    int n;
    printf("entrer le nombres de mots que vous voulez ");
    scanf("%d",&n);
    // 3\n
    while(getchar() != '\n');
    // 3
    char** strings = malloc( sizeof(char*) * n);
    char tmp[max];
    for(int i = 0 ; i<n ; i++ ){
        printf("entrer le %d'%s element ",i+1, i==0? "er":"eme");
    fgets(tmp,max,stdin);
    int length = 0;
    length = strlen(tmp);
    tmp[length - 1] = '\0';
    strings[i] = malloc(sizeof(char) * length);
    strcpy(strings[i],tmp);
}

printf("tableau avant tri \n");
for(int i=0; i<n;i++){
printf("%s \n",strings[i]);}


char mot[100]; //on peut utiliser tmp mais c est pas bc de depenses de memoire

printf("entrer le mot que vous cherchez : ");
fgets(mot,100,stdin);
mot[strlen(mot)-1] = '\0';
rechercheDico(strings,n,mot);
for(int i =0 ; i<n; i++){
    free(strings[i]);
}
free(strings);
}

void trierChaine(char **t,int n){
    int indxMin;
    for(int i=0; i<n-1;i++){
        indxMin = i;
        int j;
        for(j=i+1;j<n;j++){
            if ( strcmp(t[j],t[indxMin]) < 0 ){
                indxMin = j;
            }
        }
        if(indxMin != i){
        char tmp[100];
        strcpy(tmp,t[i]);
        strcpy(t[i],t[indxMin]);
        strcpy(t[indxMin],tmp);}
    }

    }

void rechercheDico(char **t, int n,char *mot){
    trierChaine(t,n);
    printf("le tableau apres le tri \n ");
    for(int i = 0 ; i<n ; i++){
        printf("%s \n ",t[i]);
    } 
    int sup = n-1, inf = 0,m, ind = -1;
    while (inf<=sup)
    {
        m = (sup+inf)/2;
        if(strcmp(mot,t[m]) == 0) {ind = m; break;}
        else if (strcmp(mot, t[m]) < 0 ) sup = m-1;
        else inf = m+1;
    }

    if(ind != -1)
         printf("le mot %s se trouve a l'indice %d ",mot,ind);
    else 
    printf("INTROUVABLE");
   
}