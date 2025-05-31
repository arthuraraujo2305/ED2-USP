#include <stdio.h>
#include <stdlib.h>
long long merge(int arr[], int temp[], int esquerda, int meio, int direita) {
    int i, j, k;
    long long inversoes = 0;

    i = esquerda;
    j = meio + 1;
    k = esquerda;

    while ((i <= meio) && (j <= direita)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversoes += (long long)(meio - i + 1);
        }
    }

    while (i <= meio) {
        temp[k++] = arr[i++];
    }

    while (j <= direita) {
        temp[k++] = arr[j++];
    }

    for (i = esquerda; i <= direita; i++) {
        arr[i] = temp[i];
    }

    return inversoes;
}

long long _mergeSort_recursiva(int arr[], int temp[], int esquerda, int direita) {
    long long inversoes = 0;
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        inversoes += _mergeSort_recursiva(arr, temp, esquerda, meio);
        inversoes += _mergeSort_recursiva(arr, temp, meio + 1, direita);
        
        inversoes += merge(arr, temp, esquerda, meio, direita);
    }
    return inversoes;
}

long long count_inversoes(int arr[], int array_size) {
    if (array_size <= 1) {
        return 0;
    }
    
    int *temp = (int *)malloc(array_size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Falha na alocacao de memoria para o array temporario.\n");
        exit(1);
    }
    
    long long inversoes = _mergeSort_recursiva(arr, temp, 0, array_size - 1);
    
    free(temp);
    return inversoes;
}

int main() {
    int N;

    while (scanf("%d", &N) == 1 && N != 0) {
        int *gomas = (int *)malloc(N * sizeof(int));
        if (gomas == NULL) {
            fprintf(stderr, "Falha na alocacao de memoria para o array de gomas.\n");
            return 1;
        }

        for (int i = 0; i < N; ++i) {
            if (scanf("%d", &gomas[i]) != 1) {
                fprintf(stderr, "Erro ao ler o tamanho da goma %d.\n", i + 1);
                free(gomas);
                return 1;
            }
        }

        long long num_inversoes = count_inversoes(gomas, N);

        if (num_inversoes % 2 == 1) {
            printf("Fino\n");
        } else {
            printf("Jaques\n");
        }

        free(gomas);
    }

    return 0;
}