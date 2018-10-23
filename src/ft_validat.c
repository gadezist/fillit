/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:10:36 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 18:45:42 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_one(char *str)
{
	int	i;
	int count_tetra;
	int count_p;
	int count_h;

	i = 0;
	count_p = 0;
	count_h = 0;
	while ((str[i] == '.' || str[i] == '\n' || str[i] == '#') && str[i] != '\0')
	{
		if (str[i] == '.')
			count_p++;
		if (str[i] == '#')
			count_h++;
		i++;
	}
	i++;
	count_tetra = i / 21;
	if (((count_p / 12) != count_tetra || (count_h / 4) != count_tetra))
		return (0);
	if ((i % 21) != 0)
		return (0);
	return (1);
}

static int	check_two(char *str)
{
	int	i;
	int n;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	i = 0;
	n = 0;
	while (str[i])
	{
		n++;
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			if (n > 21)
				return (0);
			n = 0;
		}
		i++;
	}
	return (1);
}

static int	check_three_sp(char *str, int *i, int *sp)
{
	int n;
	int temp_sp;

	n = 0;
	while (n < 4)
	{
		if (str[*i] == '#')
		{
			n++;
			*i = *i + 1;
		}
		else
		{
			temp_sp = 0;
			while (str[*i] != '#')
			{
				*sp = *sp + 1;
				temp_sp++;
				*i = *i + 1;
			}
			if (temp_sp > 4)
				return (0);
		}
	}
	return (1);
}

static int	check_three(char *str)
{
	int i;
	int sp;

	i = 0;
	while (str[i] != '\0')
	{
		sp = 0;
		if (str[i] == '#')
		{
			if (!check_three_sp(str, &i, &sp))
				return (0);
		}
		if ((sp != 0 && sp != 2 && sp != 3 && sp != 4) &&
			(sp != 6 && sp != 7 && sp != 8 && sp != 12))
			return (0);
		if (sp++ > 21)
			return (0);
		i++;
	}
	return (1);
}

int			ft_validat(char *str)
{
	int i;

	i = 0;
	if (!check_one(str) || !check_two(str) || !check_three(str))
	{
		ft_putstr("error\n");
		return (0);
	}
	while (str[i] != '#')
	{
		i++;
		if ((str[i] == '#') &&
			(str[i + 1] != '#' && str[i - 1] != '#' && str[i + 5] != '#'))
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	return (1);
}
