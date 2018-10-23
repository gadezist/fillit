/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:48:34 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 19:18:57 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = (void *)malloc(sizeof(s) * size);
	if (!s)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
