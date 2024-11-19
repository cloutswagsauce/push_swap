/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:20:52 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/19 17:33:06 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*int is_sorted(t_stack *nbs)
{
	return (0);
	
}*/

int main(int ac, char **av)
{
	if (ac == 1)
		return 0 ;
	if (ac == 2)
		handle_input_str(av[1]);
	//if (ac > 2)
		//handle_input_int();
	return (0);
	
}