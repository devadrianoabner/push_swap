
// find_best_below / find_target_pos_b = acham onde um novo elemento se encaixaria em b, mantendo a ordenação parcial.

#include "push_swap.h"

static int	find_best_below(t_ps *ps, int idx, int *pos_out) //a lógica de "onde encaixar em b
{
	t_stack	*tmp;
	int		best_idx;
	int		pos;

	tmp = ps->b;
	best_idx = -1;
	pos = 0;
	while (tmp)
	{
		if (tmp->index < idx && (best_idx == -1 || tmp->index > best_idx))
		{
			best_idx = tmp->index; 
			*pos_out = pos;   //repare: pos_out é um ponteiro de saída a função "devolve" a posição através dele, além do return que devolve só um "achou ou não").
		}
		pos++;
		tmp = tmp->next;
	}
	return (best_idx != -1); //devolve 1 (verdadeiro) se achou algum candidato, 0 se b não tinha nenhum nó com índice menor que idx.
}

int	find_target_pos_b(t_ps *ps, int idx)
{
	int	pos;

	pos = 0;
	if (find_best_below(ps, idx, &pos))
		return (pos);
	return (find_max_pos(ps->b));
}
// find_target_pos_b usa a função de cima: se existe um "maior menor que" dentro de b, devolve a posição dele. 
// Se não existe nenhum nó em b com índice menor (ou seja, idx é menor que tudo que já está em b),
//  devolve a posição do maior elemento de b como alvo (porque, se o novo elemento é o menor de todos, ele deve ir logo depois do maior valor de b — que, numa pilha mantida em ordem decrescente, fica no fundo).
// 
// Onde isso é usado: é uma das peças que ajuda a decidir onde inserir elementos mantendo b parcialmente ordenada, um raciocínio parecido (mas não idêntico) ao que o sort_complex faz com find_target_in_b — são funções irmãs, resolvendo o mesmo tip
// o de problema em contextos ligeiramente diferentes (sort_medium vs sort_complex).