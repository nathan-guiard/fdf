/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:13:48 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/04 03:21:32 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
#include "libft.h"

# define ESC 65307

typedef struct s_mlx
{
	void *init;
	void *win;
	int	x;
	int	y;
}	t_mlx;

typedef struct s_co
{
	int	x;
	int	y;
	int	alt;
}	t_co;

typedef struct s_err
{
	float a;
	float b;
	float c;
}	t_err;

typedef struct s_mathline
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_mathline;

t_mathline	init_mathline(t_co a, t_co b);
void		all_line(t_mlx *mlx, t_co a, t_co b);
void		put_cross(t_mlx *mlx, int x, int y);
void		put_bg(t_mlx *mlx, int color, int x, int y);
int		print_key(int key, t_mlx *mlx);
int		is_pos_ok(t_mlx *mlx, t_mathline all, t_co a, t_co b);
void 		put_line(t_mlx *mlx, t_co a, t_co b, t_mathline all);

# endif
