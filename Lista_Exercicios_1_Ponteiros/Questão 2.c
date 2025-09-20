#include <stdio.h>

void encontrarMaiorMenor(int *array, int tamanho, int *maior, int *menor) {
    *maior = *menor = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > *maior) *maior = array[i];
        if (array[i] < *menor) *menor = array[i];
    }
}

int main() {
    int n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int vetor[n];
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);

    int maior, menor;
    encontrarMaiorMenor(vetor, n, &maior, &menor);

    printf("Maior = %d, Menor = %d\n", maior, menor);
    return 0;
}
