/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:27:21 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/08 18:22:00 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

/*int	verifber(char *file)
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
	perror("Error\n not a .ber file");
	return (EXIT_FAILURE);
}

int	verifchar(char *file, int fd)
{
	char	*gnl;
	int		i;
	char	*tmp;

	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	i = 0;
	tmp = ft_strtrim(gnl, "\n");
	while (gnl)
	{
		while (gnl[i] != '\0')
		{
			if (!(tmp[i] == '0') && !(gnl[i] == '1') && !(gnl[i] == 'C')
				&& !(gnl[i] == 'E') && !(gnl[i] == 'P') && !(gnl[i] == '\n'))
			{
				perror("Error\n Map not valid unknown character");
				return (EXIT_FAILURE);
			}
			i++;
		}
		gnl = get_next_line(fd);
		tmp = ft_strtrim(gnl, "\n");
		i = 0;
	}
	return (1);
}

int	verifsize(int fd)
{
	char	*gnl;
	char	*tmp;
	size_t	i;

	gnl = get_next_line(fd);
	tmp = ft_strtrim(gnl, "\n");
	i = ft_strlen(tmp);
	while (gnl != '\0')
	{
		if (tmp != 0 && i != ft_strlen(tmp))
		{
			perror("Error\n Not a rectangle");
			return (EXIT_FAILURE);
		}
		gnl = get_next_line(fd);
		tmp = ft_strtrim(gnl, "\n");
	}
	return (1);
}
*/
int lengnl (int fd)
{
	char	*gnl;
	int		i;

	i = 0;
	gnl = get_next_line(fd);
	while (gnl)
		i++;
	return(i);
}
int	verifwall(int fd)
{
	char	*gnl;
	int		i;
	int		j;
	char	*tmp;

	gnl = get_next_line(fd);
	i = ft_strlen(gnl);
	j = 0;
	while (gnl && (i - 1) > j)
	{
		if (gnl && gnl[j] != '1' && gnl[j] != '\n')
		{
			perror("Error\n No Walls valid");
			return (EXIT_FAILURE);
		}
		j++;	
	}
	gnl = get_next_line(fd);
	j = lengnl(fd);
	while (gnl)
	{
		if (gnl[0] != '1' || gnl[i - 2] != '1')
		{
			perror("Error2\n No Walls valid");
			return (EXIT_FAILURE);
		}
		gnl = get_next_line(fd);
	}
	j = 0;
	printf("%s\n", gnl);
	while (gnl && (i - 1) > j)
	{
		if (gnl && gnl[j] != '1' && gnl[j] != '\n')
		{
			perror("Error\n No Walls valid");
			return (EXIT_FAILURE);
		}
		j++;	
	}
	printf("tetst");
	return (1);
}
