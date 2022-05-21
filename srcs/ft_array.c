/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:25:26 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/16 16:22:32 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_array(t_stack *stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = stack;
	i = 0;
	array = malloc(sizeof(int) * (size + 1));
	if (!(array))
		return (0);
	while (tmp)
	{
		array[i++] = tmp->number;
		tmp = tmp->next;
	}
	return (array);
}

int	*sort_array(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		temp;
	int		i;

	tmp = *stack;
	array = get_array(tmp, size);
	i = 0;
	while (size > 1)
	{
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
			i++;
		}
		size--;
		i = 0;
	}
	return (array);
}
