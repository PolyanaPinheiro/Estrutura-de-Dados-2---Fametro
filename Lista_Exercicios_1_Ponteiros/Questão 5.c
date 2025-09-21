#include <stdio.h>

void copiarString(char *origem, char *destino) {
    while (*origem != '\0') {
        *destino = *origem;
        origem++;
        destino++;
    }
    *destino = '\0';
}

int main() {
    char str1[100], str2[100];
    printf("Digite uma string: ");
    fgets(str1, 100, stdin);

    copiarString(str1, str2);
    printf("String copiada: %s\n", str2);

    return 0;
}
