/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:59:39 by aradice           #+#    #+#             */
/*   Updated: 2022/07/21 06:32:16 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_read_map(int fd, char *mapstr, t_data_all *data)
{
	int		readval;
	char	*buffer;
	char	**map;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	readval = 1;
	while (readval != 0)
	{
		readval = read(fd, buffer, 1);
		if (readval == -1)
			ft_read_error(data, mapstr, buffer);
		buffer[readval] = '\0';
		mapstr = ft_strjoin_modif(mapstr, buffer);
	}
	map = ft_split(mapstr, '\n');
	data->mapstr = ft_strdup(mapstr);
	free(buffer);
	free(mapstr);
	return (map);
}

t_data_all	*ft_parsing_map(char *file_map)
{
	t_data_all	*data;
	int			fd;
	char		*mapstr;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCan't open the file");
		exit(1);
	}
	mapstr = ft_strdup("");
	data = malloc(sizeof(t_data_all));
	if (!data)
	{
		free(mapstr);
		free(data);
		ft_printf("Error\nMalloc Error");
		exit(1);
	}
	data->map = ft_read_map(fd, mapstr, data);
	if (!data->map)
		ft_malloc_error(data);
	close(fd);
	return (data);
}

void	ft_read_error(t_data_all *data, char *mapstr, char *buffer)
{
	free(buffer);
	free(mapstr);
	free(data);
	ft_printf("Error\nCan't read the file");
	exit(1);
}

void	ft_malloc_error(t_data_all *data)
{
	free(data->mapstr);
	free(data->map);
	free(data);
	ft_printf("Error\nMalloc Error");
	exit(1);
}
