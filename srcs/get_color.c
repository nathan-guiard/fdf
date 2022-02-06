/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:31:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/18 17:38:31 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_one_color(char *s, t_info info)
{
	int	res;

	if (ft_strchr(s, ',') != NULL && info.force_color == withcode)
		return (ft_xtoi_comma(s));
	res = ft_atoi(s) * 255 / info.color_coef;
	if (res > 255)
		res = 255;
	if (res < -255)
		res = -255;
	if (res <= 0)
		return (create_trgb(255, 255 + res, 255 + res, 255));
	return (create_trgb(255, 255, 255 - res, 255 - res));
}

/*	Pour les positives aller de 0 = ffffff
	a max (a definir) = ff0000	(rouge)		
	en elevant a chaques fois du bleu et 
	du vert									

	Pour les negatives aller de 0 = ffffff
	a max (a definir) = 0000ff	(bleu)		
	en enlevant a chaques fois du rouge et 
	du vert									*/
int	get_color(char *tab1, char *tab2, t_info info)
{
	int	col1;
	int	col2;

	col1 = get_one_color(tab1, info);
	col2 = get_one_color(tab2, info);
	return (create_trgb(255, (get_r(col1) + get_r(col2)) / 2,
			(get_g(col1) + get_g(col2)) / 2, (get_b(col1) + get_b(col2)) / 2));
}

int	ft_xtoi_comma(char *s)
{
	unsigned int	i;
	int				res;
	char			c;

	res = 0;
	i = 0;
	while (s[i] && s[i] != ',')
		i++;
	i++;
	if (s[i] == '0' && s[i + 1] == 'x')
		i += 2;
	while (s[i])
	{
		c = ft_toupper(s[i]);
		if ((c < '0') || (c > 'F') || ((c > '9') && (c < 'A')))
			break ;
		c -= '0';
		if (c > 9)
			c -= 7;
		res = res * 16 + c;
		i++;
	}
	return (res);
}
