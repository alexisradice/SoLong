#include "so_long.h"

//int ft_verif_map()
//{
//	while()
//	{
//
//	}
//	return (1);
//}

char	**ft_read_map(int fd, char *staticstr)
{
	int		readval;
	char	*buffer;
	char 	**map;

	buffer = malloc(sizeof(char) * 1);
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
		map = ft_split(staticstr, '\n');
	}
	free(buffer);
	return (map);
}

t_map	*ft_parsing_map(char *file_map, char *staticstr)
{
	t_map	*map;
	char		**tab;
	int		fd;
	int		size_line;
	int		count_line;

	count_line = 0;
	size_line = 0;
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("error can't open the file");
		return (NULL);
	}
	tab = ft_read_map(fd, staticstr);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = tab;
	map->count_line = count_line;
	map->size_line = size_line;
	close(fd);
	return (map);
}

void ft_get_map(char *file_map)
{
	static char	*staticstr;
	t_map	*map;

	map = ft_parsing_map(file_map, staticstr);
	ft_printf("%s", map->map[1]);

	//line = ft_get_line(staticstr);
	//staticstr = ft_new_staticstr(staticstr);
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