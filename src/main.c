/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:38:00 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 20:59:49 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 547

int		main(int argc, char **argv)
{
	char	buf[BUF_SIZE];
	int		descr;
	int		red;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	else
	{
		descr = open(argv[1], O_RDONLY);
		if (descr)
		{
			red = read(descr, buf, BUF_SIZE);
			buf[red] = '\0';
		}
		if (!ft_fillit(buf))
			return (0);
		if (close(descr) == -1)
			return (1);
		return (0);
	}
}
