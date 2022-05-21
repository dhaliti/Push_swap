/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:34:53 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/17 16:09:16 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_array2(int *array, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (++i < size)
	{
		if (array[i - 1] > array[i])
		{
			tmp = array[i - 1];
			array[i - 1] = array[i];
			array[i] = tmp;
			i = 0;
		}
	}
	return (array);
}

static void	put_index(t_stack **stack_a, int *array, int size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		i = -1;
		while (++i < size)
		{
			if (array[i] == tmp->number)
				tmp->index = i;
		}
		tmp = tmp->next;
	}
}

static void	get_index(t_stack **stack_a, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	i = -1;
	tmp = *stack_a;
	array = (int *)malloc(size * sizeof(int) + 1);
	if (!array)
		exit(0);
	while (tmp)
	{
		array[++i] = tmp->number;
		tmp = tmp->next;
	}
	array = sort_array2(array, size);
	put_index(stack_a, array, size);
	free(array);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	num_of_bits;

	i = 0;
	get_index(stack_a, size);
	num_of_bits = get_bits(size);
	while (i <= num_of_bits)
	{
		bits_to_b(stack_a, stack_b, i, size);
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
