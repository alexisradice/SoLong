/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:59:39 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 04:25:28 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(int fd, char *mapstr, t_data_all *data)
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
		mapstr = ft_strjoin_gnl(mapstr, buffer);
	}
	map = ft_split(mapstr, '\n');
	data->mapstr = ft_strdup(mapstr);
	free(buffer);
	free(mapstr);
	return (map);
}

t_data_all	*ft_parsing_map(char *file_map, char *mapstr)
{
	t_data_all	*data;
	int			fd;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Can't open the file");
		return (NULL);
	}
	data = malloc(sizeof(t_data_all));
	if (!data)
		return (NULL);
	data->map = ft_read_map(fd, mapstr, data);
	close(fd);
	return (data);
}
