/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:52 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/16 17:18:22 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	k;

	k = 0;
	i = argc;
	fd = open(argv[1], O_RDONLY);
	if (i == 2)
	{
		verifber(argv[1]);
		verifchar(argv[1], fd);
		verifsize(fd);
		fd = open(argv[1], O_RDONLY);
		k = lengnl(fd);
		fd = open(argv[1], O_RDONLY);
		verifwall(fd, k);
	}
	return (0);
}
