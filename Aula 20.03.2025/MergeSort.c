#include <stdio.h>

int merge(int *v, int ini, int fim) {
    int meio = (ini + fim) / 2;
    int i = ini, j = meio, k = 0;
    int tam = fim - ini;
    int v_aux[tam];

    // Mescla enquanto ambos os lados têm elementos
    while (i < meio && j < fim) {
        if (v[i] <= v[j]) {
            v_aux[k++] = v[i++];
        } else {
            v_aux[k++] = v[j++];
        }
    }

    // Copia elementos restantes da esquerda (se houver)
    while (i < meio) {
        v_aux[k++] = v[i++];
    }

    // Copia elementos restantes da direita (se houver)
    while (j < fim) {
        v_aux[k++] = v[j++];
    }

    // Copia de volta para o vetor original
    for (k = 0; k < tam; k++) {
        v[ini + k] = v_aux[k];
    }
    return 0;
}

int mergesort(int *v, int ini, int fim) {
    if (fim - ini <= 1) {
        return 0;
    }
    int meio = (ini + fim) / 2;
    mergesort(v, ini, meio); //esquerda
    mergesort(v, meio, fim); //direita
    merge(v, ini, fim); // tudo
    return 0;
}

int main() {
    int v[100000];
    int n;
    int a;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&v[i]);
    }

    mergesort(v, 0, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ",v[i]);
    }
    return 0;
}