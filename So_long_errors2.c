/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_errors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:26:25 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/19 17:12:40 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	lengnl(int fd)
{
	char	*gnl;
	int		j;

	gnl = get_next_line(fd);
	j = 0;
	while (gnl)
	{
		j++;
		gnl = get_next_line(fd);
	}
	return (j);
}

int	topend(char *gnl, int i, int j)
{
	while (gnl && (i - 1) > j)
	{
		if (gnl && gnl[j] != '1' && gnl[j] != '\n')
		{
			perror("Error\n No Walls valid");
			return (EXIT_FAILURE);
		}
		j++;
	}
	return (1);
}

int	verifwall(int fd, int k)
{
	char	*gnl;
	int		i;
	int		j;

	gnl = get_next_line(fd);
	i = ft_strlen(gnl);
	j = 0;
	topend(gnl, i, j);
	while (gnl && (k - 2) > 0)
	{
		gnl = get_next_line(fd);
		k--;
		if (gnl && (gnl[0] != '1' || gnl[i - 2] != '1'))
		{
			perror("Error2\n No Walls valid");
			return (EXIT_FAILURE);
		}
	}
	gnl = get_next_line(fd);
	j = 0;
	topend(gnl, i, j);
	return (1);
}
