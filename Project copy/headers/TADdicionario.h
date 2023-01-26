#ifndef TADDICIONARIO_H
#define TADDICIONARIO_H

#include "TADpalavra.h"
#include "media.h"

//letra
typedef struct {
    char letra;
    ListaPala *Pala;
}letra;

//celula letra
typedef struct celula_letra{
    letra Letra;
    struct celula_letra *prox;
}celula_letra;

//lista de letras
typedef struct{
    celula_letra *primeiro;
    celula_letra *utimo;
}lista_letra;

//inicializa lista de letras
void inicia_lista_letra(lista_letra *lista);

//insere letra na lista
void insere_letra(lista_letra *lista, letra l,char *Palavra );

//verifica se a letra ja exista(chamar para inserir palavra)
int verifica_letra(lista_letra *lista, letra l, char *charptr,int cont);

// imprime lista
void imprimeletra(lista_letra *lista);

//imprime letra dada
void imprimeletradada(lista_letra *lista);

//trasporta informacao
void trasport(lista_letra *lista,char *palavra,int escolha);

//costroi vetor
void Constroi_vetor(lista_letra *ll,ListaPala *lp);

//criando uma copia para ordernacao
void copiaparaodernar(ListaPala *let,TPalavra *vet);

//ordena toda lista
void ordena_lista(lista_letra *lista,char *palavra,int escolha, media *v_media);

//trasporta informacao para as funcoes de ordenacao
void trasportsort(lista_letra *lista,celula_letra *letra, char *palavra,int escolha, media *v_media);

void Arquivos(void);

#endif