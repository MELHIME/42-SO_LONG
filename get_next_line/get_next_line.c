/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:53:50 by mel-hime          #+#    #+#             */
/*   Updated: 2024/04/06 00:56:46 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_chyata(char *building)
{
	int		i;
	int		j;
	char	*chyata;

	i = 0;
	j = 0;
	chyata = NULL;
	if (!building)
		return (NULL);
	while (building[i] && building[i] != '\n')
		i++;
	if (building[i] == '\n')
		i++;
	while (building[i + j])
		j++;
	chyata = (char *)malloc(j + 1);
	if (!chyata)
		return (NULL);
	j = 0;
	while (building[i])
		chyata[j++] = building[i++];
	chyata[j] = '\0';
	free (building);
	return (chyata);
}

char	*get_perfect_line(char	*building)
{
	int		i;
	char	*line;

	i = 0;
	if (!building)
		return (NULL);
	while (building[i] && building[i] != '\n')
		i++;
	if (building[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (building[i] && building[i] != '\n')
	{
		line[i] = building[i];
		i++;
	}
	if (building[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_line_extra(char *building, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		char_count;

	char_count = 1;
	buffer[0] = '\0';
	while (char_count != 0 && ft_isthereanl(buffer) == 0)
	{
		char_count = read(fd, buffer, BUFFER_SIZE);
		if (char_count < 0)
		{
			free(building);
			building = NULL;
			return (NULL);
		}
		buffer[char_count] = '\0';
		if (!building)
			building = ft_strdup(buffer);
		else
			building = ft_strjoin(building, buffer);
	}
	return (building);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*building;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	building = get_line_extra(building, fd);
	if (!building)
		return (NULL);
	line = get_perfect_line(building);
	building = get_chyata(building);
	if (ft_strlen(line) == 0)
	{
		free (building);
		building = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>
// int main ()
// {
// 	int fd;
// 	int fd1;
// 	fd = open("test.txt", O_CREAT | O_RDONLY, 0777);
// 	fd1 = open("test2.txt", O_CREAT | O_RDONLY, 0777);
// 	printf ("%d \n", fd);
// 	printf ("%d \n", fd1);
// 	// char	*s = NULL;
// 	printf("%s \n", get_next_line(3));
// 	//printf("%s \n", get_next_line(4));
// 	printf("%s \n", get_next_line(3));
// 	printf("%s \n", get_next_line(3));
// 	//printf("%s \n", get_next_line(4));
// }