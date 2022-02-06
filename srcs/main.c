/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:14:40 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/31 12:19:57 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_err(char *s)
{
	set_layout(C_RED, C_RESET, C_BOLD);
	ft_putstr_fd(s, 2);
	set_layout(C_RESET, C_RESET, C_RESET);
	return (1);
}

int	free_tabtabtab(char ***tab)
{
	int	a;
	int	b;

	a = 0;
	if (!tab)
		exit(1);
	while (tab[a])
	{
		b = 0;
		while (tab[a][b])
		{
			free(tab[a][b]);
			b++;
		}
		free(tab[a]);
		a++;
	}
	free(tab[a]);
	free(tab);
	exit(0);
}

t_all	get_all(t_mlx *mlx, t_info *info, t_img *img, char ***tab)
{
	t_all	res;

	res.mlx = mlx;
	res.info = info;
	res.img = img;
	res.tab = tab;
	return (res);
}

int	main(int argc, char **argv)
{
	char	***parsing_tab;
	t_mlx	mlx;
	t_img	img;
	t_info	info;
	t_all	all;

	if (argc != 2)
		return (print_err("Le nombre d'argument est different de 2!\n"));
	parsing_tab = parsing_fdf(argv[1]);
	if (check_parsing(parsing_tab) == 1)
		return (free_tabtabtab(parsing_tab));
	info = get_info(parsing_tab);
	mlx = init_all_mlx(argv[1]);
	img = init_all_img(&mlx);
	all = get_all(&mlx, &info, &img, parsing_tab);
	all_draw(&all);
	mlx_mouse_hook(mlx.win, zoom, &all);
	mlx_hook(mlx.win, 33, 0, quit_everything, &all);
	mlx_key_hook(mlx.win, key_touched, &all);
	mlx_loop(mlx.init);
	quit_everything(&all, 1);
	return (0);
}
