SRCS = main.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = a.out

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean : 
	$(RM) *.o

fclean :
	$(RM) *.o $(NAME)

re : fclean all

.PHONY : re all clean fclean