/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:02:55 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/18 11:39:29 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_message(t_stack **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit (0);
}

static void	free_bonus(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

static void	do_operations(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(line, "pa", 2) == 0)
		push_a(stack_a, stack_b);
	if (ft_strncmp(line, "pb", 2) == 0)
		push_b(stack_a, stack_b);
	if (ft_strncmp(line, "sa", 2) == 0)
		swap_a(stack_a);
	if (ft_strncmp(line, "sb", 2) == 0)
		swap_b(stack_b);
	if (ft_strncmp(line, "ss", 2) == 0)
		swap_a_b(stack_a, stack_b);
	if (ft_strncmp(line, "ra", 2) == 0)
		rotate_a(stack_a);
	if (ft_strncmp(line, "rb", 2) == 0)
		rotate_b(stack_b);
	if (ft_strncmp(line, "rra", 3) == 0)
		reverse_rotate(stack_a, 'a');
	if (ft_strncmp(line, "rrb", 3) == 0)
		reverse_rotate(stack_b, 'b');
	if (ft_strncmp(line, "rrr", 3) == 0)
		reverse_rotate_both(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	char	*line;

	if ((argc - 1) < 1)
		exit (0);
	size = get_stack(argv, &stack_a, argc);
	if (duplicates_checker(&stack_a, size))
		error_message(&stack_a);
	stack_b = NULL;
	line = get_next_line(0);
	if (line == NULL)
		error_message(&stack_a);
	while (line)
	{
		do_operations(line, &stack_a, &stack_b);
		line = get_next_line(0);
	}
	if (already_sorted(&stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_bonus(&stack_a, &stack_b);
	return (0);
}
