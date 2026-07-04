//Conta pares "fora de ordem" (cur->value > cmp->value) dividido pelo total de pares possíveis.
// O detalhe crucial do loop: cmp sempre começa em cur->next, não no início da lista — isso garante que cada par seja contado uma única vez, na ordem original.
// Os casts pra double na divisão final são obrigatórios — sem eles, C faria divisão inteira e o resultado sempre daria 0 ou 1, nunca uma fração de verdade.

#include "push_swap.h"

double	compute_disorder(t_stack *stack, int size)
{
	t_stack	*cur;
	t_stack	*cmp;
	long	mistakes;
	long	total_pairs;

	if (!stack || size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	cur = stack;
	while (cur)
	{
		cmp = cur->next;  //// <-- começa em cur->next, não em stack
		while (cmp)
		{
			total_pairs++;
			if (cur->value > cmp->value)
				mistakes++;
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
//lista [5, 4, 3, 2, 1] (ordem inversa completa). 
// Todo par tem o primeiro maior que o segundo "mistakes" vai ser exatamente igual a total_pairs. 
// Resultado: mistakes / total_pairs = 1.0 = 100% de desordem