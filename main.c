#include "so_long.h"

char	*ft_read_map(int fd, char *staticstr)
{
	int		readval;
	char	*buffer;

	buffer = malloc(sizeof(char) * 1);
	if (!buffer)
		return (NULL);
	readval = 1;
	while (readval != 0)
	{
		readval = read(fd, buffer, BUFFER_SIZE);
		if (readval == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readval] = '\0';
		staticstr = ft_strjoin_gnl(staticstr, buffer);
	}
	free(buffer);
	return (staticstr);
}

char	*ft_get_map(int fd)
{
	char		*line;
	static char	*staticstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	staticstr = ft_read(fd, staticstr);
	if (!staticstr)
		return (NULL);
	line = ft_get_line(staticstr);
	staticstr = ft_new_staticstr(staticstr);
	return (line);
}

t_map	*ft_parsing_map(char *file_map)
{
	t_map	*map;
	int		**tab;
	int		fd;
	int		size_line;
	int		count_line;

	count_line = 0;
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		perror("error can't open");
		return (NULL);
	}
	tab = read_file(fd);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = tab;
	map->count_line = count_line;
	map->size_line = size_line;
	close(fd);
	return (map);
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