NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread

SRC =	src/check_in.c \
		src/philo.c \
		src/philo_alloc.c

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