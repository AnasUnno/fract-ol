# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 14:11:55 by araji-af          #+#    #+#              #
#    Updated: 2023/03/23 15:15:31 by araji-af         ###   ########.fr        #
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

all :  $(NAME)

$(NAME) : $(SRCS) $(OBJ) fractol.h
	cc $(FLAGS) $(SRCS) -lmlx -framework $(GFLAGS) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(SRCS_B) $(OBJ_B) bonus/header.h
	cc $(FLAGS) $(SRCS_B) -lmlx -framework $(GFLAGS) -o $(NAME_B)

%.o: %.c
	cc -c $< -o $@
clean :
	rm -rf $(OBJ) $(OBJ_B)

fclean : clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all