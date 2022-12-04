#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Project/headers/TADdicionario.h"
#include "../Project/headers/TADpalavra.h"
#include "../Project/headers/TADlinha.h"

int main(){
    lista_letra letras;
    letra let;
    ListaPala lista;
    TPalavra obj;

    Tlista linha;
    Titem item;

    int escolha, result;
    int cont = 1, i;
    
    char linha_texto[100],pala[10];
    char *palavra;
    char l;

    celula_letra *auxptr;
    celula_letra *aux1;

    FILE *TXTptr;
    TXTptr = fopen("texto.txt", "r");


    inicia_lista_letra(&letras);


    while(escolha != 9){

        InstrucoesLP(); //exibe menu de escolhas
        printf("Escolha uma opcao: ");
        scanf("%d",&escolha);
        printf("\n");

        switch(escolha){
            case 1:
                printf("Lendo arquivo de texto.\n\n");
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
                            //

                            verifica_letra(&letras, let, palavra,cont);
                            palavra = strtok(NULL, " "); //Passa para a proxima palavra
                            
                        }
                        cont++;
                    }
                }
                fclose(TXTptr);
                printf("Leitura realizada com sucesso.\n\n");
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

                printf("Finalizando ...\n");

                break;

            default:

                printf("Escolha invalida.\n\n");

                break;
        }

    }
    return 0;
}
