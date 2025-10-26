/*
 * Resolucao da Questao 01
 * Agenda Telefonica com Lista Encadeada Simples
 * VERSAO COM EDICAO DE CAMPO ESPECIFICO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao para limpar o buffer de entrada (stdin)
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Estruturas de Dados ---

typedef struct data {
    int dia;
    int mes;
} Data;

typedef struct contato {
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    Data dataAniversario;
} Contato;

typedef struct elemento {
    Contato info;
    struct elemento *prox;
} Elemento;

// --- Funcoes da Agenda ---

Elemento* cria_agenda() {
    return NULL;
}

// Funcao para ler os dados de um contato (usada apenas para insercao)
void ler_contato_info(Contato* c) {
    printf("Digite o nome (max 40): ");
    scanf(" %[^\n]", c->nome);
    printf("Digite o telefone (max 15): ");
    scanf(" %[^\n]", c->telefone);
    printf("Digite o celular (max 15): ");
    scanf(" %[^\n]", c->celular);
    printf("Digite o email (max 40): ");
    scanf(" %[^\n]", c->email);
    
    printf("Digite o dia do aniversario: ");
    scanf("%d", &c->dataAniversario.dia);
    limpar_buffer();

    printf("Digite o mes do aniversario: ");
    scanf("%d", &c->dataAniversario.mes);
    limpar_buffer();
}

void insere_contato(Elemento** agenda) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\n--- Cadastro de Novo Contato ---\n");
    ler_contato_info(&novo->info);
    novo->prox = NULL;

    if (*agenda == NULL) {
        *agenda = novo;
    } else {
        Elemento* atual = *agenda;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    printf("Contato inserido com sucesso!\n");
}

void lista_contatos(Elemento* agenda) {
    if (agenda == NULL) {
        printf("\nAgenda vazia.\n");
        return;
    }

    printf("\n--- Lista de Contatos ---\n");
    Elemento* atual = agenda;
    int i = 1;
    while (atual != NULL) {
        printf("Contato %d:\n", i++);
        printf("  Nome: %s\n", atual->info.nome);
        printf("  Telefone: %s\n", atual->info.telefone);
        printf("  Celular: %s\n", atual->info.celular);
        printf("  Email: %s\n", atual->info.email);
        printf("  Aniversario: %d/%d\n", atual->info.dataAniversario.dia, atual->info.dataAniversario.mes);
        atual = atual->prox;
    }
}

Elemento* busca_contato(Elemento* agenda, char* nome) {
    Elemento* atual = agenda;
    while (atual != NULL) {
        if (strcmp(atual->info.nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

//
// Funcao de atualizacao modificada para permitir edicao de campos especificos.
void atualiza_contato(Elemento* agenda) {
    char nomeBusca[41];
    printf("\nDigite o nome do contato que deseja editar: ");
    scanf(" %[^\n]", nomeBusca);

    //
    Elemento* contatoEncontrado = busca_contato(agenda, nomeBusca);

    if (contatoEncontrado != NULL) {
        int opcao = 0;
        while (opcao != 7) {
            // Mostra os dados atuais do contato
            printf("\n--- Editando Contato: %s ---\n", contatoEncontrado->info.nome);
            printf("1. Nome: %s\n", contatoEncontrado->info.nome);
            printf("2. Telefone: %s\n", contatoEncontrado->info.telefone);
            printf("3. Celular: %s\n", contatoEncontrado->info.celular);
            printf("4. Email: %s\n", contatoEncontrado->info.email);
            printf("5. Dia Aniversario: %d\n", contatoEncontrado->info.dataAniversario.dia);
            printf("6. Mes Aniversario: %d\n", contatoEncontrado->info.dataAniversario.mes);
            printf("7. Concluir Edicao\n");
            printf("Qual campo deseja alterar? ");

            scanf("%d", &opcao);
            limpar_buffer();

            switch (opcao) {
                case 1:
                    printf("Digite o novo nome: ");
                    scanf(" %[^\n]", contatoEncontrado->info.nome);
                    break;
                case 2:
                    printf("Digite o novo telefone: ");
                    scanf(" %[^\n]", contatoEncontrado->info.telefone);
                    break;
                case 3:
                    printf("Digite o novo celular: ");
                    scanf(" %[^\n]", contatoEncontrado->info.celular);
                    break;
                case 4:
                    printf("Digite o novo email: ");
                    scanf(" %[^\n]", contatoEncontrado->info.email);
                    break;
                case 5:
                    printf("Digite o novo dia de aniversario: ");
                    scanf("%d", &contatoEncontrado->info.dataAniversario.dia);
                    limpar_buffer();
                    break;
                case 6:
                    printf("Digite o novo mes de aniversario: ");
                    scanf("%d", &contatoEncontrado->info.dataAniversario.mes);
                    limpar_buffer();
                    break;
                case 7:
                    printf("Edicao concluida.\n");
                    break;
                default:
                    printf("Opcao invalida! Tente novamente.\n");
                    break;
            }
        }
    } else {
        //
        printf("Contato buscado ('%s') nao foi encontrado.\n", nomeBusca);
    }
}

void remove_contato(Elemento** agenda) {
    char nomeBusca[41];
    printf("\nDigite o nome do contato que deseja remover: ");
    scanf(" %[^\n]", nomeBusca);

    Elemento* anterior = NULL;
    Elemento* atual = *agenda;

    while (atual != NULL && strcmp(atual->info.nome, nomeBusca) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato buscado ('%s') nao foi encontrado.\n", nomeBusca);
        return;
    }

    if (anterior == NULL) {
        *agenda = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Contato removido com sucesso!\n");
}

void buscar_e_imprimir(Elemento* agenda) {
    char nomeBusca[41];
    printf("\nDigite o nome do contato que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    Elemento* contato = busca_contato(agenda, nomeBusca);

    if (contato != NULL) {
        printf("\n--- Contato Encontrado ---\n");
        printf("  Nome: %s\n", contato->info.nome);
        printf("  Telefone: %s\n", contato->info.telefone);
        printf("  Celular: %s\n", contato->info.celular);
        printf("  Email: %s\n", contato->info.email);
        printf("  Aniversario: %d/%d\n", contato->info.dataAniversario.dia, contato->info.dataAniversario.mes);
    } else {
        printf("Contato buscado ('%s') nao foi encontrado.\n", nomeBusca);
    }
}

void libera_agenda(Elemento** agenda) {
    Elemento* atual = *agenda;
    while (atual != NULL) {
        Elemento* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *agenda = NULL;
}

int main() {
    Elemento* minhaAgenda = cria_agenda();
    int opcao = 0;

    //
    while (opcao != 6) {
        //
        printf("\n--- Agenda Telefonica ---\n");
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                insere_contato(&minhaAgenda);
                break;
            case 2:
                lista_contatos(minhaAgenda);
                break;
            case 3:
                buscar_e_imprimir(minhaAgenda);
                break;
            case 4:
                atualiza_contato(minhaAgenda);
                break;
            case 5:
                remove_contato(&minhaAgenda);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    libera_agenda(&minhaAgenda);
    return 0;
}