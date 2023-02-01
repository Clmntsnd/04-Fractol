# -- Executable's name -- #
NAME = fractol

# -- Compiler -- #
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra

# -- OS CHECK -- #
OS = $(shell uname)
OS_AIR = $(shell uname -p)

# -- Flags depending on the OS -- #
# -- LINUX and WSL -- #
LINUX = -ldl -lglfw -pthread -lm
# -- MAC -- #
MAC = -I /include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread
MAC_AIR = -I /include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib" -pthread

# -- REMOVE -- #
RM = rm -f

# -- MLX42 LIB -- #
MLX = ./lib/MLX42/build/libmlx42.a

# -- RUN -- #
RUN = ./fractol 1

# -- OBJS -- #
OBJS = ${SRC:.c=.o}

# -- Sources -- #
SRC = ./src/julia_multi.c ./src/julia.c ./src/colors.c ./src/main.c ./src/buddhabrot.c ./src/mandelbrot.c ./src/my_keyhook.c ./src/print_usage.c

# -- Colors -- #
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# -- Check OS to get the correcrt FLAGS -- #
ifeq ($(OS_AIR), arm)
	FLAGS = $(MAC_AIR)
else ifeq ($(OS), Linux)
	FLAGS = $(LINUX)
else ifeq ($(OS), Darwin)
	FLAGS = $(MAC)
endif

all: lib $(NAME)

$(NAME): ${OBJS} ./lib/fractol.h
	${CC} $(CFLAGS) $(OBJS) $(MLX) $(FLAGS) -o ${NAME}
	@echo "🎉$(GREEN)Everything compiled!$(WHITE)🎉"

lib:
	@cmake lib/MLX42 -B lib/MLX42/build
	@make -C lib/MLX42/build
#@cmake -B build lib/MLX42

clean:
	@echo "$(RED)💥Cleaning .o💥$(WHITE)"
	@sleep 1 > /dev/null
	$(RM) $(OBJS)
	@echo "🎉$(GREEN)Cleaning done!$(WHITE)🎉"

fclean: clean
	@echo "$(RED)💥Removing files...💥"
	$(RM) $(NAME)
	@echo "🎉$(GREEN)Cleaning done!$(WHITE)🎉"

re: fclean all
	@echo "$(PURPLE)Relink Successful! $(WHITE)"
run:  
	$(RUN)
.PHONY: all clean fclean re run lib