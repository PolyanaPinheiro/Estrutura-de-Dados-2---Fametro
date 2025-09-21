#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

static void trace(Pilha *p) {
    Frame *at = p->topo;
    int nivel = 0;
    if (!at) {
        printf("Pilha vazia.\n");
        return;
    }
    while (at) {
        printf("Nível %d -> %s (sp=%d)\n", nivel, at->func, at->sp);
        at = at->baixo;
        nivel++;
    }
}

int main(void) {
    Pilha pilha;
    pilha_init(&pilha);

    char linha[128];
    printf("Comandos: CALL <nome> <sp>, RET, PEEK, TRACE, EXIT\n");

    while (1) {
        printf(">> ");
        if (!fgets(linha, sizeof(linha), stdin)) break;

        if (strncmp(linha, "EXIT", 4) == 0) {
            limpar(&pilha);
            break;
        } else if (strncmp(linha, "CALL", 4) == 0) {
            char nome[48]; int sp;
            if (sscanf(linha+4, "%s %d", nome, &sp) == 2) {
                push(&pilha, nome, sp);
                printf("CALL %s (%d) empilhado.\n", nome, sp);
            }
        } else if (strncmp(linha, "RET", 3) == 0) {
            Frame f;
            if (pop(&pilha, &f)) {
                printf("RET -> %s (%d) desempilhado.\n", f.func, f.sp);
            } else {
                printf("Erro: pilha vazia.\n");
            }
        } else if (strncmp(linha, "PEEK", 4) == 0) {
            Frame f;
            if (peek(&pilha, &f)) {
                printf("Topo: %s (%d)\n", f.func, f.sp);
            } else {
                printf("Pilha vazia.\n");
            }
        } else if (strncmp(linha, "TRACE", 5) == 0) {
            trace(&pilha);
        } else {
            printf("Comando inválido.\n");
        }
    }
    return 0;
}