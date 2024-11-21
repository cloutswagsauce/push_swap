/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:52 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/21 16:29:29 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void add_to_stack(char **str, t_list **stack_a)
{
	int size;
	int	i;
	t_list *new_node;
	
	size = 0;
	i = 0;

	while (str[size])
		size++;
	while (i < size)
	{
		new_node = ft_lstnew(ft_atoi(str[i]));
		if (!new_node)
			return ;
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	
}

int  handle_input_str(char *str, t_list **stack_a)
{
	
	char ** nbrs_str;

	nbrs_str = ft_split(str, ' ');
	
	add_to_stack(nbrs_str, stack_a);

	return (0);
	
}


int main(int ac, char **av)
{
	t_list **stack_a;
	//t_list **stack_b;
	
	
	if (ac == 1)
		return 0 ;
	stack_a = (t_list**)malloc(sizeof(t_list));
	if (ac == 2)
		handle_input_str(av[1], stack_a);
	
		
	return (0);
	
}