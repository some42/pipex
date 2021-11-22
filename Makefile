NAME = pipex

SRCS =	main.c \
		utils.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

LIBFT= ./libft/libft.a

CC = gcc

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) -Iincludes $(INCL) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make bonus -C ./libft/

clean:
	@make clean -C ./libft/
	@rm -rf $(OBJS)
	@echo "cleaning .o files"

fclean: clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

re: fclean all
