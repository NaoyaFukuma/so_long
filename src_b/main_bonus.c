/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:11:35 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 19:16:46 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_player_and_enemy_posi(t_info *info, size_t x, size_t y, int i);
static void	get_map(char *map, t_info *info);

int	destroy_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	validate_file_name(ac, av[1]);
	get_map(av[1], &info);
	validate_map(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.wdt * 32, info.hei * 32 + 20,
			"so_long");
	get_xpm_file(&info);
	get_player_and_enemy_posi(&info, -1, -1, 0);
	put_map(&info);
	mlx_loop_hook(info.mlx, animation, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, (1L << 0), keypress, &info);
	mlx_hook(info.win, X_EVENT_DESTROYNOTIFY, (1L << 0), destroy_window, &info);
	mlx_expose_hook(info.win, put_map, &info);
	mlx_loop(info.mlx);
	exit(EXIT_SUCCESS);
}

static void	get_map(char *map, t_info *info)
{
	int	map_fd;

	map_fd = open(map, O_RDONLY);
	if (map_fd < 0)
		util_perror_exit("open", 1);
	while (1)
	{
		info->map = ft_remalloc(info->map, sizeof(char *) * (info->hei + 1),
				sizeof(char *) * info->hei);
		if (!info->map)
			util_perror_exit("malloc", 1);
		info->map[info->hei] = get_next_line(map_fd);
		if (!info->map[info->hei])
			break ;
		info->hei++;
	}
	close(map_fd);
}

static void	get_player_and_enemy_posi(t_info *info, size_t x, size_t y, int i)
{
	info->enemy_posi = malloc(sizeof(int) * info->enemy_count * 3);
	if (!info->enemy_posi)
		util_perror_exit("ft_remalloc", 1);
	while (++y < info->hei)
	{
		x = -1;
		while (++x < info->wdt)
		{
			if (info->map[y][x] == PLAYER)
			{
				info->player_posi[0] = (int)x;
				info->player_posi[1] = (int)y;
				info->player_posi[2] = DOWN;
				info->map[y][x] = BLANK;
			}
			if (info->map[y][x] == ENEMY)
			{
				info->map[y][x] = BLANK;
				info->enemy_posi[3 * i] = (int)x;
				info->enemy_posi[3 * i + 1] = (int)y;
				info->enemy_posi[3 * i + 2] = DOWN;
				i++;
			}
		}
	}
}
