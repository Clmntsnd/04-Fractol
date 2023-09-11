# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loulou <loulou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:52:46 by csenand           #+#    #+#              #
#    Updated: 2023/09/10 17:46:15 by loulou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Executable's name -- #
NAME		=	fractol

# -- Compiler -- #
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -g

# -- OS CHECK -- #
OS 			= $(shell uname)
OS_AIR 		= $(shell uname -p)

# -- Flags depending on the OS -- #
# -- LINUX and WSL -- # 
LINUX 		= -ldl -lglfw -pthread -lm

# -- MAC -- #
MAC 		= -I /include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread
MAC_AIR 	= -I /include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib" -pthread


# -- REMOVE -- #
RM = rm -rf

# -- SRC Files -- #
SRCS_DIR	=	./src/
SRCS_LST	= 	main.c \
				julia.c \
				burningship.c \
				colors.c \
				utils.c \
				mandelbrot.c \
				my_keyhook.c \
				tools.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

# -- OBJ Files -- #
OBJS_DIR	=	./obj/
OBJS_LST	=	$(patsubst %.c, %.o, $(SRCS_LST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LST))

# -- HEADER Files -- #
HEADER_DIR	=	./include/
HEADER_LST	=	fractol.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LST))

# -- MLX42 Files -- #
MLX42_DIR	=	./lib/MLX42
MLX42		=	$(MLX42_DIR)/build/libmlx42.a

# -- Colors -- #
RESET		= 	\033[0m
RED			= 	\033[0;31m
GREEN		= 	\033[0;32m
YELLOW		= 	\033[0;33m
BLUE		= 	\033[0;34m
PURPLE		= 	\033[0;35m
CYAN		= 	\033[0;36m
ERASE_LINE 	= 	\033[2K\r

# -- Check OS to get the correcrt FLAGS -- #
ifeq ($(OS_AIR), arm)
	FLAGS = $(MAC_AIR)
else ifeq ($(OS), Linux)
	FLAGS = $(LINUX)
else ifeq ($(OS), Darwin)
	FLAGS = $(MAC)
endif

# -- Executable's creation -- #
all : dir $(NAME) ./include/fractol.h

# -- Compile library -- #
$(NAME) : $(MLX42) $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) $(MLX42) $(FLAGS) -o $(NAME)
	@echo "✅ $(GREEN)$(NAME)'s exectuable successfully created.		✅$(RESET)"

# -- Create all files .o (object) from files .c (source code) -- #
$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADER)
	@printf "$(ERASE_LINE)🎛️  $(PURPLE)Compiling $(YELLOW)$(notdir $<)\r$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX42):
	@if [ ! -f "./libs/MLX42/build/libmlx42.a" ]; then \
		cmake lib/MLX42 -B $(MLX42_DIR)/build &> /dev/null && make -C $(MLX42_DIR)/build -j4; \
	fi
	@echo "\n✅ $(GREEN)MLX42 successfully compiled.\t\t\t✅$(RESET)"

# -- Create directory for *.o files -- #
dir :
	@mkdir -p $(OBJS_DIR)

# -- Removes objects -- #
clean :
	@printf "💥 $(RED)Removing $(NAME)'s objects...$(RESET)\t\t\t💥\n"
	@$(RM) $(OBJS_DIR)
	@printf "🗑️  $(CYAN)$(NAME)'s object successfully deleted.$(RESET)\t\t🗑️\n"

# -- Removes objects (with clean) and executable -- #
fclean : clean
	@printf "💥 $(RED)Removing executable(s)...$(RESET)				💥\n"
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@$(RM) $(MLX42_DIR)/build
	@printf "🗑️  $(CYAN)Executable(s) and archive(s) successfully deleted.$(RESET)	🗑️\n"

# -- Removes objects and executable then remakes all -- #
re: fclean all

# -- Avoid file-target name conflicts -- #
.PHONY : all bonus clean fclean re