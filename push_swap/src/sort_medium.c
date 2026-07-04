/*Arquivos sort_medium.c e sort_medium2.c
algoritmo O(n√n): divide os índices em blocos de tamanho aproximado √n, processa cada bloco, e junta tudo no final.

ft_sqrt_ceil calcula ⌈√n⌉ manualmente, incrementando i até i*i >= n.
Os índices são divididos em blocos de tamanho √n (push_all_chunks).
Dentro de cada bloco, push_chunk gira a até achar cada elemento daquele bloco no topo, empurra pra b, e usa op_rb condicional (só quando o elemento pertence à metade "menor" daquele bloco específico) pra manter uma ordenação parcial dentro de b.*/

#include "push_swap.h"

int	ft_sqrt_ceil(int n) //raiz quadrada arredondada pra cima, sem <math.h>
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

static int	count_in_range(t_stack *stack, int min, int max) //contando quantos elementos caem num intervalo de índices
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index <= max)
			count++;
		stack = stack->next;
	}
	return (count);
}

static int	top_is_in_range(t_ps *ps, int min, int max) //o topo de a pertence a esse bloco?
{
	if (!ps->a)
		return (0);
	return (ps->a->index >= min && ps->a->index <= max);
}

void	push_chunk(t_ps *ps, int min, int max) // processando um bloco inteiro
{
	int	pushed;
	int	total;
	int	mid;

	total = count_in_range(ps->a, min, max); //quantos elementos, no total, pertencem a esse bloco (usado como meta: "já processei todos eles?")
	pushed = 0;
	mid = (min + max) / 2; //o ponto médio do intervalo desse bloco usado logo abaixo pra decidir se um elemento recém-empurrado deve ser "empurrado mais fundo" em b ou não.(então esse é o codigo para empurrar mais fundo ? dorei)
	while (pushed < total)
	{
		if (top_is_in_range(ps, min, max)) //se o elemento no topo agora pertence a esse bloco:
		{
			op_pb(ps, 1); // empurra ele pra b.
			pushed++;
			if (ps->b && ps->b->index <= mid)
				op_rb(ps, 1);
		}
		else
			op_ra(ps, 1);
	}
}

