/*As 11 operações estão nos arquivos : rotate_utils.c, operations_swap.c, operations_push.c, operations_rotate.c, operations_rrotate.c*
 as funções que executam de verdade as 11 operações. TÁ PASSADA ? */

#include "push_swap.h"

void	list_rotate_up(t_stack **stack) //o primeiro elemento vira o último
{
	t_stack	*tmp; 
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack; // tmp aponta pro nó "3"
	*stack = (*stack)->next; // *stack (o topo oficial) agora é o nó "7"
	tmp->next = NULL; // por seguranç, o "3" não aponta pra mais nada por enquanto
	last = *stack; // // last começa no "7"
	while (last->next) // // anda até não ter mais próximo
		last = last->next;  // nesse ponto, last aponta pro "1" (o último nó de [7, 1])
	last->next = tmp;  // o "1" agora aponta pro "3"
}
// Resultado final: [7, 1, 3] — o 3, que era o primeiro, agora é o último. Exatamente o que "rodar pra cima" significa: "o primeiro elemento se torna o último")
// amou ? não? então surta bb, porque aturar voce É obrigada.

void	list_rotate_down(t_stack **stack) //o último elemento vira o primeiro
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
} 
//O caminho inverso do anterior. Usando de novo [3, 7, 1]: 
// Resultado final: [1, 3, 7] — o 1, que era o último, virou o primeiro. Isso é "rodar pra baixo". 

// Na arte do s->exo Pode crer que eu exculacho faço tudo que ele gosta e pra ele eu fico de cabeça pra baixo Quero ver tu aguentar)
