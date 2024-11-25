/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:40:18 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/25 13:56:52 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

t_list *find_min(t_list *stack)
{
	long min;
	t_list *min_node;

	min = LONG_MAX;
	while (stack)
	{
		if ((stack)->nbr < min)
		{
			min = (stack)->nbr;
			min_node = stack;
		}
			
		stack = (stack)->next;
	}
	return (min_node);
}

void rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rr(stack_a, stack_b);
	set_indexes(*stack_a);
	set_indexes(*stack_b);
}

void reverse_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target)
		rrr(stack_a, stack_b);
	set_indexes(*stack_a);
	set_indexes(*stack_b);
}

void push_prep(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
			rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
