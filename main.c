/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:52 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/25 15:49:46 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *curr;

	stack_a = 0;
	stack_b = 0;
	(void)argc;
	init_stack(&stack_a, ++argv);
	if (!is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}

	curr = stack_a;
	while (curr)
	{
		printf("%d ", curr->nbr);
		curr = curr->next;
	}
	printf("stack size: %d", ft_lstsize(stack_a));
}