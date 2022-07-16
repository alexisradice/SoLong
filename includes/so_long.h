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


	char		*map_destination;

	int			player_x;
	int			player_y;


	int			collectible_count;
	int			collectible_size;

	int			player_spawn_point_count;
	int			exit_count;

	int			player_move_count;

	char		current_direction;
	char		*direction_path;


}	t_data_all;

#endif
