#include "../headers/TADlinha.h"

//verifica se a lista esta vazia
int LL_Vazia(Tlista* lista){
    return lista->Primeiro == lista->Ultimo;
}

//inicia lista de letras
void LL_Inicializa(Tlista* lista){
    lista->Primeiro = (Apontado) malloc(sizeof(Celula_Linha));
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

//insere linha
void LL_Inserir(Tlista* lista, Titem item,int cont){

    item.chave = cont;
    
    if(LL_Procurar(lista, item) != 1){
        lista->Ultimo->prox = (Apontado) malloc(sizeof(Celula_Linha));
        lista->Ultimo = lista->Ultimo->prox;
        lista->Ultimo->linha = item;
        lista->Ultimo->prox = NULL;
        
    }
    

}

//imprime lista de linhas
int LL_Imprimir(Tlista* lista){
    Apontado aux;

    if(LL_Vazia(lista)){
        return 0;
    }

    aux = lista->Primeiro->prox;

    printf("Linhas: ");
    while(aux != NULL){
        printf("|%d", aux->linha.chave);
        aux = aux->prox;
    }
    printf("|\n");
}

//verifica se a linha ja foi adicionada
int LL_Procurar(Tlista* lista, Titem item){
    Apontado aux;
    aux = lista->Primeiro;

    while(aux != NULL){
        if(aux->linha.chave == item.chave){   
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

//esclui do final da lista
int LL_ExcluirFinal(Tlista* lista){
    if(LL_Vazia(lista)){
        
        return 0;
    }

    Apontado aux = lista->Primeiro->prox;
    Apontado ant = lista->Primeiro;

    while(aux != NULL){
        if(aux->prox == NULL){
            aux = lista->Ultimo;
            lista->Ultimo = ant;
            lista->Ultimo->prox = NULL;
            free(aux);
            printf("EXCLUIDO!\n");
            return 0;
        }
        aux = aux->prox;
        ant = ant->prox;
    }
}

//exclui linhas especificas
int LL_ExcluirEspecifico(Tlista* lista, Titem item){
    Apontado aux = lista->Primeiro->prox;
    Apontado ant = lista->Primeiro;

    if(LL_Vazia(lista)){
        printf("lista vazia!\n");
        return 0;
    }

    if(LL_Procurar(lista, item)){
        while(aux != NULL){
            if(aux->linha.chave == item.chave){
                ant->prox = aux->prox;
                free(aux);
                printf("Linha removida!\n");
                return 0;
            }
            aux = aux->prox;
            ant = ant->prox;
        }
    }
    printf("Linha não encontrada!\n");
    return 0;
}