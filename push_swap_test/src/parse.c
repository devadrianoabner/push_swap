/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 00:38:36 by bramos            #+#    #+#             */
/*   Updated: 2026/07/14 01:40:00 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	append_node(t_stack **head, t_stack **tail, int val)
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

int	parse_args(t_ps *ps, int argc, char **argv, int start)
{
	t_stack	*head;
	t_stack	*tail;

	head = NULL;
	tail = NULL;
	if (!parse_argv_loop(argc, argv, start, &head, &tail))
		return (0);
	ps->a = head;
	ps->size_a = stack_size(ps->a);
	assign_indices(ps);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
