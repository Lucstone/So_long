/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:49:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/09 18:51:42 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_background(t_data *img, int width, int height)
{
	img->img = mlx_xpm_file_to_image (img->mlx, "./sprites/floor.xpm", &width, &height);
	img->addr = mlx_get_data_addr (img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->y = 0;
	img->x = 0;
	while (img->y < img->twidth)
	{
		while (img->x < img->theight)
		{
			mlx_put_image_to_window(img->mlx,
				img->mlx_win, img->img, img->y, img->x);
			img->x = img->x + 32;
		}
		img->x = 0;
		img->y = img->y + 32;
	}
}

void	ft_winchar(t_data *img, char **tab, char c)
{
	int	i;
	int	j;

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	i = 0;
	img->y = 0;
	img->x = 0;
	while (img->y < img->theight)
	{
		j = 0;
		while (img->x < img->twidth)
		{
			if (tab[i][j] == c)
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, img->x, img->y);
			img->x = img->x + 32;
			j++;
		}
		img->x = 0;
		img->y = img->y + 32;
		i++;
	}
}


void	ft_player3(t_data *img, char **tab, char c)
{
	int	i;
	int	j;

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	i = 0;
	img->y = 0;
	img->x = 0;
	while (img->y < img->theight)
	{
		j = 0;
		while (img->x < img->twidth)
		{
			if (tab[i][j] == c)
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, img->x, img->y);
			img->x = img->x + 32;
			j++;
		}
		img->x = 0;
		img->y = img->y + 32;
		i++;
	}
}

int	tclose(int keysys , t_data *vars)
{
	printf("the escape button num is %d\n", keysys);
	if (keysys == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		//mlx_clear_window(vars->mlx, vars->img);
	}
	return (0);
}

int	ft_input(int key, void *param)
{
	t_program *program = (t_program *)param;

	// mlx function that clears the window
	//mlx_clear_window(program->mlx, program->window.reference);

	// move in a direction based on the key
	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.img, program->sprite_position.x, program->sprite_position.y);
	return (0);
}

void	ft_windows(int height, int width, char **tab)
{
	t_data	img;

	height = height * 32;
	width = width * 32;
	img.theight = height;
	img.twidth = width;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, width, height, "So_long42");
	ft_background(&img, width, height);
	img.img = mlx_xpm_file_to_image(img.mlx, "./sprites/wall.xpm", &width, &height);
	ft_winchar(&img, tab, '1');
	/*img.img = mlx_xpm_file_to_image(img.mlx, "./sprites/exit.xpm", &width, &height);
	ft_winchar(&img, tab, 'E');
	img.img = mlx_xpm_file_to_image(img.mlx, "./sprites/bone.xpm", &width, &height);
	ft_winchar(&img, tab, 'C');*/
	img.img = mlx_xpm_file_to_image(img.mlx, "./sprites/player1.xpm", &width, &height);
	ft_player3(&img, tab, 'P');
	mlx_hook(img.mlx_win, 2, 1L<<0, tclose, &img);
	mlx_hook(img.mlx_win, 2, 1L<<0, ft_input, &img);
	mlx_loop(img.mlx);
}
