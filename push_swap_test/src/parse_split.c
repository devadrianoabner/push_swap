/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 07:53:38 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/11 08:34:07 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split_matrix(char **split_arr)
{
	int	i;

	i = 0;
	if (!split_arr)
		return ;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

static int	process_split_args(char **split_args, t_stack **hd, t_stack **tl)
{
	int	j;
	int	val;

	j = 0;
	while (split_args[j])
	{
		if (!ft_atoi_safe(split_args[j], &val) || !append_node(hd, tl, val))
			return (0);
		j++;
	}
	return (1);
}

int	parse_argv_loop(int argc, char **argv, int start, t_stack **hd, t_stack **tl)
{
	int		i;
	char	**split_args;

	i = start;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args || !split_args[0]
			|| !process_split_args(split_args, hd, tl))
		{
			free_split_matrix(split_args);
			free_stack(hd);
			return (0);
		}
		free_split_matrix(split_args);
		i++;
	}
	return (1);
}
