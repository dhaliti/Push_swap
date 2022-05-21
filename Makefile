# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 01:08:17 by dhaliti           #+#    #+#              #
#    Updated: 2022/03/18 11:46:03 by dhaliti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS		= 	srcs/push_movements.c \
				srcs/push_swap.c \
				srcs/rotate_movements.c \
				srcs/ft_short_stack.c \
				srcs/radix_sort.c \
				srcs/bits_utils.c \
				srcs/ft_get_stack.c \
				srcs/swap_moves.c \
				srcs/ft_free.c \
				srcs/ft_check.c \
				srcs/ft_array.c \
				srcs/sort_two_three.c \
				srcs/sort_four_five_six.c

BONUS_SRCS	= 	bonus/push_movements_bonus.c \
				bonus/push_swap_bonus.c \
				bonus/rotate_movements_bonus.c \
				bonus/ft_get_stack_bonus.c \
				bonus/swap_moves_bonus.c \
				bonus/ft_free_bonus.c \
				bonus/ft_check_bonus.c \
				bonus/ft_array_bonus.c \


NAME		= push_swap
BONUS		= checker
OBJS_DIR	= objs/
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(BONUS_SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) ./LIBFT/libft.a -fsanitize=address -fno-omit-frame-pointer
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

$(BONUS): $(OBJS_BONUS) maker
		$(CC) $(CC_FLAGS) $(OBJS_BONUS) ./LIBFT/libft.a -o $(BONUS) -fsanitize=address -fno-omit-frame-pointer

all: $(NAME)

bonus : $(BONUS)

maker:
	@make -C ./LIBFT

clean:
	@make clean -C ./LIBFT
	@rm -rf $(OBJS_BONUS)
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	@make fclean -C ./LIBFT
	rm -rf $(BONUS)
	@rm -rf $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

.PHONY:		all clean fclean re
