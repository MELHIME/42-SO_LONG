/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:56:48 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/26 12:11:27 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	take_coin(t_mlx *s, int x, int y)
{
	void	*texture;
	void	*img;

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
	return ;
}

void	get_count(t_mlx *s)
{
	void	*texture;
	void	*img;

	texture = mlx_load_png("imgs/ground00.png");
	if (!texture)
		error("Error: Failed to load texture\n");
	img = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, img, 0, 0);
	mlx_image_to_window(s->mlx, img, 70, 0);
	mlx_delete_texture(texture);
	s->movenb = ft_itoa(s->moves++);
	mlx_put_string(s->mlx, "M o v e :", 10, 5);
	mlx_put_string(s->mlx, s->movenb, 105, 5);
	free(s->movenb);
}

static int	count_len(long nb)
{
	int	len;

	len = 1;
	if (nb > 0)
		len = 0;
	if (nb == 0)
		return (len);
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	ft_neg(long *nbr)
{
	int	neg;

	neg = 1;
	if (*nbr < 0)
	{
		neg = -1;
		*nbr = *nbr * -1;
	}
	return (neg);
}

char	*ft_itoa(int nbr)
{
	int		len;
	long	nb;
	int		sign;
	char	*str;

	nb = nbr;
	len = count_len(nb);
	sign = ft_neg(&nb);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	str[count_len(nbr)] = '\0';
	return (str);
}
