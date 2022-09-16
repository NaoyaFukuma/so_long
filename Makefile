# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 17:35:48 by nfukuma           #+#    #+#              #
#    Updated: 2022/09/16 20:24:08 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#for set up
NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf


#for sorc file and path mondatory or bonus
SRCNAMES_B	=	animation_bonus.c frame_188888_bonus.c \
				get_xpm_file_bonus.c keypress_bonus.c main_bonus.c \
				put_map_bonus.c util_bonus.c validate_file_name_bonus.c \
				valitade_map_bonus.c
SRCDIR_B		=	src_b/
SRCS_B		=	$(addprefix $(SRCDIR_B), $(SRCNAMES_B))
OBJS_B		=	$(SRCS_B:%.c=%.o)

SRCNAMES	=	animation.c get_xpm_file.c main.c put_map.c util.c \
				validate_file_name.c valitade_map.c keypress.c \
				frame_188888.c
SRCDIR		=	src/
SRCS		=	$(addprefix $(SRCDIR), $(SRCNAMES))
OBJS		=	$(SRCS:%.c=%.o)

#.a library path
LIBDIR		=	./libft
GNLDIR		=	./libgnl
MINILIBXDIR		=	./minilibx-linux/

#target rule
all	:	$(NAME)

ifeq			($(WITH_BONUS), 1)
$(NAME)	:	$(OBJS_B)
	make -C $(LIBDIR)
	make -C $(MINILIBXDIR)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -L $(LIBDIR) -L $(GNLDIR) -L $(MINILIBXDIR) -lft -lgnl -lmlx -lmlx_Darwin /usr/X11R6/lib/libX11.dylib /usr/X11R6/lib/libXext.dylib -o $@ $^
else
$(NAME)	:	$(OBJS)
	make -C $(LIBDIR)
	make -C $(GNLDIR)
	make -C $(MINILIBXDIR)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -L $(LIBDIR) -L $(GNLDIR) -L $(MINILIBXDIR) -lft -lgnl -lmlx -lmlx_Darwin /usr/X11R6/lib/libX11.dylib /usr/X11R6/lib/libXext.dylib -o $@ $^
endif

bonus	:
	make WITH_BONUS=1

clean	:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	make -C $(MINILIBXDIR) clean;
	make -C $(LIBDIR) clean;
	make -C $(GNLDIR) clean;

fclean	:	clean
	make -C $(LIBDIR) fclean;
	make -C $(GNLDIR) fclean;
	$(RM) $(NAME)

re:	fclean all

norm:
	norminette src/
	norminette src_b/
	norminette libft/
	norminette libgnl/

.PHONY:		all clean fclean re bonus

