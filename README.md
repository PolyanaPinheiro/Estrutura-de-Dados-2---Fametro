
# Questão 1 — Lista ligada para Controle de Estoque

## Compilação e execução

```bash
gcc main.c produto.c -o estoque
./estoque
```

## Exemplo de uso

```
ADD P01 "Teclado" 10 120.50
ADD P02 "Mouse" 5 80.00
LIST
REL
UPD P01 -3
LIST
DEL P02
LIST
EXIT
```

## Complexidade das operações

- inserir_inicio: O(1)
- inserir_ordenado_por_codigo: O(n)
- remover_por_codigo: O(n)
- ajustar_quantidade: O(n) (busca)
- buscar: O(n)
- listar: O(n)
- limpar: O(n)
