/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:06:54 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/28 16:56:13 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum	e_rot
{
	rot1 = 1,
	rot2 = 2,
	rot3 = 3,
	rot4 = 4
};

enum e_color
{
	red = 0xFFFF0000,
	blue = 0xFF0000FF,
	green = 0xFF00FF00,
	yellow = 0xFFFFFF00,
	orange = 0xFFFF7F00,
	pink = 0xFFF700FF,
	magenta = 0xFF7F00FF,
	white = 0xFFFFFFFF,
	withcode = 1,
	nocode = 0,
};

typedef struct s_mlx
{
	void	*init;
	void	*win;
}	t_mlx;

typedef struct s_co
{
	int	x;
	int	y;
	int	alt;
}	t_co;

typedef struct s_set
{
	t_co	a;
	t_co	b;
	int		color;
}	t_set;

typedef struct s_err
{
	float	a;
	float	b;
	float	c;
}	t_err;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_math
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_math;

typedef struct s_info
{
	t_co			where;
	t_co			base_point;
	int				zoom;
	enum e_rot		rot;
	int				color_coef;
	enum e_color	force_color;
	int				alt;
}	t_info;

typedef struct s_all
{
	t_info	*info;
	t_mlx	*mlx;
	t_img	*img;
	char	***tab;
}	t_all;

#endif