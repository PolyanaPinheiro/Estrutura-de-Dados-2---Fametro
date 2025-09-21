#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializar(Fila* f) {
    f->ini = f->fim = NULL;
}

void enfileirar(Fila* f, Cliente c) {
    Cliente *novo = (Cliente*) malloc(sizeof(Cliente));
    if (!novo) return;
    strncpy(novo->id, c.id, sizeof(novo->id));
    novo->id[sizeof(novo->id)-1] = '\0';
    novo->qtd = c.qtd;
    novo->prox = NULL;
    if (f->fim) {
        f->fim->prox = novo;
    } else {
        f->ini = novo;
    }
    f->fim = novo;
}

bool desenfileirar(Fila* f, Cliente *out) {
    if (!f->ini) return false;
    Cliente *tmp = f->ini;
    if (out) {
        *out = *tmp;
        out->prox = NULL;
    }
    f->ini = tmp->prox;
    if (!f->ini) f->fim = NULL;
    free(tmp);
    return true;
}

bool vazia(Fila* f) {
    return f->ini == NULL;
}

void limpar(Fila* f) {
    Cliente *at = f->ini;
    while (at) {
        Cliente *prox = at->prox;
        free(at);
        at = prox;
    }
    f->ini = f->fim = NULL;
}
