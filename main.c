/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:01:19 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/18 15:46:34 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

char	**ft_stock(char **tab, char *buf, int nb)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (j < nb)
	{
		if ((tab[j] = ft_memalloc(sizeof(char*) * 21)) == NULL)
			ft_exit();
		k = 0;
		while (k <= 19)
		{
			tab[j][k] = buf[i];
			k++;
			i++;
		}
		tab[j][k] = '\0';
		j++;
		if (buf[i] && buf[i] != '\n')
			ft_exit();
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**tab;
	int		ret;
	char	buf[300000];

	if (argc == 2)
	{
		tab = NULL;
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			ret = read(fd, buf, 300000);
			tab = ft_check_arg(ret);
			tab = ft_stock(tab, buf, ft_get_size(ret));
			ft_check_tab(tab);
			ft_solve(tab, ft_get_size(ret));
			close(fd);
		}
		else
			ft_exit();
	}
	else
		ft_exit();
	return (0);
}
