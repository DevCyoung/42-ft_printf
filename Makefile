# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoseo <yoseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 04:09:25 by yoseo             #+#    #+#              #
#    Updated: 2022/02/12 09:15:33 by yoseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HD = ft_printdf.h

SRC =   ft_printf.c\
		ft_num_utils.c\
		ft_str_utils.c\
			
OBJS = $(SRC:.c=.o) 

all: $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
