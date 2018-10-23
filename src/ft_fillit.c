/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:40:25 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 18:32:45 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(char *str)
{
	int		size;
	char	**s;
	char	**s_n;

	if (!ft_validat(str))
		return (0);
	s = ft_str_spl_fil(str);
	s_n = ft_who_first(s);
	size = ft_min_size(s_n);
	ft_remap(s_n, size);
	return (1);
}
