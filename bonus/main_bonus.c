/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:27 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/27 20:04:50 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fx(char	**map, char	*str)
{
	free(str);
	free_2d(map);
}

void	check_all(t_mlx *s)
{
	char	**mapcp;

	check_d(s);
	check_elements(s);
	check_1(s);
	check_p(s);
	check_e(s);
	check_c(s);
	check_n(s);
	mapcp = ft_split(s->t);
	flood_fill(mapcp, s->y, s->x);
	check_flood(mapcp, s);
}

void	remove_exit(t_mlx *s, mlx_t *mlx)
{
	void	*texture;
	void	*img;
	int		i;
	int		len;

	i = 0;
	while (s->m[i])
	{
		len = 0;
		while (s->m[i][len])
		{
			if (s->m[i][len] == 'E')
			{
				texture = mlx_load_png("imgs/ground0.png");
				img = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, img, len * 75, i * 75);
				mlx_delete_texture(texture);
				return ;
			}
			len++;
		}
		i++;
	}
}

void	lunch(t_mlx *s)
{
	void	*texture;

	s->mlx = mlx_init(s->width, s->height, "so_long", 1);
	put_ground(s, s->mlx);
	put_walls(s, 0, 0);
	put_exit(s, s->mlx);
	get_texture1(s);
	get_texture2(s);
	mlx_loop_hook(s->mlx, enm_bite, s);
	mlx_loop_hook(s->mlx, coin_flip, s);
	texture = mlx_load_png("./imgs/crct0_right.png");
	s->player = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, s->player, (s->x * 75), (s->y * 75));
	mlx_delete_texture(texture);
}

int	main(int argc, char **v)
{
	int				fd;
	static t_mlx	s;

	if (argc == 2)
	{
		fd = open(v[1], O_RDWR);
		if (fd < 0 || check_tex())
			error("\033[1;31mInvalid File!!!\n\033[0m");
		check_ber(v[1]);
		check_map(&s, fd);
		if (s.height > 1280 || s.width > 2560)
		{
			free_2d(s.m);
			error("\033[1;31mMap Is Too Large!!!\n\033[0m");
		}
		lunch(&s);
		get_count(&s);
		mlx_key_hook(s.mlx, my_keyhook, &s);
		mlx_loop(s.mlx);
		free_2d(s.m);
		mlx_terminate(s.mlx);
	}
	else
		error("\033[1;31mCheck ur Args!!\n\033[0m");
	return (0);
}
