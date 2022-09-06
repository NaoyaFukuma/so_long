# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 17:35:48 by nfukuma           #+#    #+#              #
#    Updated: 2022/09/01 22:28:03 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all	:
	gcc -Wall -Werror -Wextra -framework OpenGL -framework AppKit main.c ./minilibx-linux/libmlx.a minilibx-linux/libmlx_Darwin.a /usr/X11R6/lib/libX11.dylib /usr/X11R6/lib/libXext.dylib
