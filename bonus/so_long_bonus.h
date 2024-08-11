/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:45:06 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/27 20:24:48 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct mlx_struct{
	char		**m;
	char		*t;
	mlx_t		*mlx;
	mlx_image_t	*player;
	int			x;
	int			y;
	int			moves;
	int			c;
	int			e;
	int			p;
	int			n;
	int			width;
	int			height;
	int			n_x;
	int			n_y;
	int			c_x;
	int			c_y;
	int			delayn;
	int			delayc;
	char		*movenb;
	int			picn;
	int			picc;
	void		*texturen[7];
	mlx_image_t	*imgn[6];
	void		*texturec[7];
	mlx_image_t	*imgc[6];
}				t_mlx;

char	**ft_split(char const *s);
void	prnt_move(int n);
void	free_2d(char **s);
void	fx(char	**map, char	*str);
void	error(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin2(char *s1, char *s2);
void	check_d(t_mlx *s);
void	check_elements(t_mlx *s);
void	check_1(t_mlx *s);
void	check_p(t_mlx *s);
void	check_e(t_mlx *s);
void	check_c(t_mlx *s);
void	flood_fill(char **map, int y, int x);
void	check_flood(char **map, t_mlx *s);
void	check_all(t_mlx *s);
void	check_map(t_mlx *s, int fd);
void	delete_tex(void **texture);
void	**get_tex(void **texture);
int		check_tex(void);
void	check_ber(char *str);
void	put_ground(t_mlx *s, mlx_t *mlx);
void	put_walls(t_mlx *s, int x, int y);
void	put_exit(t_mlx *s, mlx_t *mlx);
void	remove_exit(t_mlx *s, mlx_t *mlx);
void	put_player(t_mlx *s, char *str, int x, int y);
void	next_step(t_mlx *s, int x, int y);
void	take_coin(t_mlx *s, int x, int y);
void	horizontal(mlx_key_data_t keydata, t_mlx *s, int x, int y);
void	vertical(mlx_key_data_t keydata, t_mlx *s, int x, int y);
void	my_keyhook(mlx_key_data_t keydata, void *param);

void	check_n(t_mlx *s);
void	enm_bite(void *param);
void	get_texture1(t_mlx *s);
void	get_texture2(t_mlx *s);
void	delete_texx1(void **texture);
void	get_count(t_mlx *s);
char	*ft_itoa(int nbr);
void	coin_flip(void *param);

#endif