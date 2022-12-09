#ifndef TADlinha_h
#define TADlinha_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int Tipochave;
typedef struct{
    Tipochave chave; 
}Titem;

typedef struct Celula_Linha* Apontado;
typedef struct Celula_Linha{
    Titem linha;
    struct Celula_Linha* prox;
}Celula_Linha;

typedef struct{
    Apontado Primeiro;
    Apontado Ultimo;
}Tlista;

//veifica se a lista esta vazia
int LL_Vazia(Tlista* lista);

//inicia lista de linhas
void LL_Inicializa(Tlista* lista);

//insere na lista 
void LL_Inserir(Tlista* lista, Titem item,int cont);

//imprime lista 
int LL_Imprimir(Tlista* lista);

//verifica se liinha ja foi adicionada
int LL_Procurar(Tlista* lista, Titem item);

//exclui do final da lista
int LL_ExcluirFinal(Tlista* lista);

//exclui linha especifica
int LL_ExcluirEspecifico(Tlista* lista, Titem item);

#endif