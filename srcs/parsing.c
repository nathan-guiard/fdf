/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 01:50:10 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/04 03:46:20 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**get_file(char *name)
{
	int	fd;
	int	**res;
	char	*whole_file;
	char	*buff;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = 1;
	while (buff)
	{	
	
		buff = get_next_line(fd);
		if (!buff)
			return (free_whole(whole_file));
		whole_file = join(whole_file, buff);
	}
	res = ft_split_int(whole_file, '\n');
	return (res);
}

/* Need check si toutes les lignes font la meme taille
 * Pour ca go faire une structure pour le tableau d int
 * avec le tableau et la taille
 *
 * Aussi ca vas renvoyer une structure de structure de 
 * tableau d int avec le tableau d int et sa taille 
 * "x" et "y"						*/
