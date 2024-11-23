/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:36:07 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/23 10:38:11 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	write(1, "pa\n", 3);
}

void sa(t_list **stack_a)
{
	t_list *temp;
	if (*stack_a && (*stack_a)->next)
	{
		// set temp to the second
		temp = (*stack_a)->next;

		// set first's next pointer to the third node
		(*stack_a)->next = temp->next;

		// set temp's next to be the first
		temp->next = *stack_a;

		// set first node to the second 
		*stack_a = temp;
		
		write(1, "sa\n", 3);
	}

}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	
	if (*stack_a && *stack_b)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_a = temp;
	}
	write(1, "pb\n", 2);
	
}

void sb(t_list **stack_b)
{
	t_list *temp;
	if (*stack_b && (*stack_b)->next)
	{
		// set temp to the second
		temp = (*stack_b)->next;

		// set first's next pointer to the third node
		(*stack_b)->next = temp->next;

		// set temp's next to be the first
		temp->next = *stack_b;

		// set first node to the second 
		*stack_b = temp;
		
		write(1, "sb\n", 3);
	}
}

void ss(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	if (*stack_a && (*stack_a)->next)
	{
		// set temp to the second
		temp = (*stack_a)->next;

		// set first's next pointer to the third node
		(*stack_a)->next = temp->next;

		// set temp's next to be the first
		temp->next = *stack_a;

		// set first node to the second 
		*stack_a = temp;
	}
	
	
	if (*stack_b && (*stack_b)->next)
	{
		// set temp to the second
		temp = (*stack_b)->next;

		// set first's next pointer to the third node
		(*stack_b)->next = temp->next;

		// set temp's next to be the first
		temp->next = *stack_b;

		// set first node to the second 
		*stack_b = temp;
		
	}
	write(1, "sssa\n", 4);
	
	
}

void ra(t_list **stack_a)
{
	// every node gets pushed up, first becomes last 
	t_list *temp;
	t_list *last;
	int size;

	size = ft_lstsize(*stack_a);

	if (size < 2)
		return ;

	last = ft_lstlast(*stack_a);
	
	if (*stack_a)
	{
		temp = (*stack_a);
		*stack_a = (*stack_a)->next;
		last->next = temp;
		temp->next = 0;
		
	}
	write(1, "ra\n", 3);
}

void rra(t_list **stack_a)
{
	// every node gets pushed down, last becomes first
	t_list	*temp;
	t_list	*before_last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	before_last = *stack_a;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	temp = ft_lstlast(*stack_a);
	before_last->next = 0;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "rra\n", 4);
		
	}
	


void rb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;

	last = ft_lstlast(*stack_b);

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		last->next = temp;
		temp->next = 0;
	}
	write(1, "rb\n", 3);
	
}

void rrb(t_list **stack_b)
{
	t_list *temp;
	t_list *before_last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	before_last = *stack_b;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	temp = ft_lstlast(*stack_b);
	before_last->next = 0;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "rrb\n", 4);
		
		
}
void rr(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	t_list *last;
	int size;

	size = ft_lstsize(*stack_a);

	if (size < 2)
		return ;

	last = ft_lstlast(*stack_a);
	
	if (*stack_a)
	{
		temp = (*stack_a);
		*stack_a = (*stack_a)->next;
		last->next = temp;
		temp->next = 0;
		
	}
	last = ft_lstlast(*stack_b);

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		last->next = temp;
		temp->next = 0;
	}
	write(1, "rr\n", 3);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;
	t_list *before_last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	before_last = *stack_a;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	temp = ft_lstlast(*stack_a);
	before_last->next = 0;
	temp->next = *stack_a;
	*stack_a = temp;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	before_last = *stack_b;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	temp = ft_lstlast(*stack_b);
	before_last->next = 0;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "rrr\n", 4);
	
	
}

