#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, D;
    
    while (1) {
        scanf("%d %d", &N, &D);
        if (N == 0 && D == 0) break;
        
        int *digits = (int *)malloc(N * sizeof(int));
        int *stack = (int *)malloc(N * sizeof(int));

        if (digits == NULL || stack == NULL) {
            fprintf(stderr, "Falha na alocação de memória.\n");
            return 1; 
        }

        int top = 0, toRemove = D, maxLen = N - D;

        for (int i = 0; i < N; i++) {
            scanf("%1d", &digits[i]);
        }

        for (int i = 0; i < N; i++) {
            while (top > 0 && stack[top - 1] < digits[i] && toRemove > 0) {
                top--;
                toRemove--;
            }
            
            if (top < maxLen) { 
                stack[top++] = digits[i];
            }
        }

        for (int i = 0; i < top; i++) {
            printf("%d", stack[i]);
        }
        printf("\n");

        free(digits);
        free(stack);
    }

    return 0;
}
