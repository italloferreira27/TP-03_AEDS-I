#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADdicionario.h"
#include "../headers/TADpalavra.h"
#include "../headers/TADlinha.h"

//verificar se a lista esta vazia
int ListaVaziaLP(ListaPala *LP){
    return (LP->Primeiro == LP->Ulitmo); 
}

//inicializar o Lista Palavra
void InicializarLP(ListaPala *LP){
    //LP = (ListaPala *)malloc(sizeof(ListaPala));
    LP->Primeiro = (Apontador) malloc(sizeof(celulapalavra));
    LP->Ulitmo = LP->Primeiro;
    LP->Ulitmo->prox= NULL;
    LP->nroElem = 0; 
}

//inserir nova Lista de Palavra //funcao 1
void InserirElemLP(ListaPala *LP, TPalavra t, char *charptr,int cont){
    //result para verificar se a palavra ja exite
    celulapalavra *inicio = LP->Primeiro->prox;
    int result;
    result = ProcurarLP(LP, charptr);
    while(inicio != NULL ){
        if(strcmp(charptr,inicio->palavra.item) == 0){
            //printf("!\n");
            break;
        }
        inicio = inicio->prox;
    }

    strcpy(t.item , charptr);

    if(result == 0){

        t.lista_linha = (Tlista *)malloc(sizeof(Tlista));
        LL_Inicializa(t.lista_linha);
        LL_Inserir(t.lista_linha,t.lista_linha->Ultimo->linha,cont);
        
        LP->Ulitmo->prox = (Apontador) malloc(sizeof(celulapalavra));
        LP->Ulitmo = LP->Ulitmo->prox;
        LP->Ulitmo->palavra = t; 
        LP->Ulitmo->prox = NULL;
        
        LP->nroElem++;
    }
    else{

        LL_Inserir(inicio->palavra.lista_linha,inicio->palavra.lista_linha->Ultimo->linha,cont);

    }
}

//imprimi Lista de Palavra
void ImprimirLP(ListaPala *LP){
    Apontador aux;
    aux = LP->Primeiro->prox;
    //verificar se a lista esta vazia
    if(ListaVaziaLP(LP)){
        printf("Lista esta Vazia.\n");
        return; 
    }

    while (aux != NULL){
        printf("-----------------------\n");
        printf("Palavra: %s\n",aux->palavra.item);
        LL_Imprimir(aux->palavra.lista_linha);
        printf("-----------------------\n");
        aux = aux->prox;
    }
    return;
}

//imprimi a palavra desejada
void ImprimirLPespecifica(ListaPala *LP, char *pl){
    Apontador aux;
    int result,r;
    aux = LP->Primeiro->prox;

    //verificar se elemento existe
    r = ProcurarLP(LP,pl);

    if(r == 1){
        printf("Palavra existe.\n");
        while (aux != NULL){
        
        result = strcmp(aux->palavra.item, pl);
        
        if(result == 0){
            printf("%s\n",aux->palavra.item);
            LL_Imprimir(aux->palavra.lista_linha);
        }
        
        aux = aux->prox;
        
        }
    }
    else{
        printf("Palavra nao existe.\n");
    }
    return;
}

int ProcurarLP(ListaPala *LP, char *pl){ //funcao 2
    Apontador aux;
    int result;
    aux = LP->Primeiro->prox;

    while (aux != NULL){
        result = strcmp(aux->palavra.item, pl);
        
        if(result == 0){
            return 1;
        }
        
        aux = aux->prox;
   
    }
    return 0;
}

//excluir lista que tenha elemento que o usuario pediu
void ExcluirElemLPEspecifico(ListaPala *LP, char *pl){ //funcao 3
    Apontador ANTptr; //guardar posicao celula anterior
    Apontador aux;
    Apontador Cauxptr;
    int result;
    ANTptr = LP->Primeiro;
    aux = LP->Primeiro->prox;
    
    //verificar se a lista estavazia
    if(ListaVaziaLP(LP)){
        printf("Lista esta Vazia.\n");
        return; 
    }
    //verficar se o elemento existe
    result = ProcurarLP(LP,pl);
    if(result == 0){
        printf("Palavra nao existe.\n");
        return;
    }

    while (aux != NULL){
        result = strcmp(aux->palavra.item, pl);
        if(result == 0){
            Cauxptr = aux;
            ANTptr->prox = aux->prox;
            free(Cauxptr);
            printf("Palavra removida.\n");
            LP->nroElem--;
            return;
        }
        ANTptr = ANTptr->prox;
        aux = aux->prox;
    }
    
}

//excluir o ultimo elemento
void ExcluirElemLPfinal(ListaPala *LP){ //funcao 4
    Apontador ANTptr; //guardar posicao celula anterior
    Apontador aux;
    Apontador Cauxptr;
    int result;
    ANTptr = LP->Primeiro;
    aux = LP->Primeiro->prox;
    
    //verificar se a lista estavazia
    if(ListaVaziaLP(LP)){
        printf("Lista esta Vazia.\n");
        return; 
    }

    while(aux->prox != NULL){
        aux = aux->prox;
        ANTptr = ANTptr->prox;
    }

    Cauxptr = aux;
    ANTptr->prox = aux->prox;
    free(Cauxptr);
    printf("\nPalavra removida.\n");
    LP->nroElem--;
}

//retornar quantidade de palavras
void TamanhoLP(ListaPala *LP){ //funcao 8
    printf("A lista possui %d palavras.\n",LP->nroElem);
}


void InstrucoesLP(void){
    printf("\nMENU:\n"
    "1 = Ler o arquivo de texto;\n"
    "2 = Procurar se a palavra existe;\n"
    "3 = Excluir um elemento especifico da lista;\n"
    "4 = Excluir um elemento no final da lista;\n"
    "5 = Exibir quantas palavras existem;\n"
    "6 = Imprimir a lista de palavras;\n"
    "7 = Imprimir palavra desejada e suas linhas;\n"
    "8 = Imprimir letra especifica;\n"
    "9 = Finalizar.\n");
}
