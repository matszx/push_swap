# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcygan <mcygan@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 12:09:46 by mcygan            #+#    #+#              #
#    Updated: 2025/05/07 14:38:44 by mcygan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CHECKER			=	checker

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRC_DIR			=	src/
SRC_FILES		=	main.c \
					init.c \
					lis.c \
					sort.c \
					utils.c \
					stackfish.c \
					stackfish_utils.c \
					split.c \
					push.c \
					swap.c \
					rotate.c \
					rrotate.c
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

BONUS_DIR		=	bonus/
BONUS_FILES		=	checker_bonus.c \
					init_bonus.c \
					utils_bonus.c \
					gnl_bonus.c \
					gnl_utils_bonus.c \
					split_bonus.c \
					ops_bonus.c
BONUS			=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))

OBJ_DIR			=	obj/
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
OBJ_BONUS		=	$(addprefix $(OBJ_DIR), $(BONUS_FILES:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@echo "# compiling push_swap"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "# push_swap ready"

bonus: $(OBJ_DIR) $(CHECKER)

$(CHECKER): $(OBJ_BONUS)
	@echo "# compiling checker"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(CHECKER)
	@echo "# checker ready"

$(OBJ_DIR):
	@echo "# creating object directory"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "# cleaning up"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "# removing binaries"
	@rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re