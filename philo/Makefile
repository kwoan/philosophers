NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread

SRC =	src/check_args.c \
		src/init.c \
		src/philo_utils.c \
		src/philo_status.c \
		src/philo_thread.c \
		src/philo.c \
		src/free_all.c

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