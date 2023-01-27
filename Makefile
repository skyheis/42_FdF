# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2023/01/24 15:43:56 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = fdf
PRNAME = fdf

BNUS = bonus

INCLUDE = include
MLX_PATH = ../minilibx-linux

###### VARIABLE ######

DIRSRCS =
DIROBJS = obj/

FLSRCS = main.c my_minilibx_utils.c maps.c map_utils.c set_dot.c

FLOBJS = ${FLSRCS:.c=.o}

OBJS = $(addprefix $(DIROBJS),$(FLOBJS))

ARUSD = libft.a libmlx.a
ARUSDDIR = archive/

ARINC = $(addprefix $(ARUSDDIR),$(ARUSD))

CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lm -lX11 -lXext -lmlx

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(GREEN)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: libft ${NAME}

${NAME}: ${OBJS}
	@echo "$(YELLOW)- Program Name: $(WHITE)${PRNAME}$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -L $(ARUSDDIR) -I $(INCLUDE) -o $(PRNAME) $(OBJS) $(ARINC) $(MLXFLAGS) 

clean:
	@make -sC libft clean
	@${RM} ${OBJS} 
	@echo "$(RED)All $(CYAN)$(PRNAME)$(RED)'s objects removed with $(WHITE)${RM}$(DEF_COLOR) 🧹" 

fclean: clean
	@make -sC libft fclean
	@${RM} ${PRNAME} 
	@echo "$(RED)..and $(CYAN)${PRNAME} $(RED)as been removed$(DEF_COLOR) 🚮"

libft:
	@make -sC libft

libftclean:
	@make -sC libft clean

libftfclean:
	@make -sC libft fclean

re: fclean all

minilibx:
	@make -c $(MLX_PATH)
	@cp $(MLX_PATH)/mlx.h $(INLUDE)/mlx.h
	@cp $(MLX_PATH)/libmlx_Linux.a $(INLUDE)/libmlx.a


#starting:
#	@echo "$(WHITE)🧙as a wizard, I made appear your $(CYAN) $(PRNAME) $(WHITE)binary!🪄 💫$(DEF_COLOR)"
#	@sleep 0.1

.PHONY: all clean fclean re starting .c.o libft libftclean libftfclean minilibx
.SUFFIXES: .c .o 
