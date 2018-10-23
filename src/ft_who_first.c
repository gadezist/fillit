/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_who_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:08:31 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 18:34:04 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_who_first(char **s)
{
	int	i;
	int j;
	int z;

	i = 0;
	z = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == '#')
				s[i][j] = 'A' + z;
			j++;
		}
		z++;
		i++;
	}
	return (s);
}
