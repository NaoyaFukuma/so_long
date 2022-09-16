/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:06:03 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 10:53:42 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	to_up(t_info *info);
static void	to_down(t_info *info);
static void	to_right(t_info *info);
static void	to_left(t_info *info);

int	keypress(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		destroy_window(info);
	if (info->status == CLEARED)
		return (0);
	if (keycode == KEY_W)
		to_up(info);
	if (keycode == KEY_A)
		to_left(info);
	if (keycode == KEY_S)
		to_down(info);
	if (keycode == KEY_D)
		to_right(info);
	return (0);
}

static void	to_up(t_info *info)
{
	if (info->map[info->player_posi[1] - 1][info->player_posi[0]] == WALL)
		return ;
	info->mvnum++;
	mlx_clear_window(info->mlx, info->win);
	if (util_clear_check(info, 0, -1))
		util_clear_put_msg(info);
	else if (util_lose_check(info, 0, -1))
		util_lose_put_msg(info);
	else
	{
		if (info->map[info->player_posi[1] - 1][info->player_posi[0]] == ITEM)
		{
			info->map[info->player_posi[1] - 1][info->player_posi[0]] = BLANK;
			info->item_count--;
		}
		info->player_posi[1] = info->player_posi[1] - 1;
		info->player_posi[2] = UP;
		put_map(info);
	}
}

static void	to_down(t_info *info)
{
	if (info->map[info->player_posi[1] + 1][info->player_posi[0]] == WALL)
		return ;
	info->mvnum++;
	mlx_clear_window(info->mlx, info->win);
	if (util_clear_check(info, 0, 1))
		util_clear_put_msg(info);
	else if (util_lose_check(info, 0, 1))
		util_lose_put_msg(info);
	else
	{
		if (info->map[info->player_posi[1] - 1][info->player_posi[0]] == ITEM)
		{
			info->map[info->player_posi[1] - 1][info->player_posi[0]] = BLANK;
			info->item_count--;
		}
		info->player_posi[1] = info->player_posi[1] + 1;
		info->player_posi[2] = DOWN;
		put_map(info);
	}
}

static void	to_left(t_info *info)
{
	if (info->map[info->player_posi[1]][info->player_posi[0] - 1] == WALL)
		return ;
	info->mvnum++;
	mlx_clear_window(info->mlx, info->win);
	if (util_clear_check(info, -1, 0))
		util_clear_put_msg(info);
	else if (util_lose_check(info, -1, 0))
		util_lose_put_msg(info);
	else
	{
		if (info->map[info->player_posi[1]][info->player_posi[0] - 1] == ITEM)
		{
			info->map[info->player_posi[1]][info->player_posi[0] - 1] = BLANK;
			info->item_count--;
		}
		info->player_posi[0] = info->player_posi[0] - 1;
		info->player_posi[2] = LEFT;
		put_map(info);
	}
}

static void	to_right(t_info *info)
{
	if (info->map[info->player_posi[1]][info->player_posi[0] + 1] == WALL)
		return ;
	info->mvnum++;
	mlx_clear_window(info->mlx, info->win);
	if (util_clear_check(info, 1, 0))
		util_clear_put_msg(info);
	else if (util_lose_check(info, 1, 0))
		util_lose_put_msg(info);
	else
	{
		if (info->map[info->player_posi[1]][info->player_posi[0] + 1] == ITEM)
		{
			info->map[info->player_posi[1]][info->player_posi[0] + 1] = BLANK;
			info->item_count--;
		}
		info->player_posi[0] = info->player_posi[0] + 1;
		info->player_posi[2] = RIGHT;
		put_map(info);
	}
}
