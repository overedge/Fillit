/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:01:19 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/18 15:45:51 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_count(char *str)
{
	int i;
	int piece;
	int point;
	int back;

	i = 0;
	piece = 0;
	point = 0;
	back = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			piece++;
		else if (str[i] == '.')
			point++;
		else if (str[i] == '\n')
			back++;
		i++;
	}
	if (piece != 4 || point != 12 || back != 4)
		ft_exit();
}

int		ft_count_link(char *str, int i)
{
	int nb;

	nb = 0;
	if (str[i + 1] == '#')
		nb++;
	if (str[i + 5] == '#')
		nb++;
	if (str[i - 1] == '#')
		nb++;
	if (str[i - 5] == '#')
		nb++;
	return (nb);
}

void	ft_check_tab(char **tab)
{
	int i;
	int j;
	int link;

	i = 0;
	while (tab[i])
	{
		j = 0;
		ft_count(tab[i]);
		link = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '#')
			{
				if (tab[i][j + 1] != '#' && tab[i][j - 1] != '#'
						&& tab[i][j + 5] != '#' && tab[i][j - 5] != '#')
					ft_exit();
				link += ft_count_link(tab[i], j);
			}
			j++;
		}
		if (link < 6)
			ft_exit();
		i++;
	}
}

char	**ft_check_arg(int ret)
{
	char **tab;

	tab = NULL;
	if (ret < 420)
	{
		if ((ret / 20 - 1 != ret % 20 || (ret / 20 == 0 && ret % 20 != 1)))
			ft_exit();
		if ((tab = (char**)malloc(sizeof(tab) * (ret % 20 + 2))) == NULL)
			ft_exit();
	}
	else if (ret >= 420)
	{
		if ((ret / 20 - 1 != ret % 20 + 21))
			ft_exit();
		if ((tab = (char**)malloc(sizeof(tab) * (ret % 20 + 22))) == NULL)
			ft_exit();
	}
	return (tab);
}

int		ft_get_size(int ret)
{
	if (ret < 420)
		return (ret % 20 + 1);
	else
		return (ret % 20 + 21);
}
