# Questão 2 — Fila para Venda Digital de Ingressos

## Compilação
```bash
gcc -std=c11 -Wall -Wextra main.c fila.c -o ingressos
```

## Execução
```bash
./ingressos
```

## Comandos
- `ADD <id> <qtd>` — insere cliente no final da fila.
- `START` — processa a fila em ordem FIFO até acabar ingressos.
- `REL` — mostra relatório parcial (vendido, atendidos, estoque restante).
- `EXIT` — finaliza o programa.

## Complexidade
- Enfileirar: O(1)
- Desenfileirar: O(1)
- Vazia: O(1)
- Limpar: O(n)
