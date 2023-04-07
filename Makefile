# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 14:11:55 by araji-af          #+#    #+#              #
#    Updated: 2023/04/03 18:20:13 by araji-af         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = actions.c actions2.c fractals.c main.c tools.c tools2.c tools3.c

SRCS_B = bonus/fractals.c bonus/actions.c bonus/actions2.c bonus/main.c bonus/tools.c bonus/tools2.c

NAME = fractol

NAME_B = fractol_bonus

OBJ = $(SRCS:.c=.o)

OBJ_B = $(SRCS_B:.c=.o)

FLAGS = -Wall -Wextra -Werror -Imlx

GFLAGS = OpenGL -framework AppKit


bonus/%.o : bonus/%.c bonus/header.h
	cc $(FLAGS) -c $< -o $@
%.o : %.c fractol.h
	cc $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	cc -lmlx -framework $(GFLAGS) $(OBJ) -o $(NAME)

$(NAME_B) : $(OBJ_B)
	cc -lmlx -framework $(GFLAGS) $(OBJ_B) -o $(NAME_B)

bonus : $(NAME_B)

clean :
	rm -rf $(OBJ) $(OBJ_B)
	
fclean : clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all
