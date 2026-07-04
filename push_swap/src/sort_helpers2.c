#include "push_swap.h"

void	rotate_to_top_a(t_ps *ps, int pos)
{
	int	size;

	size = ps->size_a;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			op_ra(ps, 1);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			op_rra(ps, 1);
	}
}
// rotate_to_top_a / rotate_to_top_b o "caminho mais curto"

void	rotate_to_top_b(t_ps *ps, int pos)
{
	int	size;

	size = ps->size_b;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			op_rb(ps, 1);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			op_rrb(ps, 1);
	}
}

int	find_pos_in_b(t_ps *ps, int index) // achando a posição de um índice específico em b
{
	t_stack	*tmp;
	int		pos;

	tmp = ps->b;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}
