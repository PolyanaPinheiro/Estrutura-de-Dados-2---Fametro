#include <stdio.h>

int main() {
    int x = 42;
    int *p = &x;

    printf("Valor da variavel: %d\n", x);
    printf("Endereco da variavel: %p\n", (void*)&x);
    printf("Valor do ponteiro: %p\n", (void*)p);
    printf("Valor apontado pelo ponteiro: %d\n", *p);

    return 0;
}
