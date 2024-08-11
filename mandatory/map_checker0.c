/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:10:47 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/23 14:53:47 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//---------------------------------check map-----------------------------------

void	check_c(t_mlx *s)
{
	int	i;
	int	len;

	i = 0;
	while (s->m[i])
	{
		len = 0;
		while (s->m[i][len])
		{
			if (s->m[i][len] == 'C')
				s->c++;
			len++;
		}
		i++;
	}
	if (s->c < 1)
	{
		fx(s->m, s->t);
		error("\033[1;31mVerify ur Coins!!!\n\033[0m");
	}
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E' )
		map[y][x] = '1';
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x - 1);
	flood_fill(map, y, x + 1);
}

void	check_flood(char **map, t_mlx *s)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
			{
				fx(s->m, s->t);
				free_2d(map);
				error("\033[1;31mU Can't Win This Map!!!\n\033[0m");
			}
			i++;
		}
		j++;
	}
	fx(map, s->t);
	return ;
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
	mapcp = ft_split(s->t);
	flood_fill(mapcp, s->y, s->x);
	check_flood(mapcp, s);
}

void	check_map(t_mlx *s, int fd)
{
	char	*tmp;

	s->t = NULL;
	s->c = 0;
	s->e = 0;
	s->p = 0;
	s->m = NULL;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		error("\033[1;31mEmpty file!!!\n\033[0m");
	while (tmp)
	{
		if (!ft_strncmp(tmp, "\n", 1))
		{
			free(tmp);
			error("\033[1;31mRemove That New Line!!!!\n\033[0m");
		}
		s->t = ft_strjoin2(s->t, tmp);
		tmp = get_next_line(fd);
	}
	s->m = ft_split(s->t);
	check_all(s);
}
