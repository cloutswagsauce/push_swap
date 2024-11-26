/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:52 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/26 23:00:22 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
#include <stdio.h>

void free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	char **split_argv;

	split_argv = 0;
	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
		return (1);
	if ((argc == 2) && !(argv[1][0]))
	{
		write(2, "Error\n", 6);
        return (1);
	}
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (1);
		if(!init_stack(&stack_a, split_argv))
		{
			free_split(split_argv);
			free_stack(&stack_a);
			return (1);
		}
		free_split(split_argv);
	}
	 else
    {
        if (!init_stack(&stack_a, ++argv))
        {
            free_stack(&stack_a);
            return (1);
        }
    }
	if (!is_sorted(stack_a) && stack_a)
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
