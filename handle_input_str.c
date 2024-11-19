/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:34:51 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/19 17:36:40 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int check_input(int *nbs, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j+ i < size)
		{
			if (nbs[j + i] == nbs[i])
				return (0);
			j++;
		}
		i++;
	}
	printf("%d", size);
	return size;
}
void handle_input_str(char *str)
{
	char **nbrs_char;
	int	*nbs;
	int	i;
	
	nbrs_char = ft_split(str, ' ');
	i = 0;
	while (*nbrs_char[i])
		i++;
	nbs = (int *)malloc(sizeof(int) * i);
	check_input(nbs, i);
	
	
	
	
	
	
}