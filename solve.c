/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 12:54:27 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/18 15:25:41 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_calculsize(int nb)
{
	int nbdiese;

	nbdiese = nb * 4;
	return (ft_sqrt(nbdiese));
}

void	ft_solve(char **tab, int size)
{
	int		i;
	char	**tabclear;
	char	*map;

	tabclear = (char**)malloc(sizeof(tabclear) * size + 1);
	i = 0;
	while (tab[i] != NULL)
	{
		tabclear[i] = (char*)malloc(sizeof(char*) * size + 1);
		tabclear[i] = ft_letter(ft_clear(tab[i]), 'A' + i);
		i++;
	}
	tabclear[i] = NULL;
	free(tab);
	size = ft_calculsize(size);
	map = (char*)malloc(sizeof(map) * (size * size + size + 1));
	map = ft_fillmap(map, size);
	while (ft_fillit(map, tabclear, 0, size) == 0)
	{
		ft_fillit(map, tabclear, 0, size);
		size++;
		map = (char*)malloc(sizeof(map) * (size * size + size + 1));
		map = ft_fillmap(map, size);
	}
	ft_printmap(map);
}
