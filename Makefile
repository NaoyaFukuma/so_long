# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 17:35:48 by nfukuma           #+#    #+#              #
#    Updated: 2022/09/15 22:13:17 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#for set up
NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf


#for sorc file and path mondatory or bonus
SRCNAMES_B	=
SRCDIR_B		=	src_b/
SRCS_B		=	$(addprefix $(SRCDIR), $(SRCNAMES_B))
OBJS		=	$(SRCS_B:%.c=%.o)

SRCNAMES	=	animation.c get_xpm_file.c main.c put_map.c util.c validate_file_name.c valitade_map.c keypress.c
SRCDIR		=	src/
SRCS		=	$(addprefix $(SRCDIR), $(SRCNAMES))
OBJS		=	$(SRCS:%.c=%.o)

#.a library path
LIBDIR		=	./libft
GNLDIR		=	./libgnl
MINILIBXDIR		=	./minilibx-linux/

#target rule
all	:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C $(LIBDIR)
	make -C $(GNLDIR)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -L $(LIBDIR) -L $(GNLDIR) -L $(MINILIBXDIR) -lft -lgnl -lmlx -lmlx_Darwin /usr/X11R6/lib/libX11.dylib /usr/X11R6/lib/libXext.dylib -o $@ $^

bonus	:
	make WITH_BONUS=1

clean	:
	$(RM) $(OBJS)
	make -C $(LIBDIR) clean;
	make -C $(GNLDIR) clean;

fclean	:	clean
	make -C $(LIBDIR) fclean;
	make -C $(GNLDIR) fclean;
	$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re bonus

# all	:
# 	gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit main.c ./minilibx-linux/libmlx.a minilibx-linux/libmlx_Darwin.a /usr/X11R6/lib/libX11.dylib /usr/X11R6/lib/libXext.dylib
