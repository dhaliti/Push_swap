/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:43:02 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/18 12:05:23 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->number = 0;
	first->next = NULL;
	first->index = 0;
	return (first);
}

static int	check_argv_1(t_stack **stack_a, char **array)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	*stack_a = create_new_node();
	tmp = *stack_a;
	while (array[size])
	{
		if (!(int_checker(array[size])) || check_len(array[size]) || \
		check_int_overflow(array[size]))
			error_message(stack_a);
		tmp->number = ft_atoi(array[size]);
		if (array[size + 1])
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		size++;
	}
	return (size);
}

static int	check_argv_2(t_stack **stack_a, char **args, int argc)
{
	int		i;
	t_stack	*tmp;
	int		size;

	*stack_a = create_new_node();
	tmp = *stack_a;
	i = 1;
	size = argc - 1;
	while (i <= size)
	{
		if (check_len(args[i]) \
		|| !int_checker(args[i]) || check_int_overflow(args[i]))
			error_message(stack_a);
		tmp->number = ft_atoi(args[i]);
		if (i < size)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
	return (size);
}

int	get_stack(char **argv, t_stack **stack_a, int argc)
{
	char	**array;
	int		size;

	size = 0;
	if (argv[1] && argv[2] && ft_strchr(argv[1], ' ')
		&& ft_strchr(argv[2], ' '))
		error_message(stack_a);
	array = ft_split(argv[1], ' ');
	if (array[1])
		size = check_argv_1(stack_a, array);
	else if (!array[1])
		size = check_argv_2(stack_a, argv, argc);
	free_array(array);
	return (size);
}
