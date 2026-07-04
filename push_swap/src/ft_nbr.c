#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd((int)(nb / 10), fd);
	c = (char)('0' + nb % 10);
	write(fd, &c, 1);
}
/*Exemplo de execução pra ft_putnbr_fd(123, 1):

chamada 1: nb=123, nb>=10, chama ft_putnbr_fd(12, 1) ANTES de escrever nada
  chamada 2: nb=12, nb>=10, chama ft_putnbr_fd(1, 1) ANTES de escrever nada
    chamada 3: nb=1, nb<10, NÃO chama recursivamente. escreve '1'.
  (voltando pra chamada 2): escreve '2'
(voltando pra chamada 1): escreve '3'
Resultado impresso, na ordem real: 1, depois 2, depois 3 → "123", exatamente na ordem certa, mesmo a função "pensando" do fim pro começo.*/