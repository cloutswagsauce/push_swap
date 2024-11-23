/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:52 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/23 10:11:43 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "push_swap.h"
# include <stdio.h>

void add_node(int nbr, t_list **stack_a)
{
	t_list *new_node;
	
	new_node = ft_lstnew(nbr);
	if (!new_node)
		return ;
	ft_lstadd_back(stack_a, new_node);

	
}

int main(int argc, char **argv)
{
	int i;
	t_list *stack_a;
	t_list *curr;
	
	stack_a = 0;

	i = 1;
	while (i < argc)
	{
		add_node(ft_atoi(argv[i]), &stack_a);
		i ++;
	}
	sort_three(&stack_a);
	
	curr = stack_a;
	while(curr)
	{
		printf("%d", curr->nbr);
		curr = curr->next;
	}
	printf("stack size: %d", ft_lstsize(stack_a));
	
	
}