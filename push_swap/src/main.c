#include "push_swap.h"

static void	parse_flags(int argc, char **argv, char **strategy, int *bench)
{
	int	i;

	*strategy = "Adaptive";
	*bench = 0;
	i = 1;
	while (i < argc && is_flag(argv[i]))
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			*bench = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			*strategy = "Simple";
		else if (ft_strcmp(argv[i], "--medium") == 0)
			*strategy = "Medium";
		else if (ft_strcmp(argv[i], "--complex") == 0)
			*strategy = "Complex";
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			*strategy = "Adaptive";
		i++;
	}
}

static int	count_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && is_flag(argv[i]))
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	*strategy;
	int		bench;
	int		arg_start;

	if (argc < 2)
		return (0);
	parse_flags(argc, argv, &strategy, &bench);
	arg_start = count_flags(argc, argv);
	if (arg_start >= argc)
		return (0);
	ps = (t_ps){0};
	if (!parse_args(&ps, argc, argv, arg_start))
	{
		// mensagem de erro generica demais, dar pra dizer
		// se foi numero invalido, duplicado ou overflow
		ft_putstr_fd("Erro\n", 2);
		return (1);
	}
	if (!ps.a || is_sorted(ps.a))
	{
		free_ps(&ps);
		return (0);
	}
	run_sort(&ps, strategy, bench);
	free_ps(&ps);
	return (0);
}
