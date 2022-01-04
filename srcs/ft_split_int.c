/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 03:27:14 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/04 03:43:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res += 1;
		i++;
	}
	return (res);
}

int	*intlloc(char *s, char c, int *i)
{
	int	*res;
	int	j;
	int	nbs;

	nbs = count_nbs(s, c, *i);
	res = malloc(sizeof(int) * nbs);
}
int	**ft_split_int(char *s, char c)
{
	int	**res;
	int	lignes;
	int	i;
	int	*pi;
	int	j;

	if (!s)
		return (NULL);
	i = 0;
	pi = &i;
	mots = word_count(s, c);
	j = 0;
	res = malloc((mots + 1) * sizeof(int *));
	if (!res)
		return (NULL);
	while (j < lignes)
	{
		res[j] = intlloc(s, c, pi);
		if (!res[j])
			return (free_all(res));
		j++;
	}
	res[lignes] = NULL;
	return (res);
