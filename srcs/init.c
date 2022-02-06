/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:47:07 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/28 15:16:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	init_all_mlx(char *mapname)
{
	t_mlx	mlx;
	char	*name;

	name = get_name(mapname);
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, LENGTH, HEIGHT, name);
	free(name);
	return (mlx);
}

t_img	init_all_img(t_mlx *mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx->init, LENGTH + 1, HEIGHT + 1);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
