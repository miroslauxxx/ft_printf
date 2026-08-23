SRC_FILES = ft_printf.c \
			ft_printf_put.c \
			ft_printf_utils.c 

NAME = libftprintf.a

LIBFT_DIR = ../libft

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): 
	gcc -c $(FLAGS) $(SRC_FILES)
	ar rcs $(NAME) $(LIBFT) $(OBJ_FILES)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_FILES)
	@make -C $(LIBFT_DIR) clean && echo "@make -C $(LIBFT_DIR) clean"

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean && echo "@make -C $(LIBFT_DIR) fclean"

re: fclean all
