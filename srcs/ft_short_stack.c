/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:42:53 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/17 17:42:55 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			swap_a(stack_a);
	}
	else if (size == 3)
		ft_algomini(stack_a);
	else if (size == 4)
		ft_algofour(stack_a, stack_b, size);
	else if (size == 5)
		ft_algofive(stack_a, stack_b, size);
	else if (size == 6)
		ft_algosix(stack_a, stack_b, size);
}
