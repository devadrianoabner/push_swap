#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

void	radix_sort(t_ps *ps)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	size = ps->size_a;
	max_bits = get_max_bits(size);
	bit = 0;
	// isso aqui ta quebrando pra listas com index negativo
	// preciso normalizar os indices (0 a size-1) antes de comparar
	// os bits, se nao o sinal bagunca tudo.
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((ps->a->index >> bit) & 1)
				op_ra(ps, 1);
			else
				op_pb(ps, 1);
			i++;
		}
		while (ps->b)
			op_pa(ps, 1);
		bit++;
	}
}
	// terminar o fechamento do loop e testar com 500 numeros
