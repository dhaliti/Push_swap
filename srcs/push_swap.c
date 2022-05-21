/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:02:55 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/17 12:29:56 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(t_stack **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if ((argc - 1) < 1)
		exit (0);
	size = get_stack(argv, &stack_a, argc);
	if (duplicates_checker(&stack_a, size))
		error_message(&stack_a);
	stack_b = NULL;
	if (already_sorted(&stack_a))
		return (0);
	if (size <= 5)
		short_stack(&stack_a, &stack_b, size);
	if (size > 5)
		radix_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
