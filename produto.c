
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

Produto* criar_node(Produto p) {
    Produto *novo = (Produto*)malloc(sizeof(Produto));
    if (!novo) return NULL;
    *novo = p;
    novo->prox = NULL;
    return novo;
}

Produto* inserir_inicio(Produto *L, Produto p) {
    Produto *novo = criar_node(p);
    if (!novo) return L;
    novo->prox = L;
    return novo;
}

Produto* inserir_ordenado_por_codigo(Produto *L, Produto p) {
    Produto *ant = NULL, *atual = L;
    while (atual && strcmp(atual->codigo, p.codigo) < 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual && strcmp(atual->codigo, p.codigo) == 0) {
        atual->qtd += p.qtd;
        atual->preco = p.preco;
        return L;
    }
    Produto *novo = criar_node(p);
    if (!novo) return L;
    if (!ant) {
        novo->prox = L;
        return novo;
    } else {
        ant->prox = novo;
        novo->prox = atual;
        return L;
    }
}

Produto* remover_por_codigo(Produto *L, const char *codigo) {
    Produto *ant = NULL, *atual = L;
    while (atual && strcmp(atual->codigo, codigo) != 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (!atual) return L;
    if (!ant) {
        L = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual);
    return L;
}

Produto* ajustar_quantidade(Produto *L, const char *codigo, int delta_qtd) {
    Produto *atual = buscar(L, codigo);
    if (atual) {
        if (atual->qtd + delta_qtd >= 0) {
            atual->qtd += delta_qtd;
        } else {
            printf("Erro: quantidade nao pode ser negativa.\n");
        }
    }
    return L;
}

Produto* buscar(Produto *L, const char *codigo) {
    for (Produto *aux = L; aux; aux = aux->prox) {
        if (strcmp(aux->codigo, codigo) == 0) return aux;
    }
    return NULL;
}

void listar(Produto *L) {
    for (Produto *aux = L; aux; aux = aux->prox) {
        printf("[%s] %s - qtd=%d preco=%.2f\n", aux->codigo, aux->nome, aux->qtd, aux->preco);
    }
}

Produto* limpar(Produto *L) {
    Produto *aux = L;
    while (aux) {
        Produto *tmp = aux;
        aux = aux->prox;
        free(tmp);
    }
    return NULL;
}
