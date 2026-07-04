#include "push_swap.h"

void	sort_adaptive(t_ps *ps, char **name, char **complexity)
{
	double	disorder;

	disorder = compute_disorder(ps->a, ps->size_a);
	*name = "Adaptive";
	// esses thresholds (0.2 / 0.5) foram no chute, preciso
	// rodar o benchmark com varios tamanhos e calibrar direito
	if (ps->size_a <= 5)
	{
		*complexity = "O(n^2)";
		sort_simple(ps);
		return ;
	}
	if (disorder < 0.2)
	{
		*complexity = "O(n^2)";
		sort_simple(ps);
		return ;
	}
	if (disorder < 0.5)
	{
		*complexity = "O(n*sqrt(n))";
		sort_medium(ps);
		return ;
	}
	*complexity = "O(n log n)";
	sort_complex(ps);
}
