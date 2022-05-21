/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five_six.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:43:23 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/17 17:43:28 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_seekmin(t_stack **stack_a)
{
	int		i;
	int		j;
	int		min;
	t_stack	*tmp;

	i = 0;
	min = 0;
	tmp = *stack_a;
	j = tmp->number;
	while (tmp)
	{
		if (tmp->number < j)
		{
			j = tmp->number;
			min = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}

void	ft_reverse(t_stack **stack_a, int size)
{
	int	min;
	int	j;

	min = ft_seekmin(stack_a);
	j = 0;
	if (min <= size / 2)
	{
		while (j != min)
		{
			rotate_a(stack_a);
			j++;
		}
	}
	else
	{
		while (j != size - min)
		{
			reverse_rotate(stack_a, 'a');
			j++;
		}
	}
}

void	ft_algofour(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		reverse_rotate(stack_a, 'a');
		size = size - 1;
		i++;
		push_b(stack_a, stack_b);
	}
	ft_algomini(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	ft_algofive(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		ft_reverse(stack_a, size);
		size = size - 1;
		i++;
		push_b(stack_a, stack_b);
	}
	ft_algomini(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	ft_algosix(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		reverse_rotate(stack_a, 'a');
		size--;
		i++;
		push_b(stack_a, stack_b);
	}
	ft_algomini(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}
