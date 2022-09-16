/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:01:39 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/16 14:25:40 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_file_name(int ac, char *file_name)
{
	size_t	len;

	if (ac != 2)
		util_perror_exit("invalid number of arguments", 0);
	len = ft_strlen(file_name);
	if (len < 5)
		util_perror_exit("invalid filename of map", 0);
	if (ft_memcmp(&file_name[len - 4], ".ber", 5))
		util_perror_exit("invalid extension of map", 0);
	return ;
}
