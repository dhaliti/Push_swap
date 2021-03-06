/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:11:05 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/16 16:11:07 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_a;
	t_stack	*from_b;
	t_stack	*tmp;

	to_a = *stack_a;
	from_b = *stack_b;
	if (!from_b)
		return ;
	tmp = from_b;
	from_b = from_b->next;
	*stack_b = from_b;
	if (!to_a)
	{
		to_a = tmp;
		to_a->next = NULL;
		*stack_a = to_a;
	}
	else
	{
		tmp->next = to_a;
		*stack_a = tmp;
	}
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	to = *stack_b;
	from = *stack_a;
	if (!from)
		return ;
	tmp = from;
	from = from->next;
	*stack_a = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*stack_b = to;
	}
	else
	{
		tmp->next = to;
		*stack_b = tmp;
	}
	ft_putendl_fd("pb", 1);
}
