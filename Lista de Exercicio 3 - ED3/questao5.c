#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

#define MAX 100

typedef struct {
    int topo;
    int dados[MAX];
} Pilha;

void criaPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int push_interno(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        return 0; // Falha
    } else {
        p->topo++;
        p->dados[p->topo] = valor;
        return 1; // Sucesso
    }
}

void push(Pilha *p, int valor) {
    if (push_interno(p, valor)) {
        printf("Numero %d cadastrado com sucesso.\n", valor);
    } else {
        printf("Mensagem: Pilha cheia! Nao foi possivel cadastrar.\n");
    }
}

int pop(Pilha *p) {
    if (pilhaVazia(p)) {
        return INT_MIN; 
    } else {
        int valor = p->dados[p->topo];
        p->topo--;
        return valor;
    }
}

void mostrarPares(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Mensagem: Pilha vazia! Nao ha numeros para mostrar.\n");
        return;
    }

    Pilha aux;
    criaPilha(&aux);
    int encontrouPar = 0;

    printf("Numeros pares na pilha (do topo para a base):\n");
    
    while (!pilhaVazia(p)) {
        int valor = pop(p);
        if (valor % 2 == 0) {
            printf("%d\n", valor);
            encontrouPar = 1;
        }
        push_interno(&aux, valor);
    }

    if (!encontrouPar) {
        printf("Nenhum numero par encontrado na pilha.\n");
    }

    while (!pilhaVazia(&aux)) {
        push_interno(p, pop(&aux));
    }
}

void mostrarMenu() {
    printf("\n--- MENU ---\n");
    printf("1- Cadastrar numero\n");
    printf("2- Mostrar numeros pares\n");
    printf("3- Excluir numero\n");
    printf("4- Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Pilha p;
    criaPilha(&p);
    int opcao, valor;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero a ser cadastrado: ");
                scanf("%d", &valor);
                push(&p, valor);
                break;
            case 2:
                mostrarPares(&p);
                break;
            case 3: { 
                int valorExcluido = pop(&p);
                if (valorExcluido == INT_MIN) {
                    printf("Mensagem: Pilha vazia! Nao ha numero para excluir.\n");
                } else {
                    printf("Numero %d (topo) excluido com sucesso.\n", valorExcluido);
                }
                break;
            }
            case 4: // Sair
                printf("Saindo...\n");
                break;
            default:
                printf("Mensagem: Opcao invalida do menu!\n");
        }
    } while (opcao != 4);

    return 0;
}
