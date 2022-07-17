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
	void		*player_left;
	void		*player_back;
	void		*player_right;
	void		*ground;
	void		*obstacle;
	void		*collectable;
	void		*exit;

	int			player_x;
	int			player_y;
	char		*direction_path;
	int			count_collectable;
	int			count_moves_player;


	char		*map_destination;
	int			collectible_size;
	int			player_spawn_point_count;
	int			exit_count;
	char		current_direction;
}	t_data_all;

t_data_all	*ft_parsing_map(char *file_map, char *staticstr);
char		**ft_read_map(int fd, char *staticstr);
void		ft_verif_map(t_data_all *map);
void		ft_verif_rectangular_map(int x, t_data_all *map);
void		ft_verif_walls_map(int x, int y, t_data_all *map);
void		ft_verif_elements_map(int x, int y, char **map, int *tab);
void		ft_load_data(t_data_all *data);
void		ft_load_exit(t_data_all *data);
void		ft_load_player(t_data_all *data);
void		ft_load_collectables(t_data_all *data);
void		ft_load_obstacles(t_data_all *data);
void		ft_display_assets(t_data_all *data);
void		ft_place_asset(t_data_all *data, int x, int y);
int			ft_key_hook(int key, t_data_all *data);
void		ft_move_right(t_data_all *data);
void		ft_move_left(t_data_all *data);
void		ft_move_down(t_data_all *data);
void		ft_move_up(t_data_all *data);
int			ft_count_letter(char **map, char letter);
void		ft_find_player(t_data_all *data);
void		ft_error(int err, char *msg);
void		ft_free_all(t_data_all	*data);
int			ft_close_button();

#endif
