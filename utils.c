/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:50:47 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/25 17:49:01 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;
	
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
void cost_check(t_list *stack_a, t_list *stack_b)
{
	// ok
	int len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->cost = len_a - (stack_a->index);
		if (stack_a->target->above_median)
			stack_a->cost += stack_a->target->index;
		else
			stack_a->cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}
t_list *find_max(t_list *stack)
{
	t_list	*max_node;
	long 	max;
	
	if (!stack)
		return (0);

	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max_node = stack;
			max = stack->nbr;
		}
			
		stack = stack->next;
	}
	return (max_node);
	
}
void set_target_a(t_list **stack_a, t_list **stack_b)
{
//ok
	t_list	*target_node;
	t_list	*current_b;
	long	best_match;

	while (*stack_a)
	{
		best_match = LONG_MIN;
		current_b = *stack_b;
		while (current_b)
		{
			if (current_b->nbr < (*stack_a)->nbr
			&& current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			(*stack_a)->target = find_max(*stack_b);
		else
			(*stack_a)->target = target_node;
		(*stack_a) = (*stack_a)->next;
	}
}

void set_indexes(t_list *stack)
{
	// ok
	int	i;
	int median;

	if (!stack)
		return ;
	i = 0;
	median = ft_lstsize(stack) / 2;

	while (stack)
	{
		(stack)->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
	
}

int is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}