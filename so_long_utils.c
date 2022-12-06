/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:27:21 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 17:56:38 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"
/*
int	verifber(char *file)
{
	int		i;

	if (!file)
	{
		perror("no file");
		return (EXIT_FAILURE);
	}
	i = ft_strlen(file);
	i = i - 4;
	if (file[i] == '.' && file[i + 1] == 'b' && file[i + 2] == 'e'
		&& file[i + 3] == 'r')
		return (1);
	perror("not a .ber file/n");
	return (EXIT_FAILURE);
}
*/
int	verifchar(char *file)
{
	int 	fd;
	char	*gnl;
	
	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	printf("%s", gnl);
	if (ft_strchr(gnl,'0') || ft_strchr(gnl,'1') || ft_strchr(gnl,'C') ||
		ft_strchr(gnl,'E') || ft_strchr(gnl,'P'))
	{
		while (gnl != 0)
		{
			gnl = get_next_line(fd);
			printf("%s", gnl);
		}
		return (1);
	}
	ft_printf("NON");
	return (EXIT_FAILURE);
}