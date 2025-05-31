#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h> 

#define MAX_MOEDAS 100
#define MAX_PESO_POR_MOEDA 500
#define MAX_SOMA_TOTAL_PESOS (MAX_MOEDAS * MAX_PESO_POR_MOEDA)

bool soma_atingivel[MAX_SOMA_TOTAL_PESOS + 1];

int main() {
    int numero_moedas;
    if (scanf("%d", &numero_moedas) != 1) {
        return 1;
    }

    int pesos_das_moedas[MAX_MOEDAS];
    int soma_total_dos_pesos = 0;

    for (int i = 0; i < numero_moedas; ++i) {
        if (scanf("%d", &pesos_das_moedas[i]) != 1) {
            return 1;
        }
        soma_total_dos_pesos += pesos_das_moedas[i];
    }

    for (int i = 0; i <= soma_total_dos_pesos; ++i) {
        soma_atingivel[i] = false;
    }

    soma_atingivel[0] = true;
    for (int i = 0; i < numero_moedas; ++i) {
        int peso_moeda_atual = pesos_das_moedas[i];
        for (int soma_parcial = soma_total_dos_pesos; soma_parcial >= peso_moeda_atual; --soma_parcial) {
            if (soma_atingivel[soma_parcial - peso_moeda_atual]) {
                soma_atingivel[soma_parcial] = true;
            }
        }
    }

    int menor_diferenca_absoluta = INT_MAX;
    for (int soma_para_henrico = 0; soma_para_henrico <= soma_total_dos_pesos / 2; ++soma_para_henrico) {
        if (soma_atingivel[soma_para_henrico]) {
            int soma_para_frederico = soma_total_dos_pesos - soma_para_henrico;
            int diferenca_atual = abs(soma_para_henrico - soma_para_frederico);   
            if (diferenca_atual < menor_diferenca_absoluta) {
                menor_diferenca_absoluta = diferenca_atual;
            }
        }
    }

    printf("%d\n", menor_diferenca_absoluta);

    return 0;
}