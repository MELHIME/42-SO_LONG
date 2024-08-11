/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_flip_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:50:41 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/26 17:49:25 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_texture2(t_mlx *s)
{
	s->texturec[0] = mlx_load_png("imgs/coin/coin10.png");
	s->texturec[1] = mlx_load_png("imgs/coin/coin20.png");
	s->texturec[2] = mlx_load_png("imgs/coin/coin30.png");
	s->texturec[3] = mlx_load_png("imgs/coin/coin40.png");
	s->texturec[4] = mlx_load_png("imgs/coin/coin50.png");
	s->texturec[5] = mlx_load_png("imgs/coin/coin60.png");
	s->texturec[6] = NULL;
	s->imgc[0] = mlx_texture_to_image(s->mlx, s->texturec[0]);
	s->imgc[1] = mlx_texture_to_image(s->mlx, s->texturec[1]);
	s->imgc[2] = mlx_texture_to_image(s->mlx, s->texturec[2]);
	s->imgc[3] = mlx_texture_to_image(s->mlx, s->texturec[3]);
	s->imgc[4] = mlx_texture_to_image(s->mlx, s->texturec[4]);
	s->imgc[5] = mlx_texture_to_image(s->mlx, s->texturec[5]);
}

void	put_cn(t_mlx *s, int j)
{
	void	*img;

	img = NULL;
	if (j <= 5)
	{
		mlx_image_to_window(s->mlx, s->imgc[j], s->c_x * 75, s->c_y * 75);
	}
	if (j > 1)
	{
		mlx_delete_image(s->mlx, s->imgc[j - 2]);
		s->imgc[j - 2] = mlx_texture_to_image(s->mlx, s->texturec[j - 2]);
	}
	else if (j == 1)
	{
		mlx_delete_image(s->mlx, s->imgc[5]);
		s->imgc[5] = mlx_texture_to_image(s->mlx, s->texturec[5]);
	}
	else if (j == 0)
	{
		mlx_delete_image(s->mlx, s->imgc[4]);
		s->imgc[4] = mlx_texture_to_image(s->mlx, s->texturec[4]);
	}
}

void	get_cn(t_mlx *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->m[y])
	{
		x = 0;
		while (s->m[y][x])
		{
			if (s->m[y][x] == 'C')
			{
				s->c_x = x;
				s->c_y = y;
				put_cn(s, s->picc);
			}
			x++;
		}
		y++;
	}
}

void	coin_flip(void *param)
{
	t_mlx		*s;

	s = (t_mlx *)param;
	if (s->delayc > 3) 
		s->delayc = 0;
	if (s->delayc == 0)
	{
		if (s->picc > 5)
			s->picc = 0;
		get_cn(s);
		s->picc++;
	}
	s->delayc++;
}
