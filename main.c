/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:11:35 by nfukuma           #+#    #+#             */
/*   Updated: 2022/09/06 10:46:10 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <sys/errno.h>
#define WIN_WIDTH 900
#define WIN_HEIGHT 600


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	int	i;
	int	j;

	errno = 0;
	perror("test");

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	data.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);
	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
		// 	if (WIN_HEIGHT - 450 <= i && i < WIN_HEIGHT - 150 && WIN_WIDTH - 600 <=  j && j < WIN_WIDTH - 300 )
				my_mlx_pixel_put(&data, i, j, 0x00000E9F);
			j++;
		}
				mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
		i++;
	}




	mlx_loop(mlx);
	return 0;
}
