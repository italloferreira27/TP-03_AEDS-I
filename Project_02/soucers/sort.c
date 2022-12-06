#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/sort.h"


//imprimir elementos
void imprimir(TPalavra *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%s\n",v[i].item);
    }
    printf("\n");
}

//---------------------------------------bubble sort-----------------------------------------------------
void bubblesort(ListaPala *lp){
    clock_t start, end;

    int i, j, p=1, comp=0, mov=0;
    int tam = lp->nroElem;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp, vet);
    
    double time;
    start = clock();
    
    /*for(int a = 0; a < tam; a++){//Bobble_sort
        for(int j = a+1; j < tam; j++){
            comp++;
            if(strcmp(vet[a].item, vet[j].item) > 0){ //0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
                strcpy(aux.item, vet[a].item);
                strcpy(vet[a].item, vet[j].item);
                strcpy(vet[j].item, aux.item);
                mov += 2;
            }
        }
    }*/

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            while(vet[i].item[p] == vet[j].item[p] && (vet[i].item[p] && vet[j].item[p])) p++;

            comp++; //Conta o numero de comparações
            if(vet[i].item[p] < vet[j].item[p]){
                
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                mov++; //Conta o número de movimentações
            }p=1;
        }
    }

    end = clock();
    
    printf("\nbubblesort:\n");
    imprimir(vet, tam);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comp, mov);
    printf("Tempo de execução: %f seg\n",time);
}
//----------------------------------------------------------------------------------------------------------

//---------------------------------------insertion sort----------------------------------------------------
void insertionsort(ListaPala *lp){
    clock_t start, end;

    int i, j, p=1, comp=0, mov=0;
    int tam = lp->nroElem;
    double time;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp, vet);

    start = clock();

    /*for(i = 1; i <= tam; i++){
        strcpy(aux.item, vet[i].item);
        j = i-1;
        while(j >= 0 && strcmp(aux.item, vet[j].item) < 0){
            strcpy(vet[j+1].item, vet[j].item);
            j--;
            comp++;
        }
        strcpy(vet[j+1].item, aux.item);
        mov++;
    }*/

    for(i=1;i<tam;i++){
        aux = vet[i];
        j=i-1;
        while(vet[j].item[p] == aux.item[p] && (vet[j].item[p] && aux.item[p]))p++;
        while(j>=0 && vet[j].item[p] > aux.item[p]){
            vet[j+1] = vet[j];
            j--;
            p=1;
            while(vet[j].item[p] == aux.item[p] && (vet[j].item[p] && aux.item[p]))p++;
        }p=1;

        vet[j+1] = aux;
    }
    end = clock();

    printf("\ninsertionsort:\n");
    imprimir(vet, tam+1);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comp, mov);
    printf("tempo de execução: %f\n",time);
}
//---------------------------------------------------------------------------------------------------------

//-------------------------------------selection sort-----------------------------------------------------
void selectionsort(ListaPala *lp){
    clock_t start, end;

    int i, j, p=1, min, comp=0, mov=0;
    int tam = lp->nroElem;
    double time;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp, vet);

    start = clock();

    /*for(i = 0; i < tam; i++){ //select_sort
        min = i;
        for(j = i + 1; j < tam; j++){
            comp++; //Conta a quantidade de comparacoes
            if(strcmp(vet[j].item, vet[min].item) < 0) min = j;//0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
        }
        strcpy(aux.item, vet[min].item);
        strcpy(vet[min].item, vet[i].item);
        strcpy(vet[i].item, aux.item);
        mov++; //Conta a quantidade de mivimentacoes
    }*/

    for(i=0;i<tam;i++){
        min=i;
        for(j=i+1;j<tam;j++){
            while(vet[min].item[p] == vet[j].item[p] && (vet[min].item[p] && vet[j].item[p])) p++;
            if(vet[j].item[p]<vet[min].item[p]) min = j;

            p = 1;
        }
        aux=vet[min];
        vet[min] = vet[i];
        vet[i] = aux;
    }
    end = clock();

    printf("\nselectionsort:\n");
    imprimir(vet, tam);
    
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comp, mov);
    printf("tempo de execução: %f\n",time);
}
//---------------------------------------------------------------------------------------------------------

//----------------------------------------heap sort-------------------------------------------------------
void Refaz(int Esq, int Dir, TPalavra *vet){
    int p = 1;
    int j = Esq * 2;
    TPalavra aux = vet[Esq];

    while (j <= Dir){
        while(vet[j].item[p] == vet[j+1].item[p] && (vet[j].item[p] && vet[j+1].item[p]))p++;
        if ((j < Dir)&&(vet[j].item[p] < vet[j+1].item[p])) j++;
        
        p=1;
        while(vet[j].item[p] == aux.item[p] && (vet[j].item[p] && aux.item[p]))p++;
        if (aux.item[p] >= vet[j].item[p]) break;
        
        p=1;
        
        vet[Esq] = vet[j];
        Esq = j; j = Esq * 2 ;

    }
    vet[Esq] = aux;
}

void Constroi(TPalavra *vet, int *n){
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1){
        Esq--;
        Refaz(Esq, *n, vet);
    }
}



void Heapsort(ListaPala *lp){ 
    clock_t start, end;
    double time;
    int Esq, Dir,i;
    int tam = lp->nroElem;
    TPalavra aux;

    TPalavra vet[tam+1];
//*************************copia o vetor*********************************   
    int tam1;
    ListaPala *aux1;
    celulapalavra *auxpala;
    
    aux1 = lp;
    tam1 = aux1->nroElem;
    
    
    for(i=1;i<tam1+1;i++){
        vet[i] = lp->Vpalavra[i-1];
    }
//************************************************************************
    
    start = clock();
    Constroi(vet, &tam); /* constroi o heap */
    Esq = 1; Dir = tam;
    
    while (Dir > 1){ /* ordena o vetor */
        aux = vet[1]; vet[1] = vet[Dir]; vet[Dir] = aux;
        Dir--;
        Refaz(Esq, Dir, vet);
    }
    end = clock();

    printf("\nHeapsort:\n");
    for(i=1;i<tam+1;i++){
        printf("%s\n\n",vet[i].item);;
    }

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("tempo de execuçao: %f\n",time);
}
//---------------------------------------------------------------------------------------------------------

//------------------------------------shell sort---------------------------------------------------------- 
void shellsort(ListaPala *lp){
    clock_t start, end;

    int h,i,var,j,p=1;
    int tam = lp->nroElem;
    double time;
    TPalavra aux;

    TPalavra vet[tam];
    copiaparaodernar(lp,vet);
    
    start = clock();
    
        while(h<tam){
            h=h*3+1;
        }

        do{
            if(tam == 1)break;
            h = h / 3;
            for(i=h;i<tam;i++){
                aux = vet[i];
                j = i;


                while(vet[j-h].item[p] == aux.item[p] && (vet[j-h].item[p] && aux.item[p])) p++; 
                
                while(vet[j-h].item[p] > aux.item[p]){  
                    vet[j] = vet[j-h];
                    j = j-h;
                    
                    p=1;
                    while(vet[j-h].item[p] == aux.item[p] && (vet[j-h].item[p] && aux.item[p])) p++;
                    
                    if(j < h)break;
                }
                p=1;
                vet[j] = aux;
            } 
        }while(h != 1);
    end = clock();
        

    printf("\nshellsort:\n");
    imprimir(vet, tam);

    time = (double)(end - start) /CLOCKS_PER_SEC;
    printf("tempo de execução: %f\n",time);
    
    return;
}
//--------------------------------------------------------------------------------------------------------

//----------------------------quicksort------------------------------------------------------------------- 
void particaoQ(int esq, int dir, int *i, int *j,TPalavra *vet){
    int p=1;
    TPalavra pivo,aux;
    *i = esq; *j = dir;
    pivo = vet[(*i+*j)/2];

    do{
        while(vet[*i].item[p] == pivo.item[1] && (vet[*i].item[p] && pivo.item[1])) p++; 
        while (pivo.item[p] > vet[*i].item[p]){
            (*i)++;
            p=1;
            while(vet[*i].item[p] == pivo.item[1] && (vet[*i].item[p] && pivo.item[1])) p++;
            }p=1;
        
        while(vet[*j].item[p] == pivo.item[p] && (vet[*j].item[p] && pivo.item[p])) p++; 
        while (pivo.item[p] < vet[*j].item[p]){
            (*j)--;
            p=1;
            while(vet[*j].item[p] == pivo.item[p] && (vet[*j].item[p] && pivo.item[p])) p++;
            }p=1;
        
        if (*i <= *j){
            aux = vet[*i]; 
            vet[*i] = vet[*j]; 
            vet[*j] = aux;
            (*i)++; (*j)--;
            
        }
        
    }while (*i <= *j);
}


void ordenaQ(int esq, int dir, TPalavra *vet){
    int i,j;

    particaoQ(esq,dir,&i,&j,vet);

    if(esq < j)ordenaQ(esq,j,vet);
    if(i < dir)ordenaQ(i,dir,vet);
}


void quicksort(ListaPala *lp){
    clock_t start,end;
    double time;
    int tam = lp->nroElem;
    
    TPalavra vet[tam];
    copiaparaodernar(lp,vet);

    start = clock();
    ordenaQ(0,tam-1,vet);
    end = clock();

    printf("\nQicksort:\n");
    imprimir(vet,tam);

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("tempo de execução: %f",time);
}
//----------------------------------------------------------------------------------------------------------