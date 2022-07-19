/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:09:30 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 01:44:47 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# include <stdlib.h>

typedef struct s_data_all
{
	char		**map;
	int			size_line;
	int			count_line;

	void		*mlx_ptr;
	void		*window_ptr;
	int			window_width;
	int			window_height;

	int			size_asset;

	void		*player_top;
	void		*player_back;
	void		*player_left;
	void		*player_right;
	void		*ground;
	void		*obstacle;
	void		*collectable;
	void		*exit_close;
	void		*exit_open;

	int			player_x;
	int			player_y;
	char		player_position;
	int			count_collectable;
	int			count_moves_player;
	int			exit_ok;
	int			nb_collectible;

	int			player_spawn_point_count;
	int			exit_count;
}	t_data_all;

t_data_all	*ft_parsing_map(char *file_map, char *staticstr);
char		**ft_read_map(int fd, char *staticstr);
void		ft_verif_map(t_data_all *map);
void		ft_verif_rectangular_map(int x, t_data_all *map);
void		ft_verif_walls_map(int x, int y, t_data_all *map);
void		ft_verif_elements_map(int x, int y, t_data_all *data, int *tab);
void		ft_verif_filename(char *filename);
void		ft_load_data(t_data_all *data);
void		ft_load_exit(t_data_all *data);
void		ft_load_player(t_data_all *data);
void		ft_load_collectables(t_data_all *data);
void		ft_load_obstacles(t_data_all *data);
void		ft_load_ground(t_data_all *data);
void		ft_display_assets(t_data_all *data);
void		ft_place_assets(t_data_all *data, int x, int y);
void		ft_place_assets_player(t_data_all *data, int x, int y);
int			ft_key_hook(int key, t_data_all *data);
void		ft_move_right(t_data_all *data);
void		ft_move_left(t_data_all *data);
void		ft_move_down(t_data_all *data);
void		ft_move_up(t_data_all *data);
int			ft_count_letter(char **map, char letter);
void		ft_find_player(t_data_all *data);
void		ft_free_all(t_data_all	*data);
void		ft_init_data(t_data_all *data);
void		ft_free_all(t_data_all *data);
void		ft_free_assets(t_data_all *data);
void		ft_free_map(t_data_all	*data);
int			ft_close_game(t_data_all *data, int err, char *msg);

#endif
