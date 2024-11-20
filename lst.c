/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:33 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/20 14:17:19 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	len;

	if (!lst)
		return (0);
	i = 0;
	len = ft_lstsize(lst) - 1;
	while (i <= len && lst)
	{
		i ++;
		lst = lst -> next;
	}
	return (lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	last = ft_lstlast(*lst);
	
	if (!last)
		*lst = new;
	else
		last -> next = new;
}

/*void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	// to be edited, must clean up all members of list
	t_list	*temp_next;
	t_list	*p_lst;

	p_lst = *lst;
	while (p_lst)
	{
		temp_next = p_lst -> next;
		del(p_lst -> nbr);
		free(p_lst);
		p_lst = temp_next;
	}
	*lst = 0;
} */

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

t_list	*ft_lstnew(int nbr)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node -> nbr = nbr;
	new_node -> next = 0;
	return (new_node);
}