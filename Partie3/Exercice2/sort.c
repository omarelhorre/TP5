#include <stdlib.h>
#include "usef.h"

void triSelect(int *t,int n,int l){
int tmp,indxMin;
    for(int i = 0; i<l; i++){
        indxMin = i;
        for(int j = i+1 ; j<n;j++){
            if (t[j] < t[indxMin]){
                indxMin = j;
            }
        }
        if(i != indxMin)
        echanger(&t[i],&t[indxMin]);

    }
}
void triInsert(int *t,int n){
    int tmp,j;
    for(int i = 1;i<n;i++){
        tmp = t[i];
        j=i-1;
        while( tmp<t[j] && j>=0){
            t[j+1] = t[j];
            j--;
        }
        t[j+1] = tmp;
    }
}
void triBull(int *t, int n){
    for (int i =0;i<n-1;i++){
        for (int j=0;j<(n-i-1);j++){
            if (t[j] > t[j+1]){
                echanger(&t[j],&t[j+1]);
            }
        }
    }
}
int calculerMediane(int *t,int debut,int fin){
    return (t[(fin+debut)/2]); 
}
int medianeDesMedianes(int *t, int debut,int fin){
    
    int nombreDeGroupes = (((fin-debut)+1)+4)/5 ; 
    
    if (nombreDeGroupes == 1){
        triInsert(t+debut,(fin-debut)+1); //nombre des elements
        return calculerMediane(t,debut,fin);
        
    }
    else {
        int *tabMediane = (int *)malloc(sizeof(int) * nombreDeGroupes);
        for(int i = 0;i<nombreDeGroupes;i++){
        int indiceCommencer =debut+ i*5;  
        int indicefin = indiceCommencer + 4;
        if (indicefin > fin ) indicefin = fin;  
            triInsert(t+(indiceCommencer),indicefin -indiceCommencer +1);
            tabMediane[i] = calculerMediane(t,indiceCommencer,indicefin);}
            
            int me = medianeDesMedianes(tabMediane,0,nombreDeGroupes - 1);
            free(tabMediane);
            return me;

    
       
    }
    

}
int partitionner(int *t,int deb, int fin){
    int pivot = medianeDesMedianes(t,deb,fin);
    int indxpivot;
    for (indxpivot= deb ; indxpivot<=fin ; indxpivot++){ // ou egale le cas ou pivot se trouve en fin on doit le rendre au milieu
        if(t[indxpivot] == pivot) break;
    }
    echanger(&t[indxpivot],&t[fin]);
    int i = deb - 1;
    if(deb<fin){
        for(int j =deb; j<fin ; j++){
            if(t[j]<pivot){
                i++;
                echanger(&t[j],&t[i]);
            }
        }
      echanger(&t[i+1],&t[fin]);
    }
return i+1;
}
void triRap(int *t, int deb,int fin){
    if(deb<fin){
    int pivot = partitionner(t,deb,fin);
    triRap(t,deb,pivot-1);
    triRap(t,pivot+1,fin);}
}
void fusion(int *t,int g,int m,int d){
    int i,j,k;
    int n1 = m-g+1; //calcule de la taille de Tgauche et Tdroit
    int n2 = d-m;
    // int Tg[n1],Td[n2];
    int *Tg = (int*)malloc(sizeof(int) * n1); if(Tg==NULL) exit(1); //allocation dynamique
    int *Td = (int*)malloc(sizeof(int) * n2); if(Td==NULL) exit(1);//allocation dynamique
    for(i=0;i<n1;i++)
    Tg[i] = t[g+i]; //stocker les valeurs dans les tableaux tableaux devisés en deux
    for (j=0;j<n2;j++)
    Td[j] = t[m+1+j];
    //Fin
    i=0;
    j=0;
    k=g;
    while(i<n1 && j<n2){
        if(Tg[i]<=Td[j]){
            t[k] = Tg[i];
            i++;
        }
        else{
            t[k] = Td[j];
            j++;
        }
        k++;
    }
    // apres on aura l'execlusion d un evenement qui sera par l obligation du code >n1 et donc il n'est pas inferieur aux autres elements avec les quelles on a rempli le tableau
    while(i<n1){
        t[k] = Tg[i];
        i++;
        k++;

    }

    while(j<n2){
        t[k] = Td[j];
        j++;
        k++;

    }
    free(Tg);
    free(Td);
}
void triFusion(int *t,int deb,int fin){
    if(deb<fin){
        int m = (fin+deb)/2; //calculer les medianes car on donne a la recursion le meme tableau pour moi la fonction mergeSort donen seulement le tableau
        triFusion(t,deb,m);
        triFusion(t,m+1,fin);
        fusion(t,deb,m,fin);
    }
    }