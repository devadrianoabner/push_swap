#include "push_swap.h"

// tirar essa declaração local daqui e voltar pro push_swap.h
// assim que o radix_sort estiver terminado
# ifndef NO_RADIX
void	radix_sort(t_ps *ps);
# endif

static void	turk_sort(t_ps *ps)
{
	int	best_a;
	int	best_b;

	op_pb(ps, 1);
	if (ps->size_a > 1)
		op_pb(ps, 1);
	while (ps->size_a > 3)
	{
		best_a = 0;
		best_b = 0;
		find_cheapest(ps, &best_a, &best_b);
		move_both_to_top(ps, best_a, best_b);
		op_pb(ps, 1);
	}
	sort_simple(ps);
	push_back_to_a(ps);
}

void	sort_complex(t_ps *ps)
{
	if (ps->size_a <= 3)
	{
		sort_simple(ps);
		return ;
	}
	if (ps->size_a <= 200)
		turk_sort(ps);
	// acima de 200 era pra chamar radix_sort, mas como ele
	// ainda não fechou, no build de dev (NO_RADIX) cai pro turk_sort
	// mesmo só fica mais lento pra listas grandes
	else
	{
# ifndef NO_RADIX
		radix_sort(ps);
# else
		turk_sort(ps);
# endif
	}
}
