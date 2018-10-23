/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:51:55 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 18:35:28 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_sqrt(int nb)
{
	int	a;
	int	da;

	a = 0;
	da = 0;
	while (da <= nb + 1)
	{
		da = a * a;
		if (da == nb)
			return (a);
		else
			a++;
	}
	return (0);
}

int				ft_min_size(char **s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (s[i])
		i++;
	ret = 4 * i;
	while ((ft_sqrt(ret) == 0))
		ret = ret + 1;
	return (ft_sqrt(ret));
}
