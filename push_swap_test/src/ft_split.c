/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 07:43:00 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/11 07:43:38 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
