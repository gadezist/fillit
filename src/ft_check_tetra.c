/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:47:12 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 18:44:16 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check_left(char *str, int left, int *i, int *j_m)
{
	while (left >= 0)
	{
		if (!ft_alpha(str, str[*i - left], *i - left))
			left--;
		else
		{
			*i = *i - left - 1;
			*j_m = *j_m - left;
			break ;
		}
	}
}

static int		ft_check_if(char *str, int *i_m, int *j_m, int *i)
{
	if (!ft_alpha(str, str[*i + 1], *i + 1))
	{
		*i_m = *i_m + 1;
		*i += 5;
		return (0);
	}
	else
	{
		*i = *i + 1;
		*j_m = *j_m + 1;
	}
	return (1);
}

int				ft_check_tetra(char **map, int i_m, int j_m, char *str)
{
	int		i;
	int		j;
	int		count;
	int		left;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (ft_alpha(str, str[i], i))
		{
			if ((!map[i_m] || map[i_m][j_m] != '.'))
				return (1);
			if (!ft_check_if(str, &i_m, &j_m, &i))
				break ;
		}
		left = 2;
		ft_check_left(str, left, &i, &j_m);
		i++;
	}
	return (0);
}
