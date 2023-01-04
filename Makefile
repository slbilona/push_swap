SRCS = main.c \

LIBFT = Libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make -C Libft
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) -g

clean : 
	make clean -C Libft
	$(RM) *.o

fclean :
	make fclean -C Libft
	$(RM) *.o $(NAME)

re : fclean all

.PHONY : re all clean fclean