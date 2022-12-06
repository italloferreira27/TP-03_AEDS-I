#ifndef sort_h
#define sort_h

#include "TADdicionario.h"

void imprimir(TPalavra *v,int tam);
void bubblesort(ListaPala *lp);
void insertionsort(ListaPala *lp);
void selectionsort(ListaPala *lp);
void Refaz(int Esq, int Dir, TPalavra *vet);
void Constroi(TPalavra *vet, int *n);
void Heapsort(ListaPala *lp);
void shellsort(ListaPala *lp);
void particaoQ(int esq, int dir, int *i, int *j,TPalavra *vet);
void ordenaQ(int esq, int dir, TPalavra *vet);
void quicksort(ListaPala *lp);

#endif