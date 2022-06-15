# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hherba <hherba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 23:13:06 by hherba            #+#    #+#              #
#    Updated: 2022/06/14 19:25:38 by hherba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror 

NAME=fractol

SRCS=	main.c init.c utils.c utils2.c \
		mandelbrot.c julia.c

INC = fractol.h
BSRCS=	bonus/main_bonus.c bonus/init_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c \
		bonus/mandelbrot_bonus.c bonus/burning_ship_bonus.c bonus/julia_bonus.c
		
BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(INC)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(OBJCTS) -o $(NAME)

all: $(NAME)

bonus : $(BOBJCTS) $(INC)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(BOBJCTS) -o fractol_bonus

clean:
		rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
		rm -f $(NAME) fractol_bonus
		
re: fclean all	
