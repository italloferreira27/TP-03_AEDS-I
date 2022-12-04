#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
    FILE *file;
    file = fopen("texto.txt", "r");

    char linha[100], *palavra; 
    char vet[50][100], aux[20];
    int cont, comp, mov; 
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
    //..........Ordenar..........
    for(int a = 0; a < 40; a++){
        for(int j = a+1; j < 40; j++){
            comp++;
            if(strcmp(vet[a], vet[j]) > 0){
                strcpy(aux, vet[a]);
                strcpy(vet[a], vet[j]);
                strcpy(vet[j], aux);
                mov += 2;
            }
        }
    }
    //...........................
    end = clock();

    printf("\n\nPalavras ordenadas: ");
    for(int i = 0; i < 40; i++){
        printf("%s ", vet[i]);
    }
    printf("\n\nComparacoes: %d\nMovimentacoes: %d", comp, mov);

    time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %f seg.\n", time);


    fclose(file);
    return 0;
}