
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

int main() {
    Produto *estoque = NULL;
    char comando[16];

    printf("Sistema de Controle de Estoque\n");
    while (1) {
        printf("\nDigite um comando (ADD, UPD, DEL, FIND, LIST, REL, EXIT): ");
        if (scanf("%15s", comando) != 1) break;

        if (strcmp(comando, "ADD") == 0) {
            Produto p;
            scanf("%15s", p.codigo);
            getchar(); // remover espaço
            scanf(" \"%63[^\"]\" %d %f", p.nome, &p.qtd, &p.preco);
            estoque = inserir_ordenado_por_codigo(estoque, p);
        } else if (strcmp(comando, "UPD") == 0) {
            char cod[16];
            int delta;
            scanf("%15s %d", cod, &delta);
            estoque = ajustar_quantidade(estoque, cod, delta);
        } else if (strcmp(comando, "DEL") == 0) {
            char cod[16];
            scanf("%15s", cod);
            estoque = remover_por_codigo(estoque, cod);
        } else if (strcmp(comando, "FIND") == 0) {
            char cod[16];
            scanf("%15s", cod);
            Produto *res = buscar(estoque, cod);
            if (res) {
                printf("Produto encontrado: %s (%s), qtd=%d, preco=%.2f\n", res->codigo, res->nome, res->qtd, res->preco);
            } else {
                printf("Produto nao encontrado.\n");
            }
        } else if (strcmp(comando, "LIST") == 0) {
            listar(estoque);
        } else if (strcmp(comando, "REL") == 0) {
            int totalItens = 0;
            float valorTotal = 0.0;
            Produto *maior = NULL;
            for (Produto *aux = estoque; aux; aux = aux->prox) {
                totalItens++;
                valorTotal += aux->qtd * aux->preco;
                if (!maior || aux->qtd * aux->preco > maior->qtd * maior->preco)
                    maior = aux;
            }
            printf("Total itens: %d\nValor total: %.2f\n", totalItens, valorTotal);
            if (maior) {
                printf("Produto com maior valor: %s (%s), valor=%.2f\n",
                       maior->codigo, maior->nome, maior->qtd * maior->preco);
            }
        } else if (strcmp(comando, "EXIT") == 0) {
            estoque = limpar(estoque);
            break;
        } else {
            printf("Comando invalido.\n");
        }
    }

    return 0;
}
