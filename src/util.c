/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:03:12 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 10:54:29 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	util_perror_exit(char *error_message)
{
	ft_putstr_fd("\e[31m", STDERR_FILENO);
	perror(error_message);
	ft_putstr_fd("\e[m", STDERR_FILENO);
	exit(1);
}

void	util_lose_put_msg(t_info *info)
{
	info->status = CLEARED;
	mlx_string_put(info->mlx, info->win, 3, 12, 0xffffff,
			"You lose. See you again.");
	ft_putstr_fd("\e[31mYou lose. See you again.\e[m", STDERR_FILENO);
}

void	util_clear_put_msg(t_info *info)
{
	char	*mv_count_msg;
	char	*mv_num;

	info->status = CLEARED;
	mv_num = ft_itoa(info->mvnum);
	mv_count_msg = ft_strjoin("Congratulation!! game clear Thanks for playing! Move :",
			mv_num);
	ft_putstr_fd("\e[32m", STDOUT_FILENO);
	ft_putstr_fd(mv_count_msg, STDOUT_FILENO);
	ft_putstr_fd("\e[m", STDOUT_FILENO);
	mlx_string_put(info->mlx, info->win, 3, 12, 0xffffff, mv_count_msg);
	free(mv_num);
	free(mv_count_msg);
}

bool	util_clear_check(t_info *info, int move_x, int move_y)
{
	if (info->item_count == 0 && info->map[info->player_posi[1]
		+ move_y][info->player_posi[0] + move_x] == EXIT)
		return (true);
	return (false);
}

bool	util_lose_check(t_info *info, int move_x, int move_y)
{
	int	i;

	i = -1;
	while (++i < info->enemy_count)
	{
		if ((info->player_posi[1] + move_y == info->enemy_posi[i * 3 + 1])
			&& (info->player_posi[0] + move_x == info->enemy_posi[i * 3]))
			return (true);
	}
	return (false);
}
