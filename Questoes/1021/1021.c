#include <stdio.h>
#include <math.h>

void decompor(int valor, int notas[], int tamanho) {
    int moedaPrint = 0;
    int notaPrint = 0;

    for (int i = 0; i < tamanho; i++) {
        int quantidade = valor / notas[i];
        valor -= quantidade * notas[i];

        if (notas[i] >= 200) {
            if (!notaPrint) {
                notaPrint = 1;
                printf("NOTAS:\n");
            }
            printf("%d nota(s) de R$ %.2f\n", quantidade, notas[i] / 100.0);
        } else {
            if (!moedaPrint) {
                moedaPrint = 1;
                printf("MOEDAS:\n");
            }
            printf("%d moeda(s) de R$ %.2f\n", quantidade, notas[i] / 100.0);
        }
    }
}

int main() {
    float valor;
    scanf("%f", &valor);

    // Converte valor para centavos para evitar problemas de precisão, arredondando
    float valor_em_centavos = round(valor * 100);

    // Vetor com todas as notas e moedas, ordenadas de maior para menor
    int notas[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1}; // Em centavos
    int tamanho = 12;

    // Chama a função para decompor o valor
    decompor(valor_em_centavos, notas, tamanho);

    return 0;
}
