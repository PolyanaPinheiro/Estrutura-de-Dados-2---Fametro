#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    trocar(&a, &b);

    printf("Valores trocados: a = %d, b = %d\n", a, b);
    return 0;
}

