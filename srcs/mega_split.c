/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:18:06 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/31 10:57:01 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	word_count_nl(char const *s, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] != c && (s[i + 1] == c
				|| s[i + 1] == '\0' || s[i + 1] == '\n'))
			res += 1;
		i++;
	}
	return (res);
}

static char	*tablloc_nl(char const *s, char c, int *i)
{
	char		*res;
	int			j;

	j = *i;
	while (s[j] == c)
		j++;
	*i = j;
	while (s[j] != '\0' && s[j] != c && s[j] != '\n')
		j++;
	res = (char *)malloc((j - *i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s[*i] != '\0' && s[*i] != c && s[*i] != '\n')
	{
		res[j] = s[*i];
		*i += 1;
		j++;
	}
	res[j] = '\0';
	return (res);
}

static void	*free_all_mega(char **s)
{
	int	i;

	i = 0;
	while (*s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split_nl(char const *s, char c)
{
	char	**res;
	int		mots;
	int		j;
	int		i;
	int		*pi;

	if (!s)
		return (NULL);
	i = 0;
	pi = &i;
	mots = word_count_nl(s, c);
	j = 0;
	res = malloc((mots + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < mots)
	{
		res[j] = tablloc_nl(s, c, pi);
		if (!res[j])
			return (free_all_mega(res));
		j++;
	}
	res[mots] = NULL;
	return (res);
}

char	***mega_split(char *s, int lines)
{
	char	***res;
	int		i;
	char	*to_free;

	i = 0;
	res = malloc(sizeof(char **) * (lines + 1));
	if (!res)
		return (NULL);
	while (i < lines)
	{
		res[i] = ft_split_nl(s, ' ');
		to_free = s;
		s = new_rest(s);
		if (to_free && i < lines)
			free(to_free);
		i++;
	}
	free(s);
	res[lines] = NULL;
	return (res);
}
