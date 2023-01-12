# Executable #
NAME = fractol
# Compile stuff #
CC = gcc
CFGLAGS = -Wall -Werror -Wextra
# LINUX and WSL WINDOWS FLAG #
LINUX = -ldl -lglfw -pthread -lm
# MAC FLAG #
MAC = -I /include -lglfw -pthread -L "/Users/$(USER)/.brew/opt/glfw/lib/"
# REMOVE #
REMOVE = rm -f
# LIBS #
CLONE = git clone https://github.com/codam-coding-college/MLX42.git;
MLX = ./lib/MLX42/libmlx42.a
# RUN #
RUN = ./fractol 1
# OBJS #
OBJS = ${SRC:.c=.o}
# OS CHECK #
OS = $(shell uname)
# Source #
SRC = 	./src/mandelbrot.c ./src/data.c ./src/get_rgba.c ./src/my_keyhook.c \
	 	./src/main.c \

		
# Colors #
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

#CHECK WHICH OS IS RUNNING TO GET THE CORRECT COMPILATION FLAG #
ifeq ($(OS), Linux)
	FLAGS = $(LINUX)
else ifeq ($(OS), Darwin)
	FLAGS = $(MAC)

endif

$(NAME): lib ${OBJS}
	${CC} $(CFGLAGS) $(OBJS) $(MLX) $(FLAGS) -o ${NAME}
	@echo "🎉$(GREEN)Everything compiled!$(WHITE)🎉"

lib:
	@if [ ! -d "./lib/MLX42" ]; then \
		cd lib && $(CLONE) \
	fi
	@cd lib && make -C MLX42

all: $(NAME)

clean:
	@echo "$(RED)💥Cleaning .o💥$(WHITE)"
	@sleep 1 > /dev/null
	$(REMOVE) $(OBJS)
	@if [ -d "./lib/MLX42" ]; then \
		make clean -C lib/MLX42; \
	fi
	@echo "🎉$(GREEN)Cleaning done!$(WHITE)🎉"

fclean: clean
	@echo "$(RED)💥Removing files...💥"
	@sleep 1 > /dev/null
	$(REMOVE) $(NAME)
	@echo "$(RED)💥Removing MLX Directory...💥"
	@sleep 1 > /dev/null
	@if [ -d "./lib/MLX42" ]; then \
		rm -rf lib/MLX42; \
	fi
	@echo "🎉$(GREEN)Cleaning done!$(WHITE)🎉"

re: fclean all
	@echo "$(PURPLE)Relink Successful! $(WHITE)"
run:  
	$(RUN)
.PHONY: all clean fclean re run lib