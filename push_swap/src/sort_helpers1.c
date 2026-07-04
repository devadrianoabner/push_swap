/* 
Essas são funções de apoio, reutilizadas por vários dos algoritmos de sort. cada uma resolve um problema pequeno e específico ("achar a posição do menor elemento", "girar até uma posição pelo caminho mais curto", etc), e os algoritmos maiores as combinam.

arquivos: src/sort_helpers1.c, sort_helpers2.c, sort_helpers3.c


find_min_index/find_max_index — acham o valor do menor/maior índice na pilha.

find_min_pos/find_max_pos — acham a posição (distância do topo) do elemento com esse índice.
*/

#include "push_swap.h"

int	find_min_index(t_stack *stack) //achando mínimo e máximo
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	find_max_index(t_stack *stack) // trocando < por >.
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_min_pos(t_stack *stack)
{
	int		min_idx;
	int		pos;

	min_idx = find_min_index(stack);
	pos = 0;
	while (stack)
	{
		if (stack->index == min_idx)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

int	find_max_pos(t_stack *stack)
{
	int		max_idx;
	int		pos;

	max_idx = find_max_index(stack);
	pos = 0;
	while (stack)
	{
		if (stack->index == max_idx)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}
