/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:18:23 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/25 16:24:35 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void min_on_top(t_list **stack_a)
{
	while ((*stack_a)->nbr != find_min(*stack_a)->nbr)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void set_target_b(t_list **stack_a, t_list **stack_b)
{
	t_list *current_a;
	t_list *target_node;
	long best_match;

	while (*stack_b)
	{
		best_match = LONG_MAX;
		current_a = *stack_a;
		while (current_a)
		{
			if (current_a->nbr > (*stack_a)->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			(*stack_b)->target = find_min((*stack_a));
		else
			(*stack_b)->target = target_node;
		(*stack_b) = (*stack_b)->next;
	}
}

t_list *get_cheapest(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (0);
}
static void move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list *cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (!cheapest_node)
		printf("failed to find cheapest");
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!cheapest_node->above_median && !(cheapest_node->target->above_median))
		rrr(stack_a, stack_b);
	push_prep(stack_a, cheapest_node, 'a');
	push_prep(stack_a, cheapest_node->target, 'b');
	pb(stack_a, stack_b);
}

static void move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	push_prep(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}

void sort_stack(t_list **stack_a, t_list **stack_b)
{
	int len;

	len = ft_lstsize(*stack_a);
	if (len-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(stack_a, stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_indexes(*stack_a);
	min_on_top(stack_a);
}