#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE *file;
    file = fopen("texto.txt", "r");

    char linha[100], *palavra; 
    char vet[50][100], aux[20];
    //char vetor[26] = {'z', 'x', 'c', 'v', 'b', 'n', 'm', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a'};

    int cont = 0;

    while(fgets(linha, 100, file) != NULL){
        palavra = strtok(linha, " "); //Separando as palavra das linha

        while(palavra){
        strcpy(vet[cont], palavra); cont++;
        //printf("%s \n", palavra);
        palavra = strtok(NULL, " "); //Passando para porxima palavra
        
        }
        printf("%ls", &cont);
    }

    for(int i = 0; i < 40; i++){
        printf("%s ", vet[i]);
    }

    //..........Ordenar..........
    for(int a = 0; a < 40; a++){
        for(int j = a+1; j < 40; j++){
            if(strcmp(vet[a], vet[j]) > 0){
                strcpy(aux, vet[a]);
                strcpy(vet[a], vet[j]);
                strcpy(vet[j], aux);
            }
        }
    }
    //...........................

    printf("\n\nPalavras ordenadas: ");
    for(int i = 0; i < 40; i++){
        printf("%s ", vet[i]);
    }

    fclose(file);
    return 0;
}