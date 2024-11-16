# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 15:19:56 by hakobori          #+#    #+#              #
#    Updated: 2024/05/29 13:57:49 by hakobori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		 = so_long
BONUS		 = bonus
CFLAGS 		 = -Wall -Wextra -Werror
SRCS_DIR	 = ./srcs
SRCS 		 = $(SRCS_DIR)/main.c \
			   $(SRCS_DIR)/open_read_map.c \
			   $(SRCS_DIR)/map_flood_fill.c \
			   $(SRCS_DIR)/map_wall_check.c \
			   $(SRCS_DIR)/map_cep_check.c \
			   $(SRCS_DIR)/show_error.c \
			   $(SRCS_DIR)/goal_gameover_close.c \
			   $(SRCS_DIR)/get_next_line.c \
			   $(SRCS_DIR)/get_next_line_utils.c \
			   $(SRCS_DIR)/minilibx_set.c \
			   $(SRCS_DIR)/player_move.c \
			   $(SRCS_DIR)/enemy_move.c \
			   $(SRCS_DIR)/event.c
OBJS 		 = $(SRCS:.c=.o)
SRCS_BONUS_DIR	 = ./srcs_bonus
SRCS_BONUS 	= $(SRCS_BONUS_DIR)/main_bonus.c \
			   $(SRCS_BONUS_DIR)/open_read_map_bonus.c \
			   $(SRCS_BONUS_DIR)/map_flood_fill_bonus.c \
			   $(SRCS_BONUS_DIR)/map_wall_check_bonus.c \
			   $(SRCS_BONUS_DIR)/map_cep_check_bonus.c \
			   $(SRCS_BONUS_DIR)/show_error_bonus.c \
			   $(SRCS_BONUS_DIR)/goal_gameover_close_bonus.c \
			   $(SRCS_BONUS_DIR)/get_next_line_bonus.c \
			   $(SRCS_BONUS_DIR)/get_next_line_utils_bonus.c \
			   $(SRCS_BONUS_DIR)/minilibx_set_bonus.c \
			   $(SRCS_BONUS_DIR)/player_move_bonus.c \
			   $(SRCS_BONUS_DIR)/enemy_move_bonus.c \
			   $(SRCS_BONUS_DIR)/event_bonus.c
OBJS_2 		 = $(SRCS_BONUS:.c=.o)
INCLUDE_DIR  = ./includes
INCLUDE		 = $(INCLUDE_DIR)/so_long.h 
INCLUDE_2	 = $(INCLUDE_DIR)/so_long_bonus.h
LIBFT_DIR 	 = ./libft
LIBFT 		 = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = ./minilibx_opengl
MINILIBX	 = $(MINILIBX_DIR)/libmlx.a
LIBS 		 = -L$(MINILIBX_DIR) -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX) $(LIBFT) $(INCLUDE)
	$(CC) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME)

bonus:$(OBJS_2) $(MINILIBX) $(LIBFT) $(INCLUDE_2)
	$(CC) $(OBJS_2) $(LIBFT) $(LIBS) -o $(BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	rm -f $(OBJS) $(OBJS_2)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean fclean re
