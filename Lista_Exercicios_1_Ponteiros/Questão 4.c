#include <stdio.h>

void dobrar(int *n) {
    *n = *n * 2;
}

int main() {
    int x;
    printf("Digite um numero: ");
    scanf("%d", &x);

    dobrar(&x);

    printf("O dobro do valor = %d\n", x);
    return 0;
}
