#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fila.h"

typedef struct {
    int estoque;
    int total_vendido;
    int clientes_atendidos;
} Relatorio;

int main(void) {
    Fila fila;
    inicializar(&fila);
    Relatorio rel = {0,0,0};

    printf("Estoque inicial: ");
    scanf("%d", &rel.estoque);
    getchar();

    char linha[256];
    printf("Comandos: ADD <id> <qtd>, START, REL, EXIT\n");

    while (1) {
        printf(">> ");
        if (!fgets(linha, sizeof(linha), stdin)) break;
        if (strncmp(linha, "EXIT", 4) == 0) break;

        if (strncmp(linha, "ADD", 3) == 0) {
            Cliente c;
            if (sscanf(linha+3, "%s %d", c.id, &c.qtd) == 2) {
                enfileirar(&fila, c);
                printf("Cliente %s entrou na fila.\n", c.id);
            }
        } else if (strncmp(linha, "START", 5) == 0) {
            Cliente c;
            while (!vazia(&fila) && rel.estoque > 0) {
                desenfileirar(&fila, &c);
                if (c.qtd <= rel.estoque) {
                    rel.estoque -= c.qtd;
                    rel.total_vendido += c.qtd;
                    rel.clientes_atendidos++;
                    printf("Atendido %s (%d ingressos)\n", c.id, c.qtd);
                } else {
                    printf("Cliente %s pediu %d, só temos %d. Não atendido.\n", c.id, c.qtd, rel.estoque);
                    break;
                }
            }
            if (rel.estoque == 0) printf("Ingressos esgotados.\n");
        } else if (strncmp(linha, "REL", 3) == 0) {
            printf("Total vendido: %d\n", rel.total_vendido);
            printf("Clientes atendidos: %d\n", rel.clientes_atendidos);
            printf("Ingressos restantes: %d\n", rel.estoque);
        }
    }
    limpar(&fila);
    return 0;
}