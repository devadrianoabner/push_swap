# push_swap

Projeto de ordenação de pilhas (42 School) usando `push`, `swap`, `rotate` e
`reverse rotate` nas stacks A e B.

## 

- [x] Parsing dos argumentos e validação (`parse.c`)
- [x] Operações básicas (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)
- [x] `sort_simple` (3 elementos) e ordenação para poucos elementos
- [x] `sort_medium` (chunks / sqrt(n))
- [x] `sort_complex` (estratégia estilo "Turk sort" com custo mínimo)
- [x] Cálculo de desordem (`disorder.c`) pra escolher a estratégia
- [x] Modo `--bench` com contagem de operações
- [ ] `radix_sort` 
- [ ] Calibrar os thresholds do modo adaptativo (`sort_adaptive.c`)
- [ ] Melhorar mensagens de erro do parse (`main.c`)
- [ ] Otimizar `find_cheapest` (hoje é O(n²), ver TODO em `sort_complex_cost.c`)
- [ ] Testes com valgrind 
- [ ] Fluxograma da lógica de decisão (adaptive → simple/medium/complex/radix)

## Compilação

- `make` — build completo (hoje ainda quebra em `sort_complex_radix.c`, é o que falta terminar)
- `make dev` — build sem o `radix_sort`, pra já dar pra testar
  `simple` / `medium` / `complex` enquanto o radix não fecha

## 

```
./push_swap 2 1 3 5 4
./push_swap --bench 2 1 3 5 4
./push_swap --simple|--medium|--complex|--adaptive [--bench] <números>
```