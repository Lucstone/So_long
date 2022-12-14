/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:52 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/08 16:30:50 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = argc;
	fd = open(argv[1], O_RDONLY);
	if (i == 2)
	{
		/*verifber(argv[1]);
		verifchar(argv[1], fd);
		verifsize(fd);*/
		verifwall(fd);
	}
	return (0);
}
