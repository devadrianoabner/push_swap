#include "push_swap.h"

static void	swap_top_two(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	op_sa(t_ps *ps, int print)
{
	if (!ps->a || !ps->a->next)
		return ;
	swap_top_two(&ps->a);
	ps->op_sa++;
	ps->total_ops++;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	op_sb(t_ps *ps, int print)
{
	if (!ps->b || !ps->b->next)
		return ;
	swap_top_two(&ps->b);
	ps->op_sb++;
	ps->total_ops++;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	op_ss(t_ps *ps, int print)
{
	swap_top_two(&ps->a);
	swap_top_two(&ps->b);
	ps->op_ss++;
	ps->total_ops++;
	if (print)
		ft_putstr_fd("ss\n", 1);
}
