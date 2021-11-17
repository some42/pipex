NAME = pipex

SRCS =	main.c \
		utils.c \

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCL= ./libft/libft.a \

CC = gcc

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -Iincludes $(INCL) -o $(NAME)

all: $(NAME)

libs:
	@make bonus -C ./libft/

clean:
	@rm -rf $(OBJS)
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

lclean:
	@make clean -C ./libft/

lfclean:
	@make fclean -C ./libft/

re: fclean all