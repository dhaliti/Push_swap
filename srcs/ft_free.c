/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:25:50 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/05 15:25:52 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **items)
{
	int	i;

	i = 0;
	while (items[i])
	{
		free(items[i]);
		i++;
	}
	free(items);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*delete;

	tmp = *stack;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->next;
		free(delete);
	}
	*stack = NULL;
}
