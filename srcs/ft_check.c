/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:25:16 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/17 14:39:36 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_checker(char *item)
{
	int	i;

	i = 0;
	if (item[i] == '-' || item[i] == '+')
		i++;
	while (item[i])
	{
		if ((!ft_isdigit(item[i])))
			return (0);
		i++;
	}
	if ((i > 1 && !ft_isdigit(item[1])) || (i == 1 && !ft_isdigit(item[0])))
		return (0);
	return (1);
}

int	duplicates_checker(t_stack **stack, int size)
{
	int		*array;
	int		i;

	array = sort_array(stack, size);
	i = 0;
	while (i < size)
	{
		if (array[i] == array[i + 1])
		{
			free(array);
			return (1);
		}
		i++;
	}
	free(array);
	return (0);
}

int	check_int_overflow(char *item)
{
	if (item[0] == '-')
	{
		if (ft_atoi(item) > 0)
			return (1);
	}
	if (item[0] != '-')
	{
		if (ft_atoi(item) < 0)
			return (1);
	}
	return (0);
}

int	check_len(char *item)
{
	int		i;

	i = 0;
	while (item[i])
		i++;
	if (i > 11)
		return (1);
	return (0);
}

int	already_sorted(t_stack **stack_a)
{
	t_stack	*stack;

	stack = *stack_a;
	while (stack->next)
	{
		if (!(stack->number < stack->next->number))
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}
