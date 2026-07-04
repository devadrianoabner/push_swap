#include "push_swap.h"

static void	selection_sort_loop(t_ps *ps) //o coração do algoritmo O(n²) (aqui  voce se organiza que o choro vem))
{
	int	i;
	int	total;
	int	min_pos;

	total = ps->size_a; //guarda o tamanho original numa variável separada, antes de começar o loop. Isso é importante: ps->size_a vai diminuir a cada op_pb(op_pb faz ps->size_a--)
	i = 0;
	while (i < total - 1)
	{
		min_pos = find_min_pos(ps->a); //acha a posição do menor elemento que ainda está em a
		rotate_to_top_a(ps, min_pos); //gira a até esse elemento chegar no topo, pelo caminho mais curto
		op_pb(ps, 1); // empurra esse elemento (agora no topo) pra b
		i++;
	}
	while (ps->b)
		op_pa(ps, 1);
} 
//while (ps->b) op_pa(ps, 1);
// depois do loop principal, b está cheia com todos os elementos exceto o último que sobrou em a, empilhados na ordem em que foram inseridos:
// como sempre pegamos o menor restante de cada vez e empurramos pra b, o primeiro a ser empurrado foi o menor de todos e como pilha é LIFO ("último a entrar, primeiro a sair"), esse menor de todos ficou no fundo de b. Puxando de volta com op_pa repetidamente (sempre tirando o topo de b) a gente tira primeiro os maiores (que entraram por último) e por último o menor
//(que entrou primeiro e está no fundo, delicia) e cada op_pa coloca o elemento tirado no topo de a. Resultado: o menor acaba sendo o último a ser colocado em a, terminando no topo — exatamente onde ele precisa estar pra a ficar em ordem crescente


void	sort_simple(t_ps *ps)  //função "porta de entrada"  ela decide qual caminho seguir de acordo com o tamanho de a
{
	if (ps->size_a <= 1)
		return ;
	if (ps->size_a == 2)
	{
		if (ps->a->index > ps->a->next->index) //se o primeiro tem índice maior que o segundo, estão fora de ordem op_satroca eles. Se já estão em ordem, essa condição é falsa.
			op_sa(ps, 1);
		return ;
	}
	if (ps->size_a == 3) //delega pro caso especial de 3 elementos // Se chegou até aqui, size_a é 4 ou mais: selection_sort_loop(ps); — usa o algoritmo genérico.
	{
		sort_three(ps);
		return ;
	}
	selection_sort_loop(ps);
}
