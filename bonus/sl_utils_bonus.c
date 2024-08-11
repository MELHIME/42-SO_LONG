/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:02:04 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/25 21:26:16 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//-----------------------------------utils----------------------
void	prnt_move(int n)
{
	if (n >= 10)
		prnt_move(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	free_2d(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			free(s[i++]);
		free(s);
	}
}

void	error(char *str)
{
	int	i;

	i = 0;
	write(2, "\033[1;31mError\n\033[0m", 17); 
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	if (!s1)
		return (s2);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (ptr == NULL)
		return (free(s1), NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free(s2); 
	free(s1);
	return (ptr);
}
