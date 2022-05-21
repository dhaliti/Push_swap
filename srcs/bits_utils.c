/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:34:53 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/17 15:41:04 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bit_i(int num, int i)
{
	return ((num >> i) & 1);
}

int	get_bits(int max_num)
{
	int	i;

	i = 31;
	while (check_bit_i(max_num, i) != 1)
		i--;
	return (i);
}

void	bits_to_b(t_stack **stack_a, t_stack **stack_b, int bits, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (check_bit_i((*stack_a)->index, bits) == 0)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		if (already_sorted(stack_a))
			break ;
		i++;
	}
}
