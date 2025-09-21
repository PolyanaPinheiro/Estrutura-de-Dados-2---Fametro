#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void pilha_init(Pilha* p) {
    p->topo = NULL;
}

bool push(Pilha* p, const char *func, int sp) {
    Frame *novo = (Frame*) malloc(sizeof(Frame));
    if (!novo) return false;
    strncpy(novo->func, func, sizeof(novo->func));
    novo->func[sizeof(novo->func)-1] = '\0';
    novo->sp = sp;
    novo->baixo = p->topo;
    p->topo = novo;
    return true;
}

bool pop(Pilha* p, Frame *out) {
    if (!p->topo) return false;
    Frame *tmp = p->topo;
    if (out) *out = *tmp;
    p->topo = tmp->baixo;
    free(tmp);
    return true;
}

bool peek(Pilha* p, Frame *out) {
    if (!p->topo) return false;
    if (out) *out = *(p->topo);
    return true;
}

bool vazia(Pilha* p) {
    return p->topo == NULL;
}

void limpar(Pilha* p) {
    Frame *at = p->topo;
    while (at) {
        Frame *prox = at->baixo;
        free(at);
        at = prox;
    }
    p->topo = NULL;
}