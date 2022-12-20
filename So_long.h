/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:37:18 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/19 12:39:31 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/srclib/libft.h"
# include "./Libft/gnl/get_next_line.h"
# include "./Libft/printf/ft_printf.h"
# include <errno.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

int	verifber(char *file);
int	verifchar(char *file, int fd);
int	verifsize(int fd);
int	verifwall(int fd, int k);
int	lengnl(int fd);
int	topend(char *gnl, int i, int j);

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
#endif