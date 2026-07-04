/*
new_node — aloca 1 nó na heap (malloc), preenche os campos.

push_node/pop_node — usam t_stack ** porque precisam trocar qual nó é o topo da pilha vista de fora da função, não só ler/escrever dentro de um nó já existente.

stack_size/is_sorted/etc usam só t_stack * porque só leem, "andando" um cursor local sem afetar a lista de verdade.

free_stack — o cuidado de salvar next antes de dar free no nó atual é o que evita "use after free".

free_ps — atalho pra liberar as duas pilhas de uma vez.*/


#include "push_swap.h"

t_stack	*new_node(int value) //criando um nó novo
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	push_node(t_stack **stack, t_stack *node) //colocando um nó no topo de uma pilha ( lista ligada)
{
	if (!stack || !node)
		return ;
	node->next = *stack;
	*stack = node;
}
//Antes de chamar push_node(&ps->b, node_3):
/*ps->b (endereço 0x2000) guarda: 0x3000
                                    |
                                    v
                        0x3000: [value=7, next=NULL]

node (parâmetro "node", que é node_3, endereço 0x4000):
                        0x4000: [value=3, next=NULL]  (ainda solto, não encadeado)
________________________________________________________________________________________
						Depois da função:

ps->b (0x2000) agora guarda: 0x4000
                                 |
                                 v
                     0x4000: [value=3, next=0x3000]
                                                |
                                                v
                                    0x3000: [value=7, next=NULL]*/

t_stack	*pop_node(t_stack **stack) //tirando o nó do topo (lista ligada)
{
	t_stack	*node;

	if (!stack || !*stack)
		return (NULL);
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	return (node);
}

int	stack_size(t_stack *stack) //contando quantos nós tem na lista
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack) //liberando a lista inteira ( lista ligada)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
