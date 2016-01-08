/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:43:36 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/18 15:48:53 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>

void	ft_putchar(char c);
int		ft_isalpha(int c);
void	ft_putstr(char *str);
void	*ft_memalloc(size_t size);
size_t	ft_strlen(const char *s);
void	ft_exit(void);
char	**ft_stock(char **tab, char *buf, int nb);
void	ft_count(char *str);
int		ft_count_link(char *str, int i);
void	ft_check_tab(char **tab);
char	**ft_check_arg(int ret);
int		ft_get_size(int ret);
int		ft_newsize(char *str);
int		ft_lineempty(char *str, int i);
int		ft_colempty(char *str, int i);
char	*ft_newchar(char *src, char *dest);
char	*ft_clear(char *str);
char	*ft_letter(char *str, char c);
char	*ft_fillmap(char *map, int nb);
void	ft_printmap(char *map);
char	*ft_canplace(char *map, char *piece, int index, int nb);
char	*ft_place(char *map, char *piece, int index, int nb);
char	ft_getltter(char *str);
char	*ft_removeplace(char *map, char *piece, int index, int nb);
int		ft_countlarg(char *str);
int		ft_fillit(char *map, char **piece, int nb, int size);
int		ft_sqrt(int nb);
int		ft_calculsize(int nb);
void	ft_solve(char **tab, int size);
#endif
