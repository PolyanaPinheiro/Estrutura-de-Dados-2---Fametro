#include <stdio.h>
#include <ctype.h>

void contarVogaisConsoantes(char *str, int *vogais, int *consoantes) {
    *vogais = *consoantes = 0;
    while (*str != '\0') {
        char c = tolower(*str);
        if (c >= 'a' && c <= 'z') {
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                (*vogais)++;
            else
                (*consoantes)++;
        }
        str++;
    }
}

int main() {
    char texto[100];
    int v, c;

    printf("Digite uma string: ");
    fgets(texto, 200, stdin);

    contarVogaisConsoantes(texto, &v, &c);

    printf("Vogais: %d, Consoantes: %d\n", v, c);
    return 0;
}
