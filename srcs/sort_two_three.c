/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:31:36 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/17 16:56:17 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_seekmax(t_stack **stack_a)
{
	int		max;
	t_stack	*tmp;
	int		i;
	int		j;

	tmp = *stack_a;
	max = tmp->number;
	i = 0;
	j = 0;
	while (tmp)
	{
		if (max < tmp->number)
		{
			max = tmp->number;
			j = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (j);
}

static void	ft_algomini2(t_stack **stack_a, int j)
{
	if (j == 1 && (*stack_a)->next->next->number > (*stack_a)->number)
	{
		reverse_rotate(stack_a, 'a');
		swap_a(stack_a);
	}
	else if (j == 1)
		reverse_rotate(stack_a, 'a');
}

void	ft_algomini(t_stack **stack_a)
{
	int	j;

	j = ft_seekmax(stack_a);
	if (j == 0 && (*stack_a)->next->number > (*stack_a)->next->next->number)
	{
		swap_a(stack_a);
		reverse_rotate(stack_a, 'a');
	}
	else if (j == 0)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (j == 2 && (*stack_a)->number > (*stack_a)->next->number)
		swap_a(stack_a);
	else
		ft_algomini2(stack_a, j);
}

void	ft_algo2(t_stack **stack_a)
{
	if ((*stack_a)->next->number < (*stack_a)->number)
		swap_a(stack_a);
}
