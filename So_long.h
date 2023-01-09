/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:37:18 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/09 18:45:47 by lnaidu           ###   ########.fr       */
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
int	topend(char *gnl, int i);
int	verifdbl(char *file, int fd);
int	lengnl(int fd);
int	checkerror(char **argv);
char	**array(int fd, int k, char *file);
void	**ft_printmap(char **tab);

typedef struct	s_cerror
{
	int c;
	int	e;
	int p;
}				t_cerror;

typedef struct	s_vector
{
	int x;
	int	y;
}				t_vector;

typedef struct	s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct	s_data 
{
	void		*img;
	char		*addr;
	void		*mlx;
	void		*mlx_win;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	int			twidth;
	int			theight;
	t_vector	size;
}				t_data;

typedef struct	s_program {
	void		*mlx;
	t_window	window;
	t_data		sprite;
	t_vector	sprite_position;
}				t_program;

void	ft_background(t_data *img, int width, int height);
void	ft_windows(int height, int width, char **tab);

#endif