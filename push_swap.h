/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:14:25 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/26 20:32:51 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LONG_MIN -2147483648
# define LONG_MAX 2147483647
typedef	struct	s_list
{
	int				nbr;
	int				index;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;	
	int				above_median;
	int				cheapest;
	struct s_list	*prev;
	
	
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
int		is_sorted(t_list *stack);
int		init_stack(t_list **stack_a, char **argv);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	set_indexes(t_list *stack);
void	push_prep(t_list **stack, t_list *top_node, char stack_name);
void	init_nodes_a(t_list **stack_a, t_list **stack_b);
t_list 	*find_min(t_list *stack);
void	find_cheapest(t_list *stack);
void	cost_check(t_list *stack_a, t_list *stack_b);
void	set_target_a(t_list **stack_a, t_list **stack_b);
int		validate_input(char *str, t_list *stack_a);
void	free_stack(t_list **stack);



#endif