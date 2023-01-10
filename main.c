/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:55:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/10 19:11:22 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			k;
	t_data		program;

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
		program.map.map = array(fd, k, argv[1]);
		ft_printmap(program.map.map);
		program.mlx = mlx_init();
		program.window = ft_windows(program.mlx, (k), ft_strlen(program.map.map[1]));
		ft_background(&program, ft_strlen(program.map.map[1]), (k));
		ft_wall(&program, program.map.map, ft_strlen(program.map.map[1]), (k));
		ft_coin(&program, program.map.map, ft_strlen(program.map.map[1]), (k));
		ft_exit(&program, program.map.map, ft_strlen(program.map.map[1]), (k));
		program.sprite = ft_new_sprite(program.mlx, "./sprites/player1.xpm");
		program.position = ft_player(&program, program.map.map, ft_strlen(program.map.map[1]), (k));
		mlx_put_image_to_window(program.mlx, program.window.reference,
			program.sprite.reference, program.position.x, program.position.y);
		mlx_key_hook(program.window.reference, *ft_input, &program);
		mlx_loop(program.mlx);
	}
	//system("leaks so_long");
	return (0);
}
