/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:25:41 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/21 12:42:31 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	take_coin(t_mlx *s, char *str, int x, int y)
{
	void	*texture;
	void	*img;

	(void) str;
	if (s->m[y][x] == 'C')
	{
		s->c -= 1;
		s->m[y][x] = '0';
		texture = mlx_load_png("imgs/ground0.png");
		img = mlx_texture_to_image(s->mlx, texture);
		mlx_image_to_window(s->mlx, img, x * 75, y * 75);
		mlx_delete_texture(texture);
		if (s->c == 0)
		{
			remove_exit(s, s->mlx);
			put_exit(s, s->mlx);
		}
		mlx_image_to_window(s->mlx, s->player, x * 75, y * 75);
	}
	else if (s->m[y][x] == 'E' && s->c == 0)
	{
		free_2d(s->m);
		exit(EXIT_SUCCESS);
	}
}

void	horizontal(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_A && keydata.action && s->m[y][x - 1] != '1')
	{
		if (s->m[y][x - 1] == '0' || s->m[y][x - 1] == 'C' || 
			s->m[y][x - 1] == 'P' || (s->m[y][x - 1] == 'E' && s->c == 0))
		{
			prnt_move(++s->moves);
			write(1, "\n", 1);
			s->player->instances->x -= 75;
			put_player(s, "imgs/crct0_left.png", (x - 1) * 75, y * 75);
			take_coin(s, "img/crct0_left.png", x - 1, y);
		}
	}
	else if (keydata.key == MLX_KEY_D && keydata.action
		&& s->m[y][x + 1] != '1')
	{
		if (s->m[y][x + 1] == '0' || s->m[y][x + 1] == 'C' || 
			s->m[y][x + 1] == 'P' || (s->m[y][x + 1] == 'E' && s->c == 0))
		{
			prnt_move(++s->moves);
			write(1, "\n", 1);
			s->player->instances->x += 75;
			put_player(s, "imgs/crct0_right.png", (x + 1) * 75, y * 75);
			take_coin(s, "img/crct0_right.png", x + 1, y);
		}
	}
}

void	vertical(mlx_key_data_t keydata, t_mlx *s, int x, int y)
{
	if (keydata.key == MLX_KEY_W && keydata.action && s->m[y - 1][x] != '1')
	{
		if (s->m[y - 1][x] == '0' || s->m[y - 1][x] == 'C' || 
			s->m[y - 1][x] == 'P' || (s->m[y - 1][x] == 'E' && s->c == 0))
		{
			prnt_move(++s->moves);
			write(1, "\n", 1);
			s->player->instances->y -= 75;
			put_player(s, "imgs/crct0_left.png", x * 75, (y - 1) * 75);
			take_coin(s, "img/crct0_left.png", x, y - 1);
		}
	}
	else if (keydata.key == MLX_KEY_S && keydata.action
		&& s->m[y + 1][x] != '1')
	{
		if (s->m[y + 1][x] == '0' || s->m[y + 1][x] == 'C' || 
			s->m[y + 1][x] == 'P' || (s->m[y + 1][x] == 'E' && s->c == 0))
		{
			prnt_move(++s->moves);
			write(1, "\n", 1);
			s->player->instances->y += 75;
			put_player(s, "imgs/crct0_right.png", x * 75, (y + 1) * 75);
			take_coin(s, "img/crct0_right.png", x, y + 1);
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
		free_2d(s->m);
		exit(1);
	}
}
