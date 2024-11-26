/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaria-m <lfaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:00:38 by lfaria-m          #+#    #+#             */
/*   Updated: 2024/11/26 18:42:18 by lfaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>

int	ft_atoi_safe(const char *str, int *error)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	*error = 0;

	// Skip whitespace
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		   *str == '\v' || *str == '\f' || *str == '\r')
		str++;

	// Handle sign
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	// Parse digits and check for overflow
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (sign * result > 2147483647 || sign * result < -2147483648)
		{
			*error = 1; // Set error flag for out-of-bounds values
			return (0);
		}
		str++;
	}

	// Check for invalid characters
	if (*str != '\0')
	{
		*error = 1; // Set error flag for non-numeric input
		return (0);
	}

	return ((int)(sign * result));
}


int is_int(char *str)
{
	int error;
	
	error = 0;
	if (ft_atoi_safe(str, &error) == 0 && error)
		return (0);
	return (1);
}
int no_duplicates(char *str, t_list *stack_a)
{
	while (stack_a)
	{
		if (stack_a->nbr == ft_atoi(str))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int all_digits(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
int validate_input(char *str, t_list *stack_a)
{

	if (str)
	{
		if (all_digits(str) && no_duplicates(str, stack_a) && is_int(str))
			return (1);
		else
		{
			free_stack_error(stack_a);
			write(2, "Error\n", 5);
			return (0);
		}
	}
	return (0);
}