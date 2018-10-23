/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:10:14 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 18:44:09 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		f(int *t, int *i, int *j_m, char *str)
{
	while (*t >= 0)
	{
		if (!ft_alpha(str, str[*i - *t], *i - *t))
			*t = *t - 1;
		else
		{
			*i = *i - *t - 1;
			*j_m = *j_m - *t;
			break ;
		}
	}
}

static int		f_(char *str, int *i, int *i_m, int *j_m)
{
	if (!ft_alpha(str, str[*i + 1], *i + 1))
	{
		*i_m = *i_m + 1;
		*i = *i + 5;
		return (1);
	}
	else
	{
		*i = *i + 1;
		*j_m = *j_m + 1;
	}
	return (0);
}

void			ft_push_tetra(char **map, int i_m, int j_m, char *str)
{
	int		i;
	int		count;
	int		t;

	i = 0;
	count = 0;
	t = 2;
	while (str[i] != '\0')
	{
		while (ft_alpha(str, str[i], i))
		{
			map[i_m][j_m] = str[i];
			if (f_(str, &i, &i_m, &j_m))
				break ;
		}
		t = 2;
		f(&t, &i, &j_m, str);
		i++;
	}
}
