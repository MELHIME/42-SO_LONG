/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:54:11 by mel-hime          #+#    #+#             */
/*   Updated: 2024/04/06 00:44:17 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9

# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_isthereanl(char	*str);
int		ft_strlen(char *str);

char	*ft_strdup(char	*s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif