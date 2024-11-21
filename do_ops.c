/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:36:07 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/21 17:16:11 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	
	if (*stack_a && *stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	
	
	

}

void sa(t_list **stack_a)
{
	t_list *temp;
	
	if (*stack_a && (*stack_a)->next)
	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a);
	stack_a = temp;


}

void pb(t_list **stack_a, t_list **stack_b)
{
	
}

void sb(t_list **stack_b)
{
	t_list *temp;
	if (*stack_b && (*stack_b)->next)
	temp = (*stack_b)->next;
	(*stack_b)->next = (*stack_b);
	stack_b = temp;

}
void ss(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	
	if (*stack_a && (*stack_a)->next)
	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a);
	stack_a = temp;
	
	if (*stack_b && (*stack_b)->next)
	temp = (*stack_b)->next;
	(*stack_b)->next = (*stack_b);
	stack_b = temp;
	
}

void ra(t_list **stack_a)
{
	
}

void rra(t_list **stack_a)
{
	
}

void rb(t_list **stack_b)
{
	
}

void rrb(t_list **stack_b)
{
	
}
void rr(t_list **stack_a, t_list **stack_b)
{
	
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	
}

