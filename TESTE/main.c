#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//#include "funcoes.h"

int main(){
    FILE *file;
    file = fopen("texto.txt", "r");

    char linha[100], *palavra; 
    char vet[50][100], aux[20];
    int cont, comp, mov, opcao, tam = 40; 
    int i, j, min;
    double time;
    clock_t start, end;

    //..........Lendo arquivo..........
    while(fgets(linha, 100, file) != NULL){
        palavra = strtok(linha, " "); //Separando as palavra das linha

        while(palavra){
        strcpy(vet[cont], palavra); cont++;
        //printf("%s \n", palavra);
        palavra = strtok(NULL, " "); //Passando para porxima palavra
        
        }
        printf("%ls", &cont);
    }
    //..................................

    for(int i = 0; i < 40; i++){
        printf("%s ", vet[i]);
    }

    start = clock();
    //..........Ordenação..........
    /*printf("1 = Bobble_sort;\n2 = Select_sort");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            Bobble_sort(&vet[0][0], 40, &mov, &comp);
            break;
        case 2:
            break;
        default:
         printf("\nOpcao Invalida!");
    }
    */
//    for(int a = 0; a < 40; a++){//Bobble_sort
//         for(int j = a+1; j < 40; j++){
//             comp++;
//             if(strcmp(vet[a], vet[j]) > 0){ //0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
//                 strcpy(aux, vet[a]);
//                 strcpy(vet[a], vet[j]);
//                 strcpy(vet[j], aux);
//                 mov += 2;
//             }
//         }
//     }

        // for(i = 0; i < 40; i++){ //select_sort
        //     min = i;
        //     for(j = i + 1; j < 40; j++){
        //         comp++;
        //         if(strcmp(vet[j], vet[min]) < 0) min = j;//0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
        //     }
        //     strcpy(aux, vet[min]);
        //     strcpy(vet[min], vet[i]);
        //     strcpy(vet[i], aux);
        //     mov += 2;
        // }



    for(i = 0; i <= tam; i++){
        strcpy(aux, vet[i]);
        j = i-1;
        while(j >= 0 && strcmp(vet[j], aux) > 0){
            strcpy(vet[j+1], vet[j]);
            j--;
            comp++;
        }
        strcpy(vet[j+1], aux);
        mov++;
    }

    //...........................
    end = clock();

    printf("\n\nPalavras ordenadas: ");
    for(int i = 0; i < 41; i++){
        printf("%s ", vet[i]);
    }
    printf("\n\nComparacoes: %d\nMovimentacoes: %d", comp, mov);

    time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %f seg.\n", time);


    fclose(file);
    return 0;
}