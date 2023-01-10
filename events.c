/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:45:09 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/10 19:08:16 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
int	ft_input(int key, void *param)
{
	t_data *program = (t_data *)param;
	int	i;
	int	j;

	//mlx_clear(program->mlx, program->window.reference);
	program->sprite = ft_new_sprite(program->mlx, "./sprites/player1.xpm");
	j = (program->position.x) / 32;
	i = (program->position.y) / 32;

	program->map.coin = ft_count(program->map.map);

	if (key == 2 && !((program->map.map[i][j + 1]) == '1'))
	{
		program->position.x += program->sprite.size.x;
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x - 32, program->position.y);
	}
	else if (key == 0 && !((program->map.map[i][j - 1]) == '1'))
	{
		program->position.x -= program->sprite.size.x;
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x + 32, program->position.y);
	}
	else if (key == 1 && !((program->map.map[i + 1][j]) == '1'))
	{
		program->position.y = program->position.y + program->sprite.size.y;
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y - 32);
	}
	else if (key == 13 && !((program->map.map[i - 1][j]) == '1'))
	{
		program->position.y -= program->sprite.size.y;
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
		mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y + 32);
	}
	else if (key == 53)
		exit(mlx_destroy_window(program->mlx, program->window.reference));
	if ((program->map.map[i][j]) == 'C')
	{
		(program->map.map[i][j]) = 'X';
	}
	if (((program->map.map[i][j]) == 'E') && (program->map.coin == 0))
		exit(mlx_destroy_window(program->mlx, program->window.reference));
	program->map.count++;
	ft_printf("Key pressed -> %d\n", key);
	ft_printf("ttcoin -> %d\n", program->map.count);
	return (program->map.count);
}

/*int	ft_update (void *param)
{
	t_data	*program = (t_data *)param;
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		program->position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->position.y -= 1;
		frame = 0;
	}
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);

	return (0);
}*/