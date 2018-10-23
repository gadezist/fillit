/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:18:54 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 19:10:44 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**point_map(char **map, int size)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void		f(char **s, int j)
{
	while (j)
	{
		free(s[j]);
		s[j] = NULL;
		j--;
	}
	free(s[j]);
	s[j] = NULL;
}

char			**ft_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * size + 1);
	if (!map)
	{
		free(map);
		map = NULL;
		return (NULL);
	}
	while (i < size)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * size + 1);
		if (!map[i])
		{
			f(map, i);
			free(map);
			map = NULL;
			return (NULL);
		}
		i++;
	}
	return (point_map(map, size));
}
