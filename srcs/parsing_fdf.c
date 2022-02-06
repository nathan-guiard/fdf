/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:21:46 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/31 12:37:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_whole_file(int fd)
{
	char	*buff;
	char	*res;
	char	*to_free;
	int		line;

	line = 0;
	to_free = NULL;
	to_free++;
	res = NULL;
	buff = NULL;
	while (buff || line == 0)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		line++;
		to_free = res;
		res = join(res, buff);
		free(buff);
	}
	return (res);
}

int	how_many_lines(char *s)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			res++;
		i++;
	}
	return (res);
}

char	***parsing_fdf(char *path)
{
	int		fd;
	char	*whole_file;
	char	***res;
	int		lines;

	fd = open(path, O_RDONLY);
	if (fd <= 2)
		exit(print_err("Erreur lors de l'ouverture du fichier\n"));
	whole_file = get_whole_file(fd);
	lines = how_many_lines(whole_file);
	res = mega_split(whole_file, lines);
	return (res);
}

int	check_parsing(char ***tab)
{
	int	x;
	int	y;
	int	check;
	int	err;

	if (!tab)
		return (print_err("La map n'est pas valide\n"));
	x = 0;
	y = 0;
	err = 0;
	check = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
			y++;
		if (check != y && x != 0)
			err = 1;
		check = y;
		x++;
	}
	if (err == 1 || x == 0 || y == 0)
		return (print_err("La map n'est pas valide\n"));
	return (0);
}
