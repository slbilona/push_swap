SRCS = main.c \
	checkers.c \
	ft_atoi_long_int.c \
	listes_chainees.c \
	mouvements.c \
	ft_algo.c \

LIBFT = Libft_clone/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make -C Libft_clone
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) -g

clean : 
	make clean -C Libft_clone
	$(RM) *.o

fclean :
	make fclean -C Libft_clone
	$(RM) *.o $(NAME)

re : fclean all

git : fclean
	git add *
	git commit
	git push

.PHONY : re all clean fclean