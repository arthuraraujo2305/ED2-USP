#include <stdio.h>
#include <limits.h>

int swap(int *v, int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    return 0;
}
int particao(int *v, int ini, int fim) {
    int i = ini +1, j = fim - 1, p = ini;
    int aux;
    while (i<=j) {// i não extrapola o escopo e não ultrapassa o j
        //anda com i para frente até achar um maior
        while (i <= j && v[i] <= v[p])
            i++;
        //anda com j para trás até achar um menor
        while (i <=j && v[j] > v[p])
            j--;
        if (i < j) { //trocar se i e j não se cruzaram
            swap(v, i, j);
        }
    }
    swap(v, p, j);
    return j;
}
int quicksort(int *v, int ini, int fim) {
    if (ini >= fim)
        return 0;
    int j = particao(v, ini, fim);
    quicksort(v, ini, j);
    quicksort(v, j + 1, fim);
}

int main(void) {
    int v[100];
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        v[i] = a;
    }
    quicksort(v, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}