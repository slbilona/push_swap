SRCS = main.c \
	checkers.c \
	ft_atoi_long_int.c \
	listes_chainees.c \
	mouvements.c \
	ft_algo.c \
	ft_algo_b.c \
	ft_index.c \
	dix_ou_plus.c \
	ft_encore_un_fichier.c \

SRCSB = bonus.c \
	checkers.c \
	ft_atoi_long_int.c \
	listes_chainees.c \
	mouvements_bn.c \

LIBFT = Libft_clone/libft.a

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = push_swap

NAMEB = checker

all : $(NAME)

bonus : $(OBJSB)
	make -C Libft_clone
	$(CC) $(OBJSB) $(LIBFT) -o $(NAMEB) -g

$(NAME) : $(OBJS)
	make -C Libft_clone
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) -g 

clean : 
	make clean -C Libft_clone
	$(RM) *.o

fclean :
	make fclean -C Libft_clone
	$(RM) *.o $(NAME) $(NAMEB)

re : fclean all

git : fclean
	git add *
	git commit
	git push

.PHONY : re all clean fclean bonus git