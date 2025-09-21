#include <stdio.h>
#include <string.h>

void inverterString(char *str) {
    char *inicio = str;
    char *fim = str + strlen(str) - 1;
    char temp;

    while (inicio < fim) {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    fgets(palavra, 100, stdin);

    // Remove o '\n' do fgets
    palavra[strcspn(palavra, "\n")] = '\0';

    inverterString(palavra);
    printf("String invertida: %s\n", palavra);
    return 0;
}
