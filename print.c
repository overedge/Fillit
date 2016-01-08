/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:54:27 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/18 15:45:33 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_letter(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = c;
		i++;
	}
	return (str);
}

char	*ft_fillmap(char *map, int nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < nb * nb + nb)
	{
		map[i] = '.';
		i++;
		j++;
		if (j == nb)
		{
			map[i] = '\n';
			j = 0;
			i++;
		}
	}
	map[i] = '\0';
	return (map);
}

void	ft_printmap(char *map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putchar(map[i]);
		i++;
	}
}

char	*ft_canplace(char *map, char *piece, int index, int nb)
{
	int		i;
	size_t	k;
	int		line;

	i = 0;
	k = index;
	line = 0;
	while (piece[i])
	{
		if ((map[k] == '.' || (ft_isalpha(map[k]) && piece[i] == '.')))
		{
			i++;
			k++;
			if (piece[i] == '\n')
			{
				line++;
				i++;
				k = index + (nb + 1) * line;
			}
		}
		else
			return (0);
	}
	return (map);
}

char	*ft_place(char *map, char *piece, int index, int nb)
{
	int i;
	int k;
	int line;

	i = 0;
	k = index;
	line = 0;
	while (piece[i] && map[k])
	{
		if (map[k] == '.' || (ft_isalpha(map[k]) && piece[i] == '.'))
		{
			if (map[k] == '.')
				map[k] = piece[i];
			i++;
			k++;
			if (piece[i] == '\n')
			{
				line++;
				i++;
				k = index + (nb + 1) * line;
			}
		}
	}
	return (map);
}
