# Questão 3 — Pilha de Processos

## Compilação
```bash
gcc -std=c11 -Wall -Wextra main.c pilha.c -o pilha_proc
```

## Execução
```bash
./pilha_proc
```

## Comandos
- `CALL <nomeFunc> <sp>` — empilha novo frame.
- `RET` — desempilha; se vazia, mostra erro.
- `PEEK` — mostra frame do topo.
- `TRACE` — imprime toda a pilha do topo ao fundo.
- `EXIT` — finaliza.

## Complexidade
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
- Vazia: O(1)
- Limpar: O(n)
