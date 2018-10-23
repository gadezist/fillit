/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split_fil.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:08:25 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 18:54:05 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_tetra(char *str)
{
	int	i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

static void		f(char **s, int j)
{
	while (j >= 0)
	{
		free(s[j]);
		s[j] = NULL;
		j--;
	}
}

static char		**ss(char **ret, char *str, int ct, int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < ct)
	{
		k = 0;
		if (!(ret[j] = (char *)malloc(sizeof(char) * 21)))
		{
			f(ret, j);
			free(ret);
			return (NULL);
		}
		ft_memset(ret[j], '\0', 21);
		while (str[i] && k < 21)
		{
			ret[j][k] = str[i];
			i++;
			k++;
		}
		ret[j++][k] = '\0';
	}
	ret[j] = NULL;
	return (ret);
}

char			**ft_str_spl_fil(char *str)
{
	char	**ret;
	int		ct;
	int		k;

	k = 0;
	ct = count_tetra(str);
	ret = (char **)malloc(sizeof(char *) * (ct + 1));
	if (!ret)
	{
		free(ret);
		ret = NULL;
		return (NULL);
	}
	ft_memset(ret, '\0', ct + 1);
	return (ss(ret, str, ct, k));
}
