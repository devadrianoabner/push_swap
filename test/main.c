/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:39:25 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/06 15:12:25 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//////////////// STRUCTS ////////////////
typedef struct	s_node
{
	int				value;
	int				index;
	struct s_node	*next;
} t_node;

typedef struct	s_ps
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	op_sa;
	int	total_ops;
} t_ps;
//////////////// STRUCTS ////////////////

//////////////// LIB_FT ////////////////
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (n > i)
	{
		ptr[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

static	char	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

long long	ft_atol(const char *nptr)
{
	size_t		i;
	long long	result;
	int			sing;

	i = 0;
	sing = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sing = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sing);
}
//////////////// SPLIT ////////////////
static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	return (len);
}

static char	**ft_free_all(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (NULL);
}

static char	**ft_make_split(char const *s, char c, char **str)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			len = ft_get_word_len(s, c);
			str[i] = malloc(sizeof(char) * (len + 1));
			if (!str[i])
				return (ft_free_all(str, i));
			ft_strlcpy(str[i], s, len + 1);
			i++;
			s = s + len;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	return (ft_make_split(s, c, str));
}
//////////////// SPLIT ////////////////

//////////////// LIB_FT ////////////////

//////////////// DEBUG ////////////////
void	print_stack(t_node *stack_a)
{
	if (!stack_a)
	{
		printf("Nenhuma pilha foi formada");
		return ;
	}
	while (stack_a != NULL)
	{
		printf("Indice: %d | Valor %d\n", stack_a->index, stack_a->value);
		stack_a = stack_a->next;
	}
}
//////////////// DEBUG ////////////////

//////////////// DELL ////////////////
void	free_vector(char **vector)
{
	int	i;

	if (!vector)
		return ;
	i = 0;
	while (vector[i])
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}

void free_stack(t_node *stack)
{
	t_node *temp;

	if (!stack)
		return ;
	while(stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
//////////////// DELL ////////////////

//////////////// PARSING ////////////////
int	is_valid(char *str)
{
	int	i;
	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
int	has_duplicate(t_ps *push_swap, int temp_num)
{
	t_node	*stack;

	if (!push_swap->stack_a)
		return (0);
	stack = push_swap->stack_a;
	while(stack != NULL)
	{
		if (stack->value == temp_num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
void	init_stack_a(t_ps *push_swap, int argc, char **argv)
{
	int			i;
	char		**param;
	long long	temp_num;

	if (argc == 2)
	{
		param = ft_split(argv[1], ' ');
		if (param == NULL)
		{
			free(param);
			return ;
		}
	}
	param = argv + 1;
	i = 0;
	while (param[i])
	{
		if (!is_valid(param[i]))
			return ;
		temp_num = ft_atol(param[i]);
		if (temp_num > INT_MAX || temp_num < INT_MIN)
			return ;
		add_node_list(push_swap, new_node(temp_num));
		i++;
	}
}
//////////////// PARSING ////////////////
t_node *new_node(int value)
{
	t_node	*new_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		return (NULL);
	new_node->value = value;
	return (new_node);
}

void	add_node_list(t_ps *stack, t_node *next_node)
{
	t_node *temp;

	if (!stack || !next_node)
		return ;
	temp = stack->stack_a;
	if (stack->stack_a == NULL)
	{
		stack->stack_a = next_node;
		next_node->index = 0;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = next_node;
	next_node->index = temp->index + 1;
}

int	main(int argc, char **argv)
{
	t_ps	push_swap;

	ft_bzero(&push_swap, sizeof(t_ps));
	if (argc <= 1)
		return (0);
	init_stack_a(&push_swap, argc, argv);
	print_stack(push_swap.stack_a);
	return (0);
}
// gcc -Wall -Wextra -Werror main.c