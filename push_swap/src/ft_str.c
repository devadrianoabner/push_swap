/*
ft_putstr_fd/ft_putnbr_fd — as "versões caseiras" de imprimir texto e número, porque printf não é permitido; usam write byte a byte.

ft_strcmp — comparação de strings usada em toda checagem de flag

ft_atoi_safe — conversão de texto pra int, com checagem de overflow feita dígito a dígito, aplicando o sinal antes de comparar contra os limites.

Padrão que se repete: quando uma função precisa "devolver mais de uma coisa", ela usa return pra uma (geralmente "deu certo?") e ponteiros de saída (int *i, long *n, int *result) pras outras.*/

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd) //escrever uma string num file descriptor
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strlen(char *s) //tamanho de uma string
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2) //comparar duas strings
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
