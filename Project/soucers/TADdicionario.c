#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADdicionario.h"
#include "../headers/TADpalavra.h"

//inicializa lista de letras
void inicia_lista_letra(lista_letra *lista){
    lista->primeiro = (celula_letra *)malloc(sizeof(celula_letra));
    lista->utimo = lista->primeiro;
    lista->utimo->prox = NULL;

}

//insere letra na lista
void insere_letra(lista_letra *lista, letra l, char *charptr){
    celula_letra *aux = lista->primeiro->prox;
    celula_letra *auxAnt = lista->primeiro;
    Apontador AUXptr;
   
   if(lista->primeiro!=lista->utimo){
    
    while(l.letra >= aux->Letra.letra && aux->prox != NULL){
            aux = aux->prox;
            auxAnt = auxAnt->prox;
        }
    }

    if(lista->primeiro->prox == NULL || lista->utimo == auxAnt->prox && l.letra > lista->utimo->Letra.letra){
        
        lista->utimo->prox = (celula_letra *)malloc(sizeof(celula_letra));
        lista->utimo = lista->utimo->prox;
        lista->utimo->Letra = l;
        lista->utimo->prox = NULL;
        
    }else{
        
        auxAnt->prox = (celula_letra *)malloc(sizeof(celula_letra));
        auxAnt->prox->Letra = l;
        auxAnt->prox->prox = aux;
        
    } 
}

//verifica se a letra ja exista(chamar para inserir palavra)
int verifica_letra(lista_letra *lista, letra l, char *charptr,int cont){
    celula_letra *inicio = lista->primeiro->prox;

    int i;
   
    while(inicio != NULL){
        if(inicio->Letra.letra == l.letra){
            
            InserirElemLP(inicio->Letra.Pala,inicio->Letra.Pala->Ulitmo->palavra,charptr,cont);
            return 1;
        }
        inicio = inicio->prox;
    } 
    l.Pala = (ListaPala *)malloc(sizeof(ListaPala));
    InicializarLP(l.Pala);
    InserirElemLP(l.Pala,l.Pala->Ulitmo->palavra,charptr,cont);
    insere_letra(lista,l,charptr);
    return 0;
}

// imprime lista
void imprimeletra(lista_letra *lista){
    celula_letra *aux = lista->primeiro->prox;

    while(aux != NULL){
        printf("%c\n",aux->Letra.letra);
        ImprimirLP(aux->Letra.Pala);
        aux = aux->prox;
    }

}

//imprime letra dada
void imprimeletradada(lista_letra *lista){
    celula_letra *aux = lista->primeiro->prox;
    char dada[2];

    printf("Digite a letra: ");
    scanf("%s",dada);
    
    while (aux != NULL){
        if(dada[0] == aux->Letra.letra){
            break;
        }
        aux = aux->prox;
    }if(aux!=NULL)ImprimirLP(aux->Letra.Pala);
    else printf("\nInfelizmente a letra nao existe na lista.\n");

}

//trasporta informacao(Do mein para pra o tad lista de palavras/palvra)
void trasport(lista_letra *lista,char *palavra,int escolha){
    int cont = 0;
    celula_letra *aux = lista->primeiro->prox;

    while(aux->Letra.letra != palavra[0] && aux->prox != NULL){
        aux = aux->prox;
    }

    if(aux->Letra.letra == palavra[0]){
            cont++;
        } 
    
    if(aux->prox != NULL || cont != 0){
        switch(escolha){
            case 2:

                int i;
                i = ProcurarLP(aux->Letra.Pala,palavra);
                if(i==1)printf("\nPalavra Encontrada!\n\n");
                else printf("\nInfelimente a palavra nao existe!\n\n");
                break;

            case 3:

                ExcluirElemLPEspecifico(aux->Letra.Pala,palavra);
                break;

            case 4:

                ExcluirElemLPfinal(aux->Letra.Pala);
                break;

            case 5:
                if(aux!=NULL){
                TamanhoLP(aux->Letra.Pala);}
                break;

            case 7:

                ImprimirLPespecifica(aux->Letra.Pala,palavra);
                break;

        }
    }else{
        printf("\nItem nao encontrado.\n");
    }

}