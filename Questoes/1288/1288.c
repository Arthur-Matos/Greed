#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int poder_destruicao;
    int peso;
} Projetil;

int max(int a, int b) {
    return a > b ? a : b;
}

// Função para calcular o dano máximo usando backtracking
int calcularMaximoDano(Projetil projetis[], int n, int capacidade, int idx, int **memo) {
    if (capacidade == 0 || idx == n) {
        return 0; 
    }

    if (memo[idx][capacidade] != -1) {
        return memo[idx][capacidade];
    }

    int naoPega = calcularMaximoDano(projetis, n, capacidade, idx + 1, memo);
    int pega = 0;
    if (projetis[idx].peso <= capacidade) { // Se o peso do projétil cabe na capacidade restante
        pega = projetis[idx].poder_destruicao + calcularMaximoDano(projetis, n, capacidade - projetis[idx].peso, idx + 1, memo);
    }
    memo[idx][capacidade] = max(pega, naoPega);
    return memo[idx][capacidade];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, K, R;
        scanf("%d", &N);
        Projetil *projetis = (Projetil *)malloc(N * sizeof(Projetil));
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &projetis[i].poder_destruicao, &projetis[i].peso);
        }
        scanf("%d %d", &K, &R);
        
        int **memo = (int **)malloc(N * sizeof(int *));
        for (int i = 0; i < N; i++) {
            memo[i] = (int *)malloc((K + 1) * sizeof(int));
            for (int j = 0; j <= K; j++) {
                memo[i][j] = -1; 
            }
        }

        int dano_maximo = calcularMaximoDano(projetis, N, K, 0, memo);
        if (dano_maximo >= R) {
            printf("Missao completada com sucesso\n");
        } else {
            printf("Falha na missao\n");
        }

        for (int i = 0; i < N; i++) {
            free(memo[i]);
        }
        free(memo);
        free(projetis);
    }
    return 0;
}
