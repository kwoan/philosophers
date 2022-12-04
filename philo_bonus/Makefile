# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 13:57:34 by kwpark            #+#    #+#              #
#    Updated: 2022/12/04 18:56:51 by kwpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread

SRC =	src/check_args.c \
		src/init.c \
		src/philo_utils.c \
		src/philo_status.c \
		src/philo_process.c \
		src/philo_bonus.c

OBJS = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re