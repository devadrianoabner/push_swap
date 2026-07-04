/*
AQUI É ONDE TÁ O BABADO !! Esse é o arquivo que transforma argv vindo da linha de comando na lista ligada ps->a (a pilha a inicial), validando tudo no processo.

has_duplicate — percorre a lista comparando valores, O(n) por chamada.

assign_indices — loop duplo, calcula a posição relativa de cada nó O(n²) no total, roda uma vez só.

append_node — insere no fim da lista (diferente do push_node, que insere no início)

parse_args — orquestra tudo: lê cada argumento, converte, valida, insere e é onde a segunda parte da correção do leak vive (o erro de conversão de ft_atoi_safe também precisa 
liberar a lista parcial).

is_sorted — checa em O(n) se a lista já está em ordem crescente.*/

#include "push_swap.h"

static int	has_duplicate(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	assign_indices(t_ps *ps)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		idx;

	cur = ps->a;
	while (cur)
	{
		idx = 0;
		cmp = ps->a;
		while (cmp)
		{
			if (cmp->value < cur->value)
				idx++;
			cmp = cmp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
}

static int	append_node(t_stack **head, t_stack **tail, int val)
{
	t_stack	*node;

	if (has_duplicate(*head, val))
	{
		free_stack(head);
		return (0);
	}
	node = new_node(val);
	if (!node)
	{
		free_stack(head);
		return (0);
	}
	if (!*head)
		*head = node;
	else
		(*tail)->next = node;
	*tail = node;
	return (1);
}

int	parse_args(t_ps *ps, int argc, char **argv, int start) //a função principal, juntando tudo
{
	int		i;
	int		val;
	t_stack	*head;
	t_stack	*tail;

	head = NULL;
	tail = NULL;
	i = start;
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &val))
		{
			free_stack(&head);
			return (0);
		}
		if (!append_node(&head, &tail, val))
			return (0);
		i++;
	}
	ps->a = head;
	ps->size_a = stack_size(ps->a);
	assign_indices(ps);
	return (1);
}

int	is_sorted(t_stack *stack) //checando se a pilha já está ordenada
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
