/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_t_ex_tention_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:15:25 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/27 16:01:52 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//------------------------------check texture----------------------------
void	delete_tex(void **texture)
{
	int	i;

	i = 0;
	while (i < 19)
	{
		if (texture[i] == NULL)
			i++;
		else
		{
			mlx_delete_texture(texture[i]);
			i++;
		}
	}
	free(texture);
	texture = NULL;
}

void	**get_tex(void **texture)
{
	texture = malloc(20 * sizeof(void *));
	texture[0] = mlx_load_png("imgs/ground0.png");
	texture[1] = mlx_load_png("imgs/block0.png");
	texture[2] = mlx_load_png("imgs/exit0.png");
	texture[3] = mlx_load_png("imgs/exit1.png");
	texture[4] = mlx_load_png("imgs/crct0_left.png");
	texture[5] = mlx_load_png("imgs/crct0_right.png");
	texture[6] = mlx_load_png("imgs/ground00.png");
	texture[7] = mlx_load_png("imgs/enm/enm0.png");
	texture[8] = mlx_load_png("imgs/enm/enm1.png");
	texture[9] = mlx_load_png("imgs/enm/enm2.png");
	texture[10] = mlx_load_png("imgs/enm/enm3.png");
	texture[11] = mlx_load_png("imgs/enm/enm4.png");
	texture[12] = mlx_load_png("imgs/enm/enm5.png");
	texture[13] = mlx_load_png("imgs/coin/coin10.png");
	texture[14] = mlx_load_png("imgs/coin/coin20.png");
	texture[15] = mlx_load_png("imgs/coin/coin30.png");
	texture[16] = mlx_load_png("imgs/coin/coin40.png");
	texture[17] = mlx_load_png("imgs/coin/coin50.png");
	texture[18] = mlx_load_png("imgs/coin/coin60.png");
	texture[19] = NULL;
	return (texture);
}

int	check_tex(void)
{
	void	**texture;
	int		i;

	i = 0;
	texture = NULL;
	texture = get_tex(texture);
	while (i < 19)
	{
		if (texture[i] == NULL)
		{
			delete_tex(texture);
			error("\033[1;31mLoad Error!!!\n\033[0m");
		}
		i++;
	}
	delete_tex(texture);
	return (0);
}

//--------------------------------check extention----------------------
void	check_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		error("\033[1;31mInvalid Extention!!!\n\033[0m");
	if (str[len - 1] != 'r' || str[len - 2] != 'e'
		|| str[len - 3] != 'b' || str[len - 4] != '.')
		error("\033[1;31mInvalid Extention!!!\n\033[0m");
}
