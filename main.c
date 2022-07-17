#include "so_long.h"

void    ft_error(int err, char *msg)
{
    ft_printf("%s\n", msg);
    exit(err);
}

int	ft_close_button()
{
	exit(0);
}

void	ft_find_player(t_data_all *data)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
        	y++;
		}
		x++;
	}
}

int	ft_count_letter(char **map, char letter)
{
	int	x;
	int y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == letter)
				count++;
        	y++;
		}
		x++;
	}
	return (count);
}

void	ft_move_up(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x - 1][data->player_y] == 'E' && ft_count_letter(data->map, 'C') == 0)
		ft_error(1, "Finish");
	if (data->map[data->player_x - 1][data->player_y] == '0' || data->map[data->player_x - 1][data->player_y] == 'C')
	{
		if (data->map[data->player_x - 1][data->player_y] == 'C')
			data->count_collectable++;
		data->map[data->player_x - 1][data->player_y] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		ft_display_assets(data);
	}
}

void	ft_move_down(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x + 1][data->player_y] == 'E' && ft_count_letter(data->map, 'C') == 0)
		ft_error(1, "Finish");
	if (data->map[data->player_x + 1][data->player_y] == '0' || data->map[data->player_x + 1][data->player_y] == 'C')
	{
		if (data->map[data->player_x + 1][data->player_y] == 'C')
			data->count_collectable++;
		data->map[data->player_x + 1][data->player_y] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		ft_display_assets(data);
	}
}

void	ft_move_left(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x][data->player_y - 1] == 'E' && ft_count_letter(data->map, 'C') == 0)
		ft_error(1, "Finish");
	if (data->map[data->player_x][data->player_y - 1] == '0' || data->map[data->player_x][data->player_y - 1] == 'C')
	{
		if (data->map[data->player_x][data->player_y - 1] == 'C')
			data->count_collectable++;
		data->map[data->player_x][data->player_y - 1] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		ft_display_assets(data);
	}
}

void	ft_move_right(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x][data->player_y + 1] == 'E' && ft_count_letter(data->map, 'C') == 0)
		ft_error(1, "Finish");
	if (data->map[data->player_x][data->player_y + 1] == '0' || data->map[data->player_x][data->player_y + 1] == 'C')
	{
		if (data->map[data->player_x][data->player_y + 1] == 'C')
			data->count_collectable++;
		data->map[data->player_x][data->player_y + 1] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		ft_display_assets(data);
	}
}

int	ft_key_hook(int key, t_data_all *data)
{
	if (key == 119)
		ft_move_up(data);
	else if (key == 115)
		ft_move_down(data);
	else if (key == 97)
		ft_move_left(data);
	else if (key == 100)
		 ft_move_right(data);
	else if (key == 65307)
		ft_error(1,"Stop Echap");
	//ft_printf("Key: %d x: %d y: %d map: %s\n", key, data->player_x, data->player_y, data->map[0]);
	return (0);
}

void	ft_place_asset(t_data_all *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->ground, y * 40, x * 40);
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->obstacle, y * 40, x * 40);
	else if (data->map[x][y] == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->player_top, y * 40, x * 40);
	else if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->collectable, y * 40, x * 40);
	else if (data->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->exit, y * 40, x * 40);
}

void	ft_display_assets(t_data_all *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			ft_place_asset(data, x, y);
			y++;
		}
		x++;
	}
}

void	ft_load_obstacles(t_data_all *data)
{
	int	img_w;
	int	img_h;

	data->obstacle = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/obstacle.xpm", &img_w, &img_h);
}

void	ft_load_collectables(t_data_all *data)
{
	int	img_w;
	int	img_h;

	data->collectable = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/carrot.xpm", &img_w, &img_h);
	data->collectable = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/flowey.xpm", &img_w, &img_h);
}

void	ft_load_player(t_data_all *data)
{
	int	img_w;
	int	img_h;

	data->player_top = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/top.xpm", &img_w, &img_h);
}

void	ft_load_exit(t_data_all *data)
{
	int	img_w;
	int	img_h;

	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/plate.xpm", &img_w, &img_h);
}

void	ft_load_data(t_data_all *data)
{
	int	width;
	int	height;

	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/ground.xpm", &width, &height);
	ft_load_player(data);
	ft_load_collectables(data);
	ft_load_exit(data);
	ft_load_obstacles(data);
}

void	ft_verif_elements_map(int x, int y, char **map, int *tab)
{
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!ft_strchr("01CEP", map[x][y]))
				ft_error(1, "Error: Undesirable Element");
			if (map[x][y] == 'C')
				tab[0] = 1;
			else if (map[x][y] == 'E')
				tab[1] = 1;
			else if (map[x][y] == 'P')
				tab[2] = 1;
        	y++;
		}
		x++;
	}
	if (tab[0] == 0 || tab[1] == 0 || tab[2] == 0)
		ft_error(1, "Error: Not Enough Mandatory Elements");
}

void	ft_verif_walls_map(int x, int y, t_data_all *map)
{
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (x == 0 || x == map->count_line - 1)
			{
				if (map->map[x][y] != '1')
					ft_error(1, "Error: The Map Must Be Surrounded By Walls");
			}
			else
			{
				if (map->map[x][0] != '1' || map->map[x][map->size_line - 1] != '1')
					ft_error(1, "Error: The Map Must Be Surrounded By Walls");
			}
			y++;
		}
		x++;
	}
}

void	ft_verif_rectangular_map(int x, t_data_all *map)
{
    size_t  len_line;
	size_t  len_first_line;

	len_first_line = ft_strlen(map->map[0]);
	while(map->map[x])
	{
		len_line = ft_strlen(map->map[x]);
		if (len_line != len_first_line)
			ft_error(1, "Error: Map Is Not Rectangular");
		x++;
	}
	map->count_line = x;
	map->size_line = len_first_line;
}

void	ft_verif_map(t_data_all *map)
{
	int		x;
	int 	y;
	int		tab[3];

	x = 0;
	y = 0;
	ft_memset(&tab, 0, sizeof(int) * 3);
	ft_verif_elements_map(x, y, map->map, tab);
	ft_verif_rectangular_map(x, map);
	ft_verif_walls_map(x, y, map);
}

char	**ft_read_map(int fd, char *staticstr)
{
	int		readval;
	char	*buffer;
	char 	**map;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		return (NULL);
	readval = 1;
	while (readval != 0)
	{
		readval = read(fd, buffer, 1);
		if (readval == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readval] = '\0';
		staticstr = ft_strjoin_gnl(staticstr, buffer);
	}
	map = ft_split(staticstr, '\n');
	free(buffer);
	free(staticstr);
	return (map);
}

t_data_all	*ft_parsing_map(char *file_map, char *staticstr)
{
	t_data_all	*map;
	int		fd;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Can't Open The File");
		return (NULL);
	}
	map = malloc(sizeof(t_data_all));
	if (!map)
		return (NULL);
	map->map = ft_read_map(fd, staticstr);
	close(fd);
	return (map);
}

void ft_free_all(t_data_all	*data)
{
	int length;

	length = -1;
	while (data->map[++length] != NULL)
		free(data->map[length]);
	free(data->map);
	free(data);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error(1, "You need to enter 2 parameters");
	static char	*staticstr;
	t_data_all	*data;
	data = ft_parsing_map(argv[1], staticstr);
	ft_verif_map(data);
	data->mlx_ptr = mlx_init();
	data->window_ptr = mlx_new_window(data->mlx_ptr, (data->size_line * 50 - 49),
			(data->count_line * 50), "so_long");
	ft_load_data(data);
	ft_display_assets(data);
	mlx_key_hook(data->window_ptr, ft_key_hook, data);
	mlx_hook(data->window_ptr, 17, (1L << 17), ft_close_button, 0);
	mlx_loop(data->mlx_ptr);
	ft_free_all(data);
	return(0);
}