/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:52:56 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/11 12:56:57 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	cou(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_clean_tetra(char **map, char *str, int *q_p, int *k)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (!ft_isalpha(str[i]))
		i++;
	temp = str[i];
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == temp)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
	*q_p = *q_p + 1;
	*k = *k + 1;
}

static void	if_f(int *i, int *j, int size)
{
	if (*j == size)
	{
		*i = *i + 1;
		*j = 0;
	}
}

static int	c_m(char **map, char **str, int size, int *q_p)
{
	int n;
	int i;
	int j;

	i = 0;
	j = 0;
	n = 0;
	if (*q_p == 0)
		return (1);
	while (i < size)
	{
		if (!(ft_check_tetra(map, i, j, str[n])))
		{
			ft_push_tetra(map, i, j, str[n]);
			*q_p = *q_p - 1;
			n++;
			if (c_m(map, &str[n], size, q_p))
				return (1);
			ft_clean_tetra(map, str[--n], q_p, &j);
		}
		else
			j++;
		if_f(&i, &j, size);
	}
	return (0);
}

void		ft_remap(char **str, int size)
{
	char	**map;
	int		i;
	int		*q_p;
	int		flag;

	map = ft_map(size);
	flag = cou(str);
	q_p = &flag;
	i = c_m(map, str, size, q_p);
	if (!i)
	{
		ft_free(map);
		map = ft_map(size + 1);
		i = c_m(map, str, size + 1, q_p);
		if (!i)
		{
			ft_free(map);
			map = ft_map(size + 2);
			i = c_m(map, str, size + 2, q_p);
		}
	}
	if (i)
		ft_print_map(map);
	ft_free(map);
	ft_free(str);
}
