/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enm_bite_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 08:43:41 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/26 17:09:03 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_texture1(t_mlx *s)
{
	s->texturen[0] = mlx_load_png("imgs/enm/enm0.png");
	s->texturen[1] = mlx_load_png("imgs/enm/enm1.png");
	s->texturen[2] = mlx_load_png("imgs/enm/enm2.png");
	s->texturen[3] = mlx_load_png("imgs/enm/enm3.png");
	s->texturen[4] = mlx_load_png("imgs/enm/enm4.png");
	s->texturen[5] = mlx_load_png("imgs/enm/enm5.png");
	s->texturen[6] = NULL;
	s->imgn[0] = mlx_texture_to_image(s->mlx, s->texturen[0]);
	s->imgn[1] = mlx_texture_to_image(s->mlx, s->texturen[1]);
	s->imgn[2] = mlx_texture_to_image(s->mlx, s->texturen[2]);
	s->imgn[3] = mlx_texture_to_image(s->mlx, s->texturen[3]);
	s->imgn[4] = mlx_texture_to_image(s->mlx, s->texturen[4]);
	s->imgn[5] = mlx_texture_to_image(s->mlx, s->texturen[5]);
}

void	delete_texx1(void **texture)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		mlx_delete_texture(texture[i]);
		i++;
	}
	texture = NULL;
}

void	put_enm(t_mlx *s, int j)
{
	void	*img;

	img = NULL;
	if (j <= 5)
	{
		mlx_image_to_window(s->mlx, s->imgn[j], s->n_x * 75, s->n_y * 75);
	}
	if (j > 1)
	{
		mlx_delete_image(s->mlx, s->imgn[j - 2]);
		s->imgn[j - 2] = mlx_texture_to_image(s->mlx, s->texturen[j - 2]);
	}
	else if (j == 1)
	{
		mlx_delete_image(s->mlx, s->imgn[5]);
		s->imgn[5] = mlx_texture_to_image(s->mlx, s->texturen[5]);
	}
	else if (j == 0)
	{
		mlx_delete_image(s->mlx, s->imgn[4]);
		s->imgn[4] = mlx_texture_to_image(s->mlx, s->texturen[4]);
	}
}

void	get_enm(t_mlx *s)
{
	int	x;
	int	y;

	y = 0;
	while (s->m[y])
	{
		x = 0;
		while (s->m[y][x])
		{
			if (s->m[y][x] == 'M')
			{
				s->n_x = x;
				s->n_y = y;
				put_enm(s, s->picn);
			}
			x++;
		}
		y++;
	}
}

void	enm_bite(void *param)
{
	t_mlx		*s;

	s = (t_mlx *)param;
	if (s->delayn > 3) 
		s->delayn = 0;
	if (s->delayn == 0)
	{
		if (s->picn > 5)
			s->picn = 0;
		get_enm(s);
		s->picn++;
	}
	s->delayn++;
}
