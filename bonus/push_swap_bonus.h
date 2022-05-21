/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:26:10 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/18 11:32:05 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../LIBFT/libft.h"

typedef struct s_stack
{
	int				index;
	int				number;
	int				max_num;
	struct s_stack	*next;
}					t_stack;

t_stack		*create_new_node(void);
t_stack		*init_stack_a(int size);
int			int_checker(char *item);
int			duplicates_checker(t_stack **stack, int size);
int			check_int_overflow(char *item);
int			check_len(char *item);
int			get_stack(char **args, t_stack **stack_a, int argc);
void		error_message(t_stack **stack_a);
void		free_array(char **items);
void		free_stack(t_stack **stack);
int			already_sorted(t_stack **stack_a);
int			*get_array(t_stack *stack, int size);
int			*sort_array(t_stack **stack, int size);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_a_b(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		reverse_rotate(t_stack **stack, char letter);
void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		short_stack(t_stack **stack_a, t_stack **stack_b, int size);
void		radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
int			check_bit_i(int num, int i);
int			get_bits(int max_num);
void		bits_to_b(t_stack **stack_a, t_stack **stack_b, int bits, int size);
void		ft_algo2(t_stack **stack_a);
void		ft_algomini(t_stack **stack_a);
void		ft_algofour(t_stack **stack_a, t_stack **stack_b, int size);
void		ft_algofive(t_stack **stack_a, t_stack **stack_b, int size);
void		ft_algosix(t_stack **stack_a, t_stack **stack_b, int size);
void		sort_five_numbers(t_stack **stack_a, t_stack **stack_b);
void		ft_reverse(t_stack **stack_a, int size);

#endif
