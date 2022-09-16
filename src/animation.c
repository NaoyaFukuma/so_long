/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:18:38 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 20:32:57 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	frame_66666(t_info *info);
static void	frame_133333(t_info *info);
static void	enemy_animation2(t_info *info, int i);
static void	enemy_animation3(t_info *info, int i);

int	animation(t_info *info)
{
	if (info->status == CLEARED)
		return (0);
	if (info->frame % 66666 == 0)
		frame_66666(info);
	else if (info->frame % 133333 == 0)
		frame_133333(info);
	if (info->frame % 188888 == 0)
		frame_188888(info);
	info->frame++;
	return (0);
}

static void	frame_66666(t_info *info)
{
	{
		if (info->player_posi[2] == UP)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_u2,
					info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == DOWN)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_d2,
					info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == RIGHT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_r2,
					info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == LEFT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_l2,
					info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		enemy_animation2(info, -1);
	}
}

static void	frame_133333(t_info *info)
{
	{
		if (info->player_posi[2] == UP)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_u3,
				info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == DOWN)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_d3,
				info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == RIGHT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_r3,
				info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == LEFT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_l3,
				info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		enemy_animation3(info, -1);
	}
}

static void	enemy_animation2(t_info *info, int i)
{
	while (++i < info->enemy_count)
	{
		if (info->enemy_posi[i * 3 + 2] == DOWN)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_d2, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == UP)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_u2, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == LEFT)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_l2, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == RIGHT)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_r2, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
	}
}

static void	enemy_animation3(t_info *info, int i)
{
	while (++i < info->enemy_count)
	{
		if (info->enemy_posi[i * 3 + 2] == DOWN)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_d3, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == UP)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_u3, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == LEFT)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_l3, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		if (info->enemy_posi[i * 3 + 2] == RIGHT)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_r3, info->enemy_posi[i * 3]
				* 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
	}
}
