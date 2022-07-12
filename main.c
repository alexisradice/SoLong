#include "so_long.h"

void    ft_map_error(int err, char *msg)
{
    ft_printf("%s\n", msg);
    exit(err);
}

void	ft_verif_elements_map(int x, int y, char **map, int *tab)
{
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!ft_strchr("01CEP", map[x][y]))
				ft_map_error(1, "Error: Undesirable Element");
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
		ft_map_error(1, "Error: Not Enough Mandatory Elements");
}

void	ft_verif_walls_map(int x, int y, t_map *map)
{
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (x == 0 || x == map->count_line - 1)
			{
				if (map->map[x][y] != '1')
					ft_map_error(1, "Error: The Map Must Be Surrounded By Walls");
			}
			else
			{
				if (map->map[x][0] != '1' || map->map[x][map->size_line - 1] != '1')
					ft_map_error(1, "Error: The Map Must Be Surrounded By Walls");
			}
			y++;
		}
		x++;
	}
}

void	ft_verif_rectangular_map(int x, t_map *map)
{
    size_t  len_line;
	size_t  len_first_line;

	len_first_line = ft_strlen(map->map[0]);
	while(map->map[x])
	{
		len_line = ft_strlen(map->map[x]);
		if (len_line != len_first_line)
			ft_map_error(1, "Error: Map Is Not Rectangular");
		x++;
	}
	map->count_line = x;
	map->size_line = len_first_line;
}

void	ft_verif_map(t_map *map)
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

t_map	*ft_parsing_map(char *file_map, char *staticstr)
{
	t_map	*map;
	int		fd;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Can't Open The File");
		return (NULL);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->count_line = 0;
	map->size_line = 0;
	map->map = ft_read_map(fd, staticstr);
	close(fd);
	return (map);
}

void ft_get_map(char *file_map)
{
	static char	*staticstr;
	t_map	*map;
	int length;

	length = -1;
	map = ft_parsing_map(file_map, staticstr);
	ft_verif_map(map);
	while (map->map[++length] != NULL)
		free(map->map[length]);
	free(map->map);
	free(map);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("You need to enter 2 parameters");
		return (0);
	}
	else
	{
		ft_get_map(argv[1]);
	}
	return(0);
}