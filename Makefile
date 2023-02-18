SRCS = main.c \
	checkers.c \
	checkers2.c \
	ft_atoi_long_int.c \
	listes_chainees.c \
	listes_chainees2.c \
	mouvements.c \
	ft_algo.c \
	ft_index.c \
	dix_ou_plus.c \
	ft_encore_un_fichier.c \

SRCSB = bonus/bonus.c \
	checkers.c \
	checkers2.c \
	ft_atoi_long_int.c \
	listes_chainees.c \
	listes_chainees2.c \
	bonus/mouvements_bn.c \
	bonus/mouvements_bn2.c \
	bonus/main_bonus.c \

LIBFT = Libft_clone/libft.a
FT_PRINTF = Libft_clone/ft_printf/libftprintf.a

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
	$(CC) $(OBJSB) $(LIBFT) $(FT_PRINTF) -o $(NAMEB) -g

$(NAME) : $(OBJS)
	make -C Libft_clone
	$(CC) $(OBJS) $(LIBFT)  $(FT_PRINTF) -o $(NAME) -g 

clean : 
	make clean -C Libft_clone
	$(RM) *.o bonus/*.o

fclean :
	make fclean -C Libft_clone
	$(RM) *.o bonus/*.o $(NAME) $(NAMEB)

re : fclean all

git : fclean
	git add *
	git commit
	git push

.PHONY : re all clean fclean bonus git