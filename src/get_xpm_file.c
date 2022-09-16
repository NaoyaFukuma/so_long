/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:46:42 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 14:26:23 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_xpm(t_info *info, int wid, int hei);
static void	get_enemy_xpm(t_info *info, int wid, int hei);
static bool check_null_xpm_file(t_info *info);


void	get_xpm_file(t_info *info)
{
	int	wid;
	int	hei;

	wid = 0;
	hei = 0;
	get_player_xpm(info, wid, hei);
	get_enemy_xpm(info, wid, hei);
	info->img.blank = mlx_xpm_file_to_image(
		info->mlx, "./img/blank/b.xpm", &wid, &hei);
	info->img.wall = mlx_xpm_file_to_image(
		info->mlx, "./img/wall/w.xpm", &wid, &hei);
	info->img.item = mlx_xpm_file_to_image(
		info->mlx, "./img/item/i.xpm", &wid, &hei);
	info->img.exit = mlx_xpm_file_to_image(
		info->mlx, "./img/exit/exit.xpm", &wid, &hei);
	if (check_null_xpm_file(info))
		util_perror_exit("mlx_xpm_file_to_image", 0);
}

static void	get_player_xpm(t_info *info, int wid, int hei)
{
	info->img.p_d1 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/md1.xpm", &wid, &hei);
	info->img.p_d2 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/md2.xpm", &wid, &hei);
	info->img.p_d3 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/md3.xpm", &wid, &hei);
	info->img.p_u1 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/mu1.xpm", &wid, &hei);
	info->img.p_u2 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/mu2.xpm", &wid, &hei);
	info->img.p_u3 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/mu3.xpm", &wid, &hei);
	info->img.p_r1 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/mr1.xpm", &wid, &hei);
	info->img.p_r2 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/mr2.xpm", &wid, &hei);
	info->img.p_r3 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/mr3.xpm", &wid, &hei);
	info->img.p_l1 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/ml1.xpm", &wid, &hei);
	info->img.p_l2 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/ml2.xpm", &wid, &hei);
	info->img.p_l3 = mlx_xpm_file_to_image(
		info->mlx, "./img/player/ml3.xpm", &wid, &hei);
}

static void	get_enemy_xpm(t_info *info, int wid, int hei)
{
	info->img.t_d1 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyd1.xpm", &wid, &hei);
	info->img.t_d2 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyd2.xpm", &wid, &hei);
	info->img.t_d3 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyd3.xpm", &wid, &hei);
	info->img.t_u1 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyu1.xpm", &wid, &hei);
	info->img.t_u2 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyu2.xpm", &wid, &hei);
	info->img.t_u3 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyu3.xpm", &wid, &hei);
	info->img.t_r1 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyr1.xpm", &wid, &hei);
	info->img.t_r2 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyr2.xpm", &wid, &hei);
	info->img.t_r3 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyr3.xpm", &wid, &hei);
	info->img.t_l1 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyl1.xpm", &wid, &hei);
	info->img.t_l2 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyl2.xpm", &wid, &hei);
	info->img.t_l3 = mlx_xpm_file_to_image(
		info->mlx, "./img/enemy/enemyl3.xpm", &wid, &hei);
}

static bool check_null_xpm_file(t_info *info)
{
	if (info->img.blank == NULL || info->img.wall == NULL ||
	info->img.item == NULL || info->img.exit == NULL || info->img.p_d1 == NULL ||
	info->img.p_d2 == NULL || info->img.p_d3 == NULL || info->img.p_u1 == NULL ||
	info->img.p_u2 == NULL || info->img.p_u3 == NULL || info->img.p_r1 == NULL ||
	info->img.p_r2 == NULL || info->img.p_r3 == NULL || info->img.p_l1 == NULL ||
	info->img.p_l2 == NULL || info->img.p_l3 == NULL || info->img.t_d1 == NULL ||
	info->img.t_d2 == NULL || info->img.t_d3 == NULL || info->img.t_u1 == NULL ||
	info->img.t_u2 == NULL || info->img.t_u3 == NULL || info->img.t_r1 == NULL ||
	info->img.t_r2 == NULL || info->img.t_r3 == NULL || info->img.t_l1 == NULL ||
	info->img.t_l2 == NULL || info->img.t_l3 == NULL)
		return (true);
	return (false);
}
