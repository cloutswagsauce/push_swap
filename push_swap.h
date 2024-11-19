/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:14:25 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/19 17:37:09 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct	s_stack
{
	int					nbr;
	struct s_node_list	*next_node;
	struct s_node_list	*prev_node;	
}				t_stack;

# include "includes/libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>

void handle_input_str(char *str);





#endif