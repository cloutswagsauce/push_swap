/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:57:47 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/25 17:50:36 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_cheapest(t_list *stack)
{
	// ok
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	  t_list *current = stack;
    while (current)
    {
        current->cheapest = 0;
        current = current->next;
    }
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node-> cheapest = 1;
	
}
void init_nodes_b(t_list **stack_a, t_list **stack_b)
{
	// ok
	set_indexes(*stack_a);
	set_indexes(*stack_b);
	set_target_b(stack_a, stack_b);
}

void init_nodes_a(t_list **stack_a, t_list **stack_b)
{
	//ok
	printf("init nodes");
	set_indexes(*stack_a);
	set_indexes(*stack_b);
	set_target_a(stack_a, stack_b);
	cost_check(*stack_a, *stack_b);
	set_cheapest(*stack_a);
	
}
void add_node(int nbr, t_list **stack_a)
{
	t_list *new_node;
	
	new_node = ft_lstnew(nbr);
	if (!new_node)
		return ;
	ft_lstadd_back(stack_a, new_node);
}

int init_stack(t_list **stack_a, char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		add_node(ft_atoi(argv[i++]), stack_a);
	return (0);
}
