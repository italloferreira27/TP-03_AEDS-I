#include <stdlib.h>
#include <stdio.h>

// void Select_sort(int* vetor, int tam){
//     int i, j, min;
//     char aux[50];
//     for(i = 0; i < tam; i++){
//         min = i;
//         for(j = i + 1; j < tam; j++)
//             if(vetor[j] < vetor[min]) min = j;
//         aux = vetor[min];
//         vetor[min] = vetor[i];
//         vetor[i] = aux;
//     }
// }

void Bobble_sort(char* vetor, int tam, int* mov, int* comp){
    int i, j;
    char aux[50];
    for(int i = 0; i < tam; i++){
        for(int j = i+1; j < tam; j++){
            comp++;
            if(strcmp(vetor[i], vetor[j]) > 0){ //0 se forem iguais, <0 se st1<st2 e >0 se st1>st2.
                strcpy(aux, vetor[i]);
                strcpy(vetor[i], vetor[j]);
                strcpy(vetor[j], aux);
                mov += 2;
            }
        }
    }
}

// void Insert_sort(int* vetor, int tam){
//     int i, j, aux;
//     for(i = 1; i <= tam; i++){
//         aux = vetor[i];
//         j = i-1;
//         while(j >= 0 && aux < vetor[j]){
//             vetor[j+1] = vetor[j];
//             j--;
//         }
//         vetor[j+1] = aux;
//     }
// }

// void Shell_sort(int* vetor, int tam){
//     int i, j, aux, h;
//     //h = tam / 2;

//     h = 1;
//     while(h < tam/3){
//         h = 3 * h + 1;
//     }

//     while(h > 0){
//         for(i = h; i < tam; i++){
//             aux = vetor[i];
//             j = i - h;
//             while(j >= 0 && vetor[j] > aux){
//                 vetor[j+h] = vetor[j];
//                 j -= h;
//             }
//             vetor[j + h] = aux;
//         }
//         printf("Valor de h: %d\nVETOR: ", h);
//         for(int c = 0; c < tam; c++){
//             printf("%d ", vetor[c]);
//         }
//         printf("\n");
//         //h /= 2;

//         h = (h-1)/3;
//     }
// }


// void Shellsort_ZIVI (int* A, int n){
//  int i, j;
//  int h = 1;
//  int aux;

//  do h = h * 3 + 1; while (h < n);
//  do{
//     h = h/3;
//     for( i = h ; i < n ; i++ )
//     {
//         aux = A[i]; j = i;
//         while (A[j - h] > aux)
//         {
//             A[j] = A[j - h]; j -= h;
//             if (j < h) break;
//         }
//         A[j] = aux;
//     }
//  } while (h != 1);
// }


// // int Particiona(int* vetor, int inicio, int final){
// //     int esq, dir, pivo, aux;
// //     esq = inicio;
// //     dir = final;
// //     pivo = vetor[inicio];
// //     while(esq < dir){
// //         while(vetor[esq] <= pivo) esq++;
// //         while(vetor[dir] > pivo) dir--;
// //         if(esq < dir){
// //             aux = vetor[esq];
// //             vetor[esq] = vetor[dir];
// //             vetor[dir] = aux;
// //         }
// //     }
// //     vetor[inicio] = vetor[dir];
// //     vetor[dir] = pivo;
// //     return dir;
// // }

// // void Quick_sort(int* vetor, int inicio, int fim){
// //     int pivo;
// //     if(fim > inicio){
// //         printf("\n");
// //         for(int c = 0; c < 16; c++){
// //             printf("%d ", vetor[c]);
// //         }
// //         pivo = Particiona(vetor, inicio, fim);
// //         Quick_sort(vetor, inicio, pivo-1);
// //         Quick_sort(vetor, pivo+1, fim);
// //     }
// // }
// // Quick sort ZIVIANI
// void Ordena(int Esq, int Dir, int* A) {
//     int i, j;
//     Particao(Esq, Dir, &i, &j, A);
//     if (Esq < j) Ordena(Esq, j, A);
//     if (i < Dir) Ordena(i, Dir, A);
// }

// void QuickSortZIVI(int* A, int n) {
//  Ordena(0, n-1, A);
// }

// void Particao(int Esq, int Dir, int *i, int *j, int *A){
//     int pivo, aux;
//     *i = Esq; *j = Dir;
//     pivo = A[(*i + *j)/2]; /* obtem o pivo x */
//     do {
//         while (pivo > A[*i]) (*i)++;
//         while (pivo < A[*j]) (*j)--;
//         if (*i <= *j){
//             aux = A[*i]; A[*i] = A[*j]; A[*j] = aux;
//             (*i)++; (*j)--;
//         }
//     } while (*i <= *j);
// }