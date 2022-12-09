#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/TADdicionario.h"
#include "headers/TADpalavra.h"
#include "headers/TADlinha.h"

int main(){
    lista_letra letras;
    letra let;
    ListaPala lista;
    TPalavra obj;

    Tlista linha;
    Titem item;

    int escolha, escolha2, result;
    int cont = 1, i;
    
    char linha_texto[100],pala[10];
    char *palavra;
    char l, nome_arq[100], nome[20];

    celula_letra *auxptr;
    celula_letra *aux1;

    FILE *TXTptr;

    inicia_lista_letra(&letras);


    while(escolha != 10){

        if(escolha == 0)InstrucoesLP(); //exibe menu de escolhas
        if(escolha != 0){
            printf("\n-------------------------------------\n");
            printf("Digite 0 caso queira ver o menu\n");
            printf("-------------------------------------\n");
        }
        
        printf("Escolha uma opcao: ");
        scanf("%d",&escolha);
        printf("\n");

        switch(escolha){
            case 0:
                break;
            case 1:
                strcpy(nome_arq, "./Arquivos-teste/");
                Arquivos();

                printf("Digite o nome do arquivo: ");
                scanf("%s", nome); //Lendo nome do arquivo
                strcat(nome_arq, nome);

                FILE *TXTptr;
                TXTptr = fopen(nome_arq, "r");

                printf("\nLendo arquivo de texto.\n\n");
                printf("...\n\n");
                if(TXTptr == NULL){
                    printf("Arquivo nao pode ser aberto.\n"); 
                    exit (0);
                }
                else{
                   while(fgets(linha_texto, 100, TXTptr) != NULL){
                        palavra = strtok(linha_texto, " "); //Esta separando cada palavra da linha

                        while(palavra){
                            let.letra = palavra[0];
                            
                            //tratar palavras no final da linha
                            result = strlen(palavra);
                            char palavraaux[result];
                            if(palavra[result-1] == '\n'){
                                for(i=0;i<result;i++){
                                    if(i<result-1){
                                        palavraaux[i] = palavra[i];
                                    }else{
                                        palavraaux[i] = '\0';
                                    }
                                }
                                palavra = palavraaux;
                            }

                            verifica_letra(&letras, let, palavra,cont);
                            palavra = strtok(NULL, " "); //Passa para a proxima palavra
                            
                        }
                        cont++;
                    }
                }
                fclose(TXTptr);
                Constroi_vetor(&letras,&lista);
                printf("Leitura realizada com sucesso.\n");
                break;
            case 2:
                    printf("Digite a palavra para verificar: ");
                    scanf("%s",pala);
                if(letras.primeiro != letras.utimo){ 
                    trasport(&letras,pala,escolha);
                }else{
                    printf("\nPalavra não existe.\n");
                }
                break;
            
            case 3:
                
                if(letras.primeiro != letras.utimo){
                    printf("Digite a palavra que queria excluir: ");
                    scanf("%s",pala);
                    trasport(&letras,pala,escolha); 
                }else{
                    printf("\nLista vazia.\n");
                }
                break;

            case 4:
                if(letras.primeiro != letras.utimo){
                    printf("Digite a letra no qual sera removido a ultima palavra: ");
                    scanf("%s",pala);
                    printf("Ultima palavra sera excluida.\n");
                    trasport(&letras,pala,escolha);
                }else{
                    printf("\nLista vazia.\n");
                }
                break;

            case 5:
                if(letras.primeiro != letras.utimo){
                    printf("Sera exibido a quantidade de palavras existentes na lista da letra: ");
                    scanf("%s",pala);
                    trasport(&letras,pala,escolha);
                }else{
                    printf("\nLista vazia.\n");
                }
                break; 

            case 6:
                if(letras.primeiro != letras.utimo){
                    imprimeletra(&letras);
                }else{
                    printf("\nLista vazia.\n");
                }
                break;

            case 7:
                if(letras.primeiro != letras.utimo){
                    printf("Digite uma palavra para saber em quais linhas ela aparece: ");
                    scanf("%s",pala);
                    trasport(&letras,pala,escolha);
                }else{
                    printf("\nLista vazia.\n");
                }
                break;

            case 8:
                if(letras.primeiro != letras.utimo){
                imprimeletradada(&letras);
                 }else{
                    printf("\nLista vazia.\n");
                }
                break;
            
            case 9:
                if(TXTptr == NULL){
                    printf("Arquivo nao foi lido.\n"); 
                    break;
                }

                printf("-----------------------------------------------\n"
                       "Digite 0 para ordenar toda a lista\n"
                       "                OU"
                       "\nDigite a letra da lista que deseja ordenar\n"
                       "-----------------------------------------------\n");
                scanf("%s",pala);
                
                printf(
              "\n-----------------------------------\n"
                "Menu de ordenacao:\n"
                "1 - Bubble_sort       4 - Heap_sort\n"
                "2 - Insertion_sort    5 - Shell_sort\n"
                "3 - Selection_sort    6 - Quick_sort\n"
                "-----------------------------------\n"
                "Digite um numero: ");
                scanf("%d",&escolha2);
                if(pala[0] == '0'){
                    ordena_lista(&letras,pala,escolha2);
                }else{
                    switch(escolha2){
                        case 1:
                            trasportsort(&letras,letras.utimo,pala,escolha2);
                            break;
                        
                        case 2:
                            trasportsort(&letras,letras.utimo,pala,escolha2);
                            break;

                        case 3:
                            trasportsort(&letras,letras.utimo,pala,escolha2);
                            break;
                        
                        case 4:
                            trasportsort(&letras,letras.utimo,pala,escolha2);
                            break;
                        
                        case 5:
                            trasportsort(&letras,letras.utimo,pala,escolha2);
                            break;
                        case 6:
                            trasportsort(&letras,letras.utimo,pala,escolha2);
                            break;
                    }
                    break;
                case 10:
                    printf("Finalizando ...\n");

                    break;
                default:

                    printf("Escolha invalida.\n\n");

                    break;
            }
        }

    }
    return 0;
}
