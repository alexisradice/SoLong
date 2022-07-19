/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:59:39 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 00:30:58 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(int fd, char *staticstr)
{
	int		readval;
	char	*buffer;
	char	**map;

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
	int			fd;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Can't open the file");
		return (NULL);
	}
	map = malloc(sizeof(t_data_all));
	if (!map)
		return (NULL);
	map->map = ft_read_map(fd, staticstr);
	close(fd);
	return (map);
}
