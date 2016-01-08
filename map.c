/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:54:27 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/18 15:23:08 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_newsize(char *str)
{
	int i;
	int nb;
	int test;

	i = 0;
	test = 0;
	nb = 20;
	while (i <= 20)
	{
		if (str[i] == '.' && str[i + 1] == '.' && str[i + 2] == '.'
				&& str[i + 3] == '.')
		{
			test++;
			nb -= 5;
		}
		i += 5;
	}
	i = -1;
	while (++i < 5)
	{
		if (str[i] == '.' && str[i + 5] == '.' && str[i + 10] == '.'
				&& str[i + 15] == '.')
			nb -= 4 - test;
	}
	return (nb);
}

int		ft_lineempty(char *str, int i)
{
	int n;

	n = i / 5 * 5;
	if (str[n] == '.' && str[n + 1] == '.' && str[n + 2] == '.'
			&& str[n + 3] == '.')
		return (1);
	return (0);
}

int		ft_colempty(char *str, int i)
{
	int n;

	while (i > 4)
		i -= 5;
	n = i;
	if (str[n] == '.' && str[n + 5] == '.' && str[n + 10] == '.'
			&& str[n + 15] == '.')
		return (1);
	return (0);
}

char	*ft_newchar(char *src, char *dest)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_lineempty(src, i) || ft_colempty(src, i))
	{
		if (ft_lineempty(src, i))
			i += 5;
		if (ft_colempty(src, i))
			i++;
	}
	while (src[i] && !ft_lineempty(src, i) && !ft_colempty(src, i))
	{
		dest[j] = src[i];
		j++;
		i++;
		while (src[i] && (ft_lineempty(src, i) || ft_colempty(src, i)))
			i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_clear(char *str)
{
	char *newstr;

	newstr = (char*)malloc(sizeof(newstr) * (ft_newsize(str) + 1));
	newstr = ft_newchar(str, newstr);
	return (newstr);
}
