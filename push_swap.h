/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:14:25 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/23 10:04:47 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct	s_list
{
	int				nbr;
	int				cost;
	int				*target;
	struct s_list	*next;	
	
}				t_list;

# include "includes/libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int nbr);
void	pa(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rrb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **list);






#endif