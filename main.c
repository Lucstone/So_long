/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:28:52 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/20 09:54:24 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"


/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	color(int k)
{
	int	rgb;
	
	rgb = 16711680 + k;
	return (rgb);
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		z;
	

	x = 3;
	y = 3;
	z = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 900, "Hello world!");
	img.img = mlx_new_image(mlx, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	while (x++ < 300)
	{
		my_mlx_pixel_put(&img, x, y, color(z));
		z++;
	}
	z = 0;
	x--;
	while (y++ < 300)
	{
		my_mlx_pixel_put(&img, x, y, color(z));
		z+=2;
	}
	y--;
	while (x-- > 4)
	{
		my_mlx_pixel_put(&img, x, y, color(z));
		z++;
	}
	x++;
	while (y-- > 4)
	{
		my_mlx_pixel_put(&img, x, y, color(z));
		z+=4;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	k;
	
	k = 0;
	i = argc;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nFile not available");
		return(0);
	}
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
