/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:09:54 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 14:23:39 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* header */
# include "../libft/libft.h"             // ...(ft)
# include "../libgnl/libget_next_line.h" //for get_next_line(ft)
# include "../minilibx-linux/mlx.h"
# include <fcntl.h> // for open(2)
# include <stdbool.h>
# include <stdio.h>  // for perror(3)
# include <stdlib.h> // for exit(3) malloc,free(3)
# include <sys/errno.h>
# include <unistd.h> // for write(2) close(2)

/* map chip */
# define BLANK '0'
# define WALL '1'
# define ITEM 'C'
# define OPEN_ITEM 'O'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'T'

/* game status */
# define MOVED 99
# define CLEARED 100

/* body orientation */
# define UP 50
# define RIGHT 51
# define LEFT 52
# define DOWN 53

/* event */
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROYNOTIFY 17

/* key */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

/* chip file path */
typedef struct s_img
{
	void	*blank;
	void	*wall;
	void	*item;
	void	*exit;
	void	*p_d1;
	void	*p_d2;
	void	*p_d3;
	void	*p_u1;
	void	*p_u2;
	void	*p_u3;
	void	*p_r1;
	void	*p_r2;
	void	*p_r3;
	void	*p_l1;
	void	*p_l2;
	void	*p_l3;
	void	*t_d1;
	void	*t_d2;
	void	*t_d3;
	void	*t_u1;
	void	*t_u2;
	void	*t_u3;
	void	*t_r1;
	void	*t_r2;
	void	*t_r3;
	void	*t_l1;
	void	*t_l2;
	void	*t_l3;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	status;
	char	**map;
	size_t	frame;
	int		player_posi[3];
	int		*enemy_posi;
	int		enemy_count;
	size_t	wdt;
	size_t	hei;
	t_img	img;
	int		mvnum;
	int		item_count;
}			t_info;

/* in main.c */
int			destroy_window(t_info *info);

/* in validate.c */
void		validate_file_name(int ac, char *file_name);

/* in validate_map.c */
void		validate_map(t_info *info);

/* in get_xpm_file */
void		get_xpm_file(t_info *info);

/* in put_map.c */
int			put_map(t_info *info);

/* in keypress.c */
int			keypress(int keycode, t_info *info);

/* animation.c */
int			animation(t_info *info);

/* frame_188888.c */
void		frame_188888(t_info *info);

/* in util.c */
void		util_perror_exit(char *error_message, int perror_flag);
void		util_lose_put_msg(t_info *info);
void		util_clear_put_msg(t_info *info);
bool		util_clear_check(t_info *info, int move_x, int move_y);
bool		util_lose_check(t_info *info, int move_x, int move_y);

void		put_player(t_info *info);
void		put_enemy(t_info *info);

#endif
