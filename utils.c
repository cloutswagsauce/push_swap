/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:50:47 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/25 22:14:14 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void find_cheapest(t_list *stack)
{
    t_list *current = stack;
    t_list *cheapest_node = NULL;
    long cheapest_value = LONG_MAX;
    
    // Reset cheapest flag for all nodes
    while (current)
    {
        current->cheapest = 0;
        current = current->next;
    }
    
    // Find the cheapest node
    current = stack;
    while (current)
    {
        if (current->cost < cheapest_value)
        {
            cheapest_value = current->cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    
    // Mark the cheapest node
    if (cheapest_node)
        cheapest_node->cheapest = 1;
}
void cost_check(t_list *stack_a, t_list *stack_b)
{
    int len_a = ft_lstsize(stack_a);
    int len_b = ft_lstsize(stack_b);
    
    while (stack_a)
    {
        // Reset cost
        stack_a->cost = stack_a->index;
        
        // Adjust cost based on position in stack_a
        if (!(stack_a->above_median))
            stack_a->cost = len_a - (stack_a->index);
        
        // Ensure target exists before accessing it
        if (stack_a->target)
        {
            if (stack_a->target->above_median)
                stack_a->cost += stack_a->target->index;
            else
                stack_a->cost += len_b - (stack_a->target->index);
        }
        
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
    t_list *current_a;
    t_list *target_node;
    t_list *current_b;
    long best_match;

    current_a = *stack_a;
    while (current_a)
    {
        best_match = LONG_MIN;
        current_b = *stack_b;
        target_node = NULL;

        while (current_b)
        {
            if (current_b->nbr < current_a->nbr && current_b->nbr > best_match)
            {
                best_match = current_b->nbr;
                target_node = current_b;
            }
            current_b = current_b->next;
        }

        if (best_match == LONG_MIN)
            current_a->target = find_max(*stack_b);
        else
            current_a->target = target_node;

        current_a = current_a->next;
    }
}

void set_indexes(t_list *stack)
{
    int i = 0;
    int median;

    if (!stack)
        return;

    median = ft_lstsize(stack) / 2;

    while (stack)
    {
        // Reset values
        stack->index = i;
        stack->above_median = 0;
        
        // Set above_median
        if (i <= median)
            stack->above_median = 1;
        
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