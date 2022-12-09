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



    // for(i = 0; i <= tam; i++){//Insertion_sort
    //     strcpy(aux, vet[i]);
    //     j = i-1;
    //     while(j >= 0 && strcmp(vet[j], aux) > 0){
    //         strcpy(vet[j+1], vet[j]);
    //         j--;
    //         comp++;
    //     }
    //     strcpy(vet[j+1], aux);
    //     mov++;
    // }

    //int h;
    //h = tam / 2;
    // h = 1;
    // while(h < tam/3){ //Shell_sort
    //     h = 3 * h + 1;
    // }

    // while(h > 0){
    //     for(i = h; i < tam; i++){
    //         strcpy(aux, vet[i]); mov++;
    //         j = i - h;
    //         while(j >= 0 && strcmp(vet[j], aux) > 0){//0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
    //             comp++;
    //             strcpy(vet[j+h], vet[j]);

    //             j -= h;
    //         }
    //         strcpy(vet[j + h], aux); mov++;
    //     }//h /= 2;

    //     h = (h-1)/3;
    // }

  int Particiona(int* vet, int inicio, int final){
      int esq, dir, aux;
      char pivo[20];
      esq = inicio;
      dir = final;
      strcpy(pivo, vet[inicio]);
      while(esq < dir){
          while(strcmp(vet[esq], pivo) <= 0) esq++; //0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
          while(strcmp(vet[dir], pivo)) > 0 dir--; //0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
          if(esq < dir){
              strcpy(aux, vet[esq]);
              strcpy(vet[esq], vet[dir]);
              strcpy(vet[dir], aux);
          }
      }
      strcpy(vet[inicio], vet[dir]);
      strcpy(vet[dir], pivo);
      return dir;
  }

  void Quick_sort(int* vet, int inicio, int fim){
      char pivo[20];
      if(fim > inicio){
          pivo = Particiona(vet, inicio, fim);
          Quick_sort(vet, inicio, pivo-1);
          Quick_sort(vet, pivo+1, fim);
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