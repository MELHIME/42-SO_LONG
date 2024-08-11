/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:05:50 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/25 21:26:31 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//---------------------------------check map-----------------------------------

void	check_d(t_mlx *s)
{
	int	i;
	int	len;
	int	test;

	i = 1;
	test = 0;
	while (s->m[0][test])
		test++;
	while (s->m[i])
	{
		len = 0;
		while (s->m[i][len])
			len++;
		if (len != test)
		{
			free(s->t);
			free_2d(s->m);
			error("\033[1;31mVerify Map's Dementions!!!\n\033[0m");
		}
		i++;
	}
	s->height = i * 75;
	s->width = test * 75;
}

void	check_elements(t_mlx *s)
{
	int	i;
	int	len;

	i = 0;
	while (s->m[i])
	{
		len = 0;
		while (s->m[i][len])
		{
			if (s->m[i][len] != 'P' && s->m[i][len] != 'E'
				&&s->m[i][len] != 'C' && s->m[i][len] != '1'
				&& s->m[i][len] != '0' && s->m[i][len] != 'M')
			{
				free (s->t);
				free_2d(s->m);
				error("\033[1;31mVerify ur Elements!!!\n\033[0m");
			}
			len++;
		}
		i++;
	}
}

void	check_1(t_mlx *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s->m[i][len])
	{
		if (s->m[i][len] != '1')
			return (fx(s->m, s->t), error("\033[1;31mTop Wall!!!\n\033[0m"));
		len++;
	}
	while (s->m[i])
	{
		if (s->m[i][0] != '1' || s->m[i][len - 1] != '1')
			return (fx(s->m, s->t), error("\033[1;31mSide Wall!!!\n\033[0m"));
		i++;
	}
	while (len > 0)
	{
		if (s->m[i - 1][--len] != '1')
			return (fx(s->m, s->t), error("\033[1;31mLower Wall!!!\n\033[0m"));
	}
	return ;
}

void	check_p(t_mlx *s)
{
	int	i;
	int	len;

	i = 0;
	while (s->m[i])
	{
		len = 0;
		while (s->m[i][len])
		{
			if (s->m[i][len] == 'P')
			{
				s->p++;
				s->y = i;
				s->x = len;
			}
			len++;
		}
		i++;
	}
	if (s->p != 1)
	{
		fx(s->m, s->t);
		error("\033[1;31mError!!! Verify ur Player!!!\n\033[0m");
	}
}

void	check_e(t_mlx *s)
{
	int	i;
	int	len;

	i = 0;
	while (s->m[i])
	{
		len = 0;
		while (s->m[i][len])
		{
			if (s->m[i][len] == 'E')
				s->e++;
			len++;
		}
		i++;
	}
	if (s->e != 1) 
	{
		fx(s->m, s->t);
		error("\033[1;31mError!!! Verify ur Exit!!!\n\033[0m");
	}
}
