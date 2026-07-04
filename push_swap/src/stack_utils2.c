#include "push_swap.h"

void	free_ps(t_ps *ps)
{
	if (!ps)
		return ;
	free_stack(&ps->a);
	free_stack(&ps->b);
}
