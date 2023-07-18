# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 18:46:43 by hcho2             #+#    #+#              #
#    Updated: 2023/07/18 14:51:37 by hcho2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

SRCDIR		= ./src
BSRCDIR		= ./bsrc
LIBFT		= ./libft/libft.a
SRC			= path.c pipex.c
BSRC		= path_bonus.c pipex_bonus.c

SRC			:= $(addprefix $(SRCDIR)/, $(SRC))
BSRC		:= $(addprefix $(BSRCDIR)/, $(BSRC))
OBJ			= $(SRC:.c=.o)
BOBJ		= $(BSRC:.c=.o)

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:		$(NAME)


$(NAME): 	$(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
		@echo $(GREEN)"\n============================================================\n" $(EOC)
		@echo $(YELLOW)"                        PIPEX DONE                          " $(EOC)
		@echo $(GREEN)"\n============================================================\n" $(EOC)

bonus:		$(BOBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(LIBFT) $(BOBJ) -o $(NAME)
		@touch $@
		@echo $(GREEN)"\n============================================================\n" $(EOC)
		@echo $(YELLOW)"                        BONUS DONE                          " $(EOC)
		@echo $(GREEN)"\n============================================================\n" $(EOC)

$(LIBFT):
		@make --no-print-directory -C ./libft

%.o: 		%.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ) $(BOBJ)
		@echo $(GREEN)"\n============================================================\n" $(EOC)
		@echo $(YELLOW)"                       PIPEX CLEAN                          " $(EOC)
		@echo $(GREEN)"\n============================================================\n" $(EOC)

fclean:		clean
		@$(RM) $(NAME)
		@echo $(GREEN)"\n============================================================\n" $(EOC)
		@echo $(YELLOW)"                      PIPEX FCLEAN                          " $(EOC)
		@echo $(GREEN)"\n============================================================\n" $(EOC)

re:			fclean all

.PHONY:		clean fclean re
