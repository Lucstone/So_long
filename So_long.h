/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:37:18 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/10 19:02:34 by lnaidu           ###   ########.fr       */
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

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

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

typedef struct	s_map
{
	int	count;
	int coin;
	char **map;
}				t_map;

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

typedef struct	s_image 
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct	s_data 
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	position;
	t_map		map;
}				t_data;

t_window	ft_windows(void *mlx, int height, int width/*, char **tab*/);
t_image		ft_new_sprite(void *mlx, char *path);
void	ft_background(t_data *img, int height, int width);
void	ft_wall(t_data *img, char **tab, int width, int height);
int	ft_input(int key, void *param);
int	ft_update (void *param);
t_vector	ft_player(t_data *img, char **tab, int width, int height);
void	ft_coin(t_data *img, char **tab, int width, int height);
void	ft_exit(t_data *img, char **tab, int width, int height);
int	ft_count(char **tab);

#endif