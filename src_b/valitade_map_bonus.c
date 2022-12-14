/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valitade_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:01:39 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 20:13:55 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	validate_rectagular(t_info *info);
static void	validate_around_wall(t_info *info);
static void	validate_mapchips(t_info *info, size_t x, size_t y);

void	validate_map(t_info *info)
{
	if (info->map[0] == NULL || info->map[0][0] == '\n')
		util_perror_exit("invalid map", 0);
	if (info->map[info->hei - 1][ft_strlen(info->map[info->hei - 1])
		- 1] != '\n')
		info->map[info->hei - 1] = ft_strjoin(info->map[info->hei - 1], "\n");
	else
		util_perror_exit("invalid map", 0);
	if (!info->map[info->hei - 1])
		util_perror_exit("ft_strjoin", 1);
	validate_rectagular(info);
	validate_around_wall(info);
	validate_mapchips(info, -1, -1);
}

static void	validate_rectagular(t_info *info)
{
	size_t	i;

	i = 0;
	info->wdt = ft_strlen(info->map[0]) - 1;
	while (info->map[++i])
		if (info->wdt != ft_strlen(info->map[i]) - 1)
			util_perror_exit("no rectangular of map", 0);
}

static void	validate_around_wall(t_info *info)
{
	size_t	i;

	i = -1;
	while (++i < info->wdt)
		if (info->map[0][i] != WALL || info->map[info->hei - 1][i] != WALL)
			util_perror_exit("invalid around wall of map", 0);
	i = -1;
	while (++i < info->hei)
		if (info->map[i][0] != WALL || info->map[i][info->wdt - 1] != WALL)
			util_perror_exit("invalid around wall of map", 0);
}

static void	validate_mapchips(t_info *info, size_t x, size_t y)
{
	int	p_count;
	int	e_count;

	p_count = 0;
	e_count = 0;
	while (++y < info->hei)
	{
		x = -1;
		while (++x < info->wdt)
		{
			if (!ft_strchr("01CEPT", info->map[y][x]))
				util_perror_exit("invalid mapchip", 0);
			if (info->map[y][x] == PLAYER)
				p_count++;
			else if (info->map[y][x] == ITEM)
				info->item_count++;
			else if (info->map[y][x] == EXIT)
				e_count++;
			else if (info->map[y][x] == ENEMY)
				info->enemy_count++;
		}
	}
	if (p_count != 1 || e_count != 1 || info->item_count == 0)
		util_perror_exit("invalid chip number", 0);
}
