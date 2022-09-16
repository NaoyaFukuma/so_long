/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:11:32 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 20:13:47 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(t_info *info, size_t x, size_t y);
static void	put_enemy(t_info *info);
static void	put_player(t_info *info);

int	put_map(t_info *info)
{
	size_t	x;
	size_t	y;
	char	*mv_count_msg;
	char	*mv_num;

	y = -1;
	while (++y < info->hei)
	{
		x = -1;
		while (++x < info->wdt)
			put_image(info, x, y);
	}
	put_player(info);
	put_enemy(info);
	mv_num = ft_itoa(info->mvnum);
	mv_count_msg = ft_strjoin("Move: ", mv_num);
	mlx_string_put(info->mlx, info->win, 3, 12, 0xffffff, mv_count_msg);
	free(mv_num);
	free(mv_count_msg);
	return (0);
}

static void	put_image(t_info *info, size_t x, size_t y)
{
	if (info->map[y][x] == BLANK)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.blank, x * 32, y * 32 + 17);
	if (info->map[y][x] == WALL)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.wall, x * 32, y * 32 + 17);
	if (info->map[y][x] == ITEM)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.item, x * 32, y * 32 + 17);
	if (info->map[y][x] == EXIT)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.exit, x * 32, y * 32 + 17);
}

static void	put_player(t_info *info)
{
	if (info->player_posi[2] == DOWN)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.p_d1, info->player_posi[0] * 32,
				info->player_posi[1] * 32 + 17);
	if (info->player_posi[2] == UP)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.p_u1, info->player_posi[0] * 32,
				info->player_posi[1] * 32 + 17);
	if (info->player_posi[2] == LEFT)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.p_l1, info->player_posi[0] * 32,
				info->player_posi[1] * 32 + 17);
	if (info->player_posi[2] == RIGHT)
		mlx_put_image_to_window(
			info->mlx, info->win, info->img.p_r1, info->player_posi[0] * 32,
				info->player_posi[1] * 32 + 17);
}

static void	put_enemy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->enemy_count)
	{
		if (info->enemy_posi[i * 3 + 2] == DOWN)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_d1, info->enemy_posi[i * 3]
					* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == UP)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_u1, info->enemy_posi[i * 3]
					* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == LEFT)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_l1, info->enemy_posi[i * 3]
					* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == RIGHT)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_r1, info->enemy_posi[i * 3]
					* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
	}
}
