#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Função de comparação para ordenação em ordem decrescente
int comparar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Função que verifica se é possível cobrir a área desejada com as tábuas disponíveis
int possivel(int *largurasTabuas, int tamanho, int comprimentoTabua, int larguraAlvo, int area) {
    int totalTabuas = 0;
    int areaAtual = 0;
    int ehPossivel = 0;

    int esquerda = 0, direita = tamanho - 1;

    // Tentar usar tábuas de largura igual à larguraAlvo
    while(esquerda <= direita && largurasTabuas[esquerda] == larguraAlvo) {
        totalTabuas++, esquerda++;
        areaAtual += larguraAlvo * comprimentoTabua;
        if (areaAtual == area) {
            ehPossivel = 1;
            break;
        }
    }

    // Tentar usar pares de tábuas que somem à larguraAlvo
    while (!ehPossivel && esquerda < direita) {
        if (largurasTabuas[esquerda] + largurasTabuas[direita] == larguraAlvo) {
            totalTabuas += 2;
            areaAtual += larguraAlvo * comprimentoTabua;
            esquerda++, direita--;
            if (areaAtual == area) {
                ehPossivel = 1;
                break;
            }
            continue;
        }

        if (largurasTabuas[esquerda] + largurasTabuas[direita] > larguraAlvo) {
            esquerda++;
        } else {
            direita--;
        }
    }

    return ehPossivel ? totalTabuas : INF;
}

int main() {
    int largura, altura;
    // Continuar lendo até que largura e altura sejam ambos diferentes de zero
    while (scanf("%d %d", &largura, &altura), largura && altura) {
        largura *= 100, altura *= 100;

        int menorDimensao = largura < altura ? largura : altura;
        int maiorDimensao = largura > altura ? largura : altura;

        int comprimentoTabua, numTabuas;
        scanf("%d %d", &comprimentoTabua, &numTabuas);

        int *tabuasParaMaiorDimensao = (int*)malloc(numTabuas * sizeof(int));
        int *tabuasParaMenorDimensao = (int*)malloc(numTabuas * sizeof(int));
        int tamanhoMaiorDimensao = 0, tamanhoMenorDimensao = 0;

        for (int i = 0; i < numTabuas; i++) {
            int larguraTabua;
            scanf("%d", &larguraTabua);
            larguraTabua *= 100;
            if (larguraTabua <= maiorDimensao) {
                tabuasParaMaiorDimensao[tamanhoMaiorDimensao++] = larguraTabua;
            }

            if (larguraTabua <= menorDimensao) {
                tabuasParaMenorDimensao[tamanhoMenorDimensao++] = larguraTabua;
            }
        }

        // Ordenar os arrays de tábuas em ordem decrescente
        qsort(tabuasParaMaiorDimensao, tamanhoMaiorDimensao, sizeof(int), comparar);
        qsort(tabuasParaMenorDimensao, tamanhoMenorDimensao, sizeof(int), comparar);

        // Calcular o resultado mínimo usando ambas as orientações
        int resultado = possivel(tabuasParaMaiorDimensao, tamanhoMaiorDimensao, comprimentoTabua, maiorDimensao, largura * altura);
        int resultadoTemporario = possivel(tabuasParaMenorDimensao, tamanhoMenorDimensao, comprimentoTabua, menorDimensao, largura * altura);

        if (resultadoTemporario < resultado) {
            resultado = resultadoTemporario;
        }

        if (resultado == INF) {
            printf("impossivel\n");
        } else {
            printf("%d\n", resultado);
        }
    }
    return 0;
}
