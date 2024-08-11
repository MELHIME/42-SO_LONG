/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:22:09 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/27 15:51:07 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//-----------------------------------draw map---------------------------------

void	put_ground(t_mlx *s, mlx_t *mlx)
{
	int		x;
	int		y;
	void	*texture;
	void	*image;

	y = 0;
	while (s->m[y])
	{
		x = 0;
		while (s->m[y][x])
		{
			if (s->m[y][x] == '0' || s->m[y][x] == 'C' || 
				s->m[y][x] == 'P' || s->m[y][x] == 'E' || 
				s->m[y][x] == '1' || s->m[y][x] == 'M')
			{
				texture = mlx_load_png("imgs/ground0.png");
				image = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, image, (x * 75), (y * 75));
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
}

void	put_walls(t_mlx *s, int x, int y)
{
	void	*texture;
	void	*img;

	while (s->m[y])
	{
		x = 0;
		while (s->m[y][x])
		{
			if (s->m[y][x] == '1')
			{
				texture = mlx_load_png("imgs/block0.png");
				if (texture != NULL)
				{
					img = mlx_texture_to_image(s->mlx, texture);
					mlx_image_to_window(s->mlx, img, x * 75, y * 75);
					mlx_delete_texture(texture);
				}
			}
			x++;
		}
		y++;
	}
}

void	put_exit(t_mlx *s, mlx_t *mlx)
{
	int		x;
	int		y;
	void	*texture;
	void	*img;

	y = 0;
	while (s->m[y])
	{
		x = 0;
		while (s->m[y][x])
		{
			if (s->m[y][x] == 'E' && s->c != 0)
				texture = mlx_load_png("imgs/exit0.png");
			if (s->m[y][x] == 'E' && s->c == 0)
				texture = mlx_load_png("imgs/exit1.png");
			if (s->m[y][x] == 'E')
			{
				img = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, img, x * 75, y * 75);
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
}
