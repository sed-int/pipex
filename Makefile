# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 18:46:43 by hcho2             #+#    #+#              #
#    Updated: 2023/07/03 13:06:40 by hcho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR		= ./src
SRC			= ft_split.c get_next_line.c get_next_line_utils_bonus.c path.c pipex.c utils.c
BSRC		= ft_split.c get_next_line.c get_next_line_utils_bonus.c path.c pipex.c utils.c

SRC			:= $(addprefix $(SRCDIR)/, $(SRC))
BSRC		:= $(addprefix $(SRCDIR)/, $(BSRC))
OBJ			= $(SRC:.c=.o)
BOBJ		= $(BSRC:.c=.o)

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:		$(NAME)


$(NAME): 	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus:		$(BOBJ)
			@$(CC) $(CFLAGS) $(BOBJ) -o $(NAME)
			@touch $@

%.o: 		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ) $(BOBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all bonus

.PHONY:		clean fclean re
