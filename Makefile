#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/06/07 18:02:32 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB = ft_printf/libftprintf.a
MINILIBX = minilibx_macos/libmlx.a
SRC = ft_error.c\
	  main.c\
	  event_maker.c\
	  mandelbrot.c\
	  julia.c\
	  burning_ship.c\
	  color_initialiser.c\
	  peripherals_manager.c
OBJ = 
SRCO = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -L /usr/lib -lmlx -framework OpenGl -framework AppKit\

all: $(NAME)

%.o: %.c
	$(CC) -o $(addprefix $(OBJ),$@) -c $< $(FLAG)

$(NAME): $(SRCO)
	make -C ft_printf
	make -C minilibx_macos
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LIB) $(MINILIBX) -I includes

clean:
	make -C ft_printf clean
	make -C minilibx_macos clean
	rm -f $(addprefix $(OBJ),$(SRCO))

fclean: clean
	make -C ft_printf fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
