#include "push_swap.h"

static void	push_all_chunks(t_ps *ps, int chunk_size) //dividindo os índices em blocos e processando cada um
{
	int	i;
	int	min;
	int	max;
	int	max_idx;

	max_idx = ps->size_a - 1; //o maior índice possível (lembrando: índices vão de 0 até n-1
	i = 0;
	while (i <= max_idx)
	{
		min = i;
		max = i + chunk_size - 1; //o fim desse bloco
		if (max > max_idx) //se o bloco calculado "ultrapassaria" o maior índice existente corta o max pro limite real.
			max = max_idx;
		push_chunk(ps, min, max); //processa esse bloco inteiro
		i += chunk_size;
	}
}
//Exemplo: n = 20, chunk_size = 5 (de ft_sqrt_ceil(20)). Os blocos processados seriam: [0,4], [5,9], [10,14], [15,19] 4 blocos de 5 elementos cada, cobrindo os 20 índices (0 a 19)

static void	extract_all(t_ps *ps) //puxando tudo de volta pra a, do maior pro menor
{
	while (ps->b)
	{
		rotate_to_top_b(ps, find_max_pos(ps->b));
		op_pa(ps, 1);
	}
}

void	sort_medium(t_ps *ps) //juntando tudo
{
	if (ps->size_a <= 3)
	{
		sort_simple(ps);
		return ;
	}
	push_all_chunks(ps, ft_sqrt_ceil(ps->size_a));
	extract_all(ps);
}
