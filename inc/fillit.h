/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:42:52 by vmartynu          #+#    #+#             */
/*   Updated: 2017/12/08 20:41:38 by vmartynu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_fillit(char *str);
int		ft_validat(char *str);
char	**ft_str_spl_fil(char *str);
char	**ft_who_first(char **s);
char	**ft_map(int size);
void	ft_print_map(char **map);
int		ft_min_size(char **s);
void	ft_push_tetra(char **map, int i_m, int j_m, char *str);
int		ft_check_tetra(char **map, int i_m, int j_m, char *str);
void	ft_remap(char **str, int size);
int		ft_alpha(char *str, int c, int i);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
int		ft_isalpha(int c);
void	ft_free(char **map);
void	*ft_memset(void *memptr, int val, size_t num);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);

#endif
