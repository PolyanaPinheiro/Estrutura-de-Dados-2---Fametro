# 📘 Respostas Teóricas --- Lista de Exercícios (Ponteiros em C)

### Questão 1

Qual das seguintes afirmações sobre ponteiros em C é VERDADEIRA?

-   a)  Um ponteiro armazena o valor de uma variável.\

-   **b) Um ponteiro armazena o endereço de memória de uma variável.**\

-   c)  A declaração `int *p;` aloca memória para um inteiro.\

-   d)  O operador `&` é usado para acessar o valor apontado por um
        ponteiro.

------------------------------------------------------------------------

### Questão 2

O que o operador `*` (asterisco) faz quando usado na frente de uma
variável do tipo ponteiro que já foi inicializada?

-   a)  Declara um novo ponteiro.\

-   b)  Retorna o endereço de memória do ponteiro.\

-   c)  Realiza uma operação de multiplicação.\

-   **d) Acessa (dereferencia) o valor armazenado no endereço de memória
    para o qual o ponteiro aponta.**

------------------------------------------------------------------------

### Questão 3

Para que serve a função `malloc()` da biblioteca `<stdlib.h>`?

-   a)  Para liberar memória previamente alocada.\

-   b)  Para declarar uma variável do tipo ponteiro.\

-   **c) Para alocar um bloco de memória de um tamanho especificado em
    bytes e retornar um ponteiro para o início desse bloco.**\

-   d)  Para copiar o conteúdo de um bloco de memória para outro.

------------------------------------------------------------------------

### Questão 4

Considere a função `void modifica(int *a, int b)` que altera o valor da
variável para a qual `a` aponta.\
Como seria a chamada correta desta função na `main` para modificar uma
variável `int num = 5;`?

**Resposta correta:**

``` c
int num = 5;
modifica(&num, num);
```
