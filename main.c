/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:55:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/09 18:33:45 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			k;
	char		**tab;
	//t_data		*img;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nfile not available");
		return (0);
	}
	if (checkerror(argv) == 1)
		return (0);
	if (argc == 2)
	{
		k = lengnl(fd);
		close (fd);
		tab = array(fd, k, argv[1]);
		ft_printmap(tab);
		ft_windows((k), ft_strlen(tab[1]), (tab));
	}
	//system("leaks so_long");
	return (0);
}
