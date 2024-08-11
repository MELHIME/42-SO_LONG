/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:25:41 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/27 11:22:47 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//-----------------------------------moves----------------------------------
void	put_player(t_mlx *s, char *str, int x, int y)
{
	void	*texture;

	mlx_delete_image(s->mlx, s->player);
	texture = mlx_load_png(str);
	s->player = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, s->player, x, y);
	mlx_delete_texture(texture);
}

void	next_step(t_mlx *s, int x, int y)
{
	if (s->m[y][x] == 'M')
	{
		free_2d(s->m);
		delete_texx1(s->texturen);
		delete_texx1(s->texturec);
		write(1, "\033[1;31mYou Lose\n\033[0m", 20);
		exit(0);
	}
	if (s->m[y][x] == 'C')
	{
		take_coin(s, x, y);
	}
	else if (s->m[y][x] == 'E' && s->c == 0)
	{
		free_2d(s->m);
		delete_texx1(s->texturen);
		delete_texx1(s->texturec);
		write(1, "\033[1;32mYou Win\n\033[0m", 19);
		exit(EXIT_SUCCESS);
	}
}

void	horizontal(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if ((s->m[y][x - 1] == 'E' && s->c == 0) || (s->m[y][x - 1] != '1'
			&& s->m[y][x - 1] != 'E'))
		{
			get_count(s);
			s->player->instances->x -= 75;
			put_player(s, "imgs/crct0_left.png", (x - 1) * 75, y * 75);
			next_step(s, x - 1, y);
		}
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if ((s->m[y][x + 1] == 'E' && s->c == 0) || (s->m[y][x + 1] != '1'
			&& s->m[y][x + 1] != 'E'))
		{
			get_count(s);
			s->player->instances->x += 75;
			put_player(s, "imgs/crct0_right.png", (x + 1) * 75, y * 75);
			next_step(s, x + 1, y);
		}
	}
}

void	vertical(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if ((s->m[y - 1][x] == 'E' && s->c == 0) || (s->m[y - 1][x] != '1'
			&& s->m[y - 1][x] != 'E'))
		{
			get_count(s);
			s->player->instances->y -= 75;
			put_player(s, "imgs/crct0_left.png", x * 75, (y - 1) * 75);
			next_step(s, x, y - 1);
		}
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if ((s->m[y + 1][x] == 'E' && s->c == 0) || (s->m[y + 1][x] != '1'
			&& s->m[y + 1][x] != 'E'))
		{
			get_count(s);
			s->player->instances->y += 75;
			put_player(s, "imgs/crct0_right.png", x * 75, (y + 1) * 75);
			next_step(s, x, y + 1);
		}
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*s;
	int		x;
	int		y;

	s = (t_mlx *)param;
	x = s->player->instances->x / 75;
	y = s->player->instances->y / 75;
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		horizontal(keydata, s, x, y);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		vertical(keydata, s, x, y);
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		delete_texx1(s->texturen);
		delete_texx1(s->texturec);
		free_2d(s->m);
		exit(1);
	}
}
