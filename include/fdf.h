/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:13:48 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/31 11:22:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "libft.h"
# include "struct.h"
# include "mlx.h"

# define HEIGHT 		1300
# define LENGTH 		2500
# define ZOOM			150
# define DEFAULT_X		50
# define DEFAULT_Y		650
# define DEFAULT_COLOR	0xFFFFFFFF
# define DIM_X			1
# define DIM_Y			2
# define ESC_MSG		33
# define MOOVE_FACTOR	20
# define MENU_X			2240
# define MENU_Y			105

# define ESC 			65307
# define PLUS			61
# define MINUS			45
# define LEFT_KEY		65361
# define RIGHT_KEY		65363
# define UP_KEY			65362
# define DOWN_KEY		65364
# define A_KEY			97
# define W_KEY			119
# define D_KEY			100
# define S_KEY			115

/* init.c */
t_mlx	init_all_mlx(char *mapname);
t_img	init_all_img(t_mlx *mlx);

/* put_line.c */
void	all_line(t_img img, t_set set, enum e_color force_color);
int		is_pos_ok(t_set set);
void	put_line(t_img img, t_set set,
			t_math all, enum e_color force_color);
void	my_pixel_put(t_img *img, int x, int y, int color);

/* main.c */
int		print_err(char *s);
int		free_tabtabtab(char ***tab);

/* math.c */
t_co	base_set(t_set set);
t_math	init_mathline(t_set set);
int		check_base(t_set set, t_co base);

/* parsing_fdf.c */
char	***parsing_fdf(char *path);
int		check_parsing(char ***tab);

/* mega_split.c */
char	***mega_split(char *s, int lines);

/* get_info.c */
char	*get_name(char *path);
int		get_zoom(char ***tab);
int		get_maxcolor(char ***tab);
t_info	get_info(char ***parsing);

/* ft_draw.c */
void	ft_draw(char ***tab, t_img img, t_info *info);
t_set	define_set(char *tab1, char *tab2, t_info info, int dim);
void	put_last_line(char ***tab, t_img img, t_info *info);
t_co	define_where(t_info info, int x, int y);
void	refresh_img(t_img img);

/* mlx_colors.c */
int		create_trgb(int t, int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/* get_color.c */
int		get_color(char *tab1, char *tab2, t_info info);
int		get_one_color(char *s, t_info info);
int		ft_xtoi_comma(char *s);

/* key_touched.c */
int		key_touched(int keycode, t_all *all);
void	moove(int keycode, t_all *all);
void	change_color(int keycode, t_all *all);
int		zoom(int keycode, int x, int y, t_all *all);
int		quit_everything(t_all *all, int event);

/* key_touched2.c */
void	altitude(int keycode, t_all *all);

/* all_draw.c */
void	all_draw(t_all *all);
void	put_menu(t_all *all);
void	all_strings(t_all *all);
#endif
