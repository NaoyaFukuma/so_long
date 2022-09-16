/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:18:38 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 12:14:19 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_info *info)
{
	int	i;

	i = -1;

	if (info->status == CLEARED)
		return (0);
	if (info->frame % 66666 == 0)
	{
		if (info->player_posi[2] == UP)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_u2, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == DOWN)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_d2, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == RIGHT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_r2, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == LEFT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_l2, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		while (++i < info->enemy_count)
		{
			if (info->enemy_posi[i * 3 + 2] == DOWN)
			mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_d2, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
			if (info->enemy_posi[i * 3 + 2] == UP)
				mlx_put_image_to_window(
					info->mlx, info->win, info->img.t_u2, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
			if (info->enemy_posi[i * 3 + 2] == LEFT)
				mlx_put_image_to_window(
					info->mlx, info->win, info->img.t_l2, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
			if (info->enemy_posi[i * 3 + 2] == RIGHT)
				mlx_put_image_to_window(
					info->mlx, info->win, info->img.t_r2, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		}
	}
	else if (info->frame % 133333 == 0)
	{
		if (info->player_posi[2] == UP)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_u3, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == DOWN)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_d3, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == RIGHT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_r3, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		if (info->player_posi[2] == LEFT)
			mlx_put_image_to_window(info->mlx, info->win, info->img.p_l3, info->player_posi[0] * 32, info->player_posi[1] * 32 + 17);
		while (++i < info->enemy_count)
		{
			if (info->enemy_posi[i * 3 + 2] == DOWN)
				mlx_put_image_to_window(
				info->mlx, info->win, info->img.t_d3, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
			if (info->enemy_posi[i * 3 + 2] == UP)
				mlx_put_image_to_window(
					info->mlx, info->win, info->img.t_u3, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
			if (info->enemy_posi[i * 3 + 2] == LEFT)
				mlx_put_image_to_window(
					info->mlx, info->win, info->img.t_l3, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
			if (info->enemy_posi[i * 3 + 2] == RIGHT)
				mlx_put_image_to_window(
					info->mlx, info->win, info->img.t_r3, info->enemy_posi[i * 3] * 32, info->enemy_posi[i * 3 + 1] * 32 + 17);
		}
	}


	if (info->frame % 188888 == 0)
	{
		while (++i < info->enemy_count)
		{
			if (i % 2 == 0)
			{
				if (info->enemy_posi[i * 3 + 2] == UP)
				{
					if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i * 3]] != WALL)
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] - 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = LEFT;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] + 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = RIGHT;
					}
					else
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
						info->enemy_posi[i * 3 + 2] = RIGHT;
					}
				}
				else if (info->enemy_posi[i * 3 + 2] == LEFT)
				{
					if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] - 1] != WALL)
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
					else if (info->map[info->enemy_posi[i * 3 + 1] + 1][info->enemy_posi[i * 3]] != WALL)
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
						info->enemy_posi[i * 3 + 2] = DOWN;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i * 3]] != WALL)
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
						info->enemy_posi[i * 3 + 2] = UP;
					}
					else
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = RIGHT;
					}
				}
				else if (info->enemy_posi[i * 3 + 2] == RIGHT)
				{
					if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] + 1] != WALL)
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
					else if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i * 3]] != WALL)
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
						info->enemy_posi[i * 3 + 2] = UP;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1] + 1][info->enemy_posi[i * 3]] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = DOWN;
					}
					else
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = LEFT;
					}
				}
				else
				{
					if (info->map[info->enemy_posi[i * 3 + 1] + 1][info->enemy_posi[i * 3]] != WALL)
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] + 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = RIGHT;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] - 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = LEFT;
					}
					else
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = UP;
					}
				}
			}
			if (i % 2 == 1)
			{
				if (info->enemy_posi[i * 3 + 2] == UP)
				{
					if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i * 3]] != WALL)
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] + 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = RIGHT;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] - 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = LEFT;
					}
					else
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
						info->enemy_posi[i * 3 + 2] = DOWN;
					}
				}
				else if (info->enemy_posi[i * 3 + 2] == LEFT)
				{
					if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] - 1] != WALL)
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
					else if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i * 3]] != WALL)
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
						info->enemy_posi[i * 3 + 2] = UP;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1] + 1][info->enemy_posi[i * 3]] != WALL)
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
						info->enemy_posi[i * 3 + 2] = DOWN;
					}
					else
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = RIGHT;
					}
				}
				else if (info->enemy_posi[i * 3 + 2] == RIGHT)
				{
					if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] + 1] != WALL)
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] - 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = LEFT;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i * 3]] != WALL)
					{
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
						info->enemy_posi[i * 3 + 2] = UP;
					}
					else
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = DOWN;
					}
				}
				else
				{
					if (info->map[info->enemy_posi[i * 3 + 1] + 1][info->enemy_posi[i * 3]] != WALL)
						info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] - 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = LEFT;
					}
					else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3] + 1] != WALL)
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
						info->enemy_posi[i * 3 + 2] = RIGHT;
					}
					else
					{
						info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
						info->enemy_posi[i * 3 + 2] = UP;
					}
				}
			}
		}
		if (util_lose_check(info, 0, 0))
		{
			mlx_clear_window(info->mlx, info->win);
			util_lose_put_msg(info);
		}
		else
			put_map(info);
	}
	info->frame++;
	return (0);
}



