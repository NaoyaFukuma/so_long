/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_188888.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:35:20 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 20:39:41 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	same_direction(t_info *info, int dir, int i);
static void	different_direction1(t_info *info, int i);
static void	different_direction2(t_info *info, int i);
static void	different_direction3(t_info *info, int i);

void	frame_188888(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->enemy_count)
	{
		if (!same_direction(info, info->enemy_posi[i * 3 + 2], i))
		{
			if (i % 2 == 0 && (info->enemy_posi[i * 3 + 2] == UP
					|| info->enemy_posi[i * 3 + 2] == DOWN))
				different_direction1(info, i);
			else if (i % 2 == 1 && (info->enemy_posi[i * 3 + 2] == UP
					|| info->enemy_posi[i * 3 + 2] == DOWN))
				different_direction3(info, i);
			else
				different_direction2(info, i);
		}
		if (util_lose_check(info, 0, 0))
		{
			mlx_clear_window(info->mlx, info->win);
			util_lose_put_msg(info);
		}
		else
			put_map(info);
	}
}

static bool	same_direction(t_info *info, int dir, int i)
{
	if (dir == UP && info->map[info->enemy_posi[i * 3 + 1]
			- 1][info->enemy_posi[i * 3]] != WALL)
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
	else if (dir == LEFT && info->map[info->enemy_posi[i * 3
				+ 1]][info->enemy_posi[i * 3] - 1] != WALL)
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
	else if (dir == RIGHT && info->map[info->enemy_posi[i * 3
				+ 1]][info->enemy_posi[i * 3] + 1] != WALL)
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
	else if (dir == DOWN && info->map[info->enemy_posi[i * 3 + 1]
			+ 1][info->enemy_posi[i * 3]] != WALL)
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
	else
		return (false);
	return (true);
}

static void	different_direction1(t_info *info, int i)
{
	if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3]
		- 1] != WALL)
	{
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
		info->enemy_posi[i * 3 + 2] = LEFT;
	}
	else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3]
		+ 1] != WALL)
	{
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
		info->enemy_posi[i * 3 + 2] = RIGHT;
	}
	else if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i
			* 3]] != WALL)
	{
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
		info->enemy_posi[i * 3 + 2] = UP;
	}
	else
	{
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
		info->enemy_posi[i * 3 + 2] = DOWN;
	}
}

static void	different_direction3(t_info *info, int i)
{
	if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3]
		+ 1] != WALL)
	{
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
		info->enemy_posi[i * 3 + 2] = RIGHT;
	}
	else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3]
		- 1] != WALL)
	{
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
		info->enemy_posi[i * 3 + 2] = LEFT;
	}
	else if (info->map[info->enemy_posi[i * 3 + 1] + 1][info->enemy_posi[i
			* 3]] != WALL)
	{
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
		info->enemy_posi[i * 3 + 2] = DOWN;
	}
	else
	{
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
		info->enemy_posi[i * 3 + 2] = UP;
	}
}

static void	different_direction2(t_info *info, int i)
{
	if (info->map[info->enemy_posi[i * 3 + 1] - 1][info->enemy_posi[i
			* 3]] != WALL)
	{
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] - 1;
		info->enemy_posi[i * 3 + 2] = UP;
	}
	else if (info->map[info->enemy_posi[i * 3 + 1] + 1][info->enemy_posi[i
			* 3]] != WALL)
	{
		info->enemy_posi[i * 3 + 1] = info->enemy_posi[i * 3 + 1] + 1;
		info->enemy_posi[i * 3 + 2] = DOWN;
	}
	else if (info->map[info->enemy_posi[i * 3 + 1]][info->enemy_posi[i * 3]
		- 1] != WALL)
	{
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] - 1;
		info->enemy_posi[i * 3 + 2] = LEFT;
	}
	else
	{
		info->enemy_posi[i * 3] = info->enemy_posi[i * 3] + 1;
		info->enemy_posi[i * 3 + 2] = RIGHT;
	}
}
