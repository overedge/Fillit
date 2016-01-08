/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:54:27 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/18 15:27:45 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_getletter(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (str[i]);
		i++;
	}
	return (0);
}

char	*ft_removepiece(char *map, char *piece, int index, int nb)
{
	int i;
	int k;
	int line;

	i = 0;
	k = index;
	line = 0;
	while (piece[i] && map[k])
	{
		if (map[k] == ft_getletter(piece))
		{
			map[k] = '.';
		}
		i++;
		k++;
		if (piece[i] == '\n')
		{
			line++;
			i++;
			k = index + (nb + 1) * line;
		}
	}
	return (map);
}

int		ft_countlarg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		ft_fillit(char *map, char **piece, int nb, int size)
{
	size_t index;

	index = 0;
	if (piece[nb] == NULL)
	{
		return (1);
	}
	while (index < ft_strlen(map) - 1)
	{
		if (ft_canplace(map, piece[nb], index, size))
		{
			ft_place(map, piece[nb], index, size);
			if (ft_fillit(map, piece, nb + 1, size))
				return (1);
			else
				ft_removepiece(map, piece[nb], index, size);
		}
		index++;
	}
	return (0);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}
