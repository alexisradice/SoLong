/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:01:11 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 06:43:19 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verif_elements_map(int x, int y, t_data_all *data, int *tab)
{
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (!ft_strchr("01CEP", data->map[x][y]))
				ft_close_game(data, 1, "Error: Undesirable elements");
			if (data->map[x][y] == 'C')
				tab[0] = 1;
			else if (data->map[x][y] == 'E')
				tab[1] = 1;
			else if (data->map[x][y] == 'P')
				tab[2] = 1;
			y++;
		}
		x++;
	}
	if (tab[0] == 0 || tab[1] == 0 || tab[2] == 0)
		ft_close_game(data, 2, "Error: Not enough mandatory elements");
}

void	ft_verif_walls_map(int x, int y, t_data_all *data)
{
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (x == 0 || x == data->count_line - 1)
			{
				if (data->map[x][y] != '1')
					ft_close_game(data, 2,
						"Error: Map must be surrounded by walls");
			}
			else
			{
				if (data->map[x][0] != '1'
						|| data->map[x][data->size_line - 1] != '1')
					ft_close_game(data, 2,
						"Error: Map must be surrounded by walls");
			}
			y++;
		}
		x++;
	}
}

void	ft_verif_rectangular_map(int x, t_data_all *data)
{
	size_t	len_line;
	size_t	len_first_line;

	len_first_line = ft_strlen(data->map[0]);
	while (data->map[x])
	{
		len_line = ft_strlen(data->map[x]);
		if (len_line != len_first_line)
			ft_close_game(data, 2, "Error: The map is not rectangular");
		x++;
	}
	data->count_line = x;
	data->size_line = len_first_line;
}

void	ft_verif_map(t_data_all *data)
{
	int		x;
	int		y;
	int		tab[3];

	x = 0;
	y = 0;
	ft_memset(&tab, 0, sizeof(int) * 3);
	ft_verif_elements_map(x, y, data, tab);
	ft_verif_rectangular_map(x, data);
	ft_verif_walls_map(x, y, data);
	if (ft_strnstr(data->mapstr, "\n\n", ft_strlen(data->mapstr))
		|| data->mapstr[ft_strlen(data->mapstr) - 1] == '\n')
		ft_close_game(data, 2, "Error: There is an empty line");
	if (ft_count_letter(data->map, 'P') > 1)
		ft_close_game(data, 2, "Error: There is more than 1 player");
}

void	ft_verif_filename(char *filename)
{
	int	filename_len;

	filename_len = ft_strlen(filename);
	if ((ft_strncmp(filename + filename_len - 4, ".ber", filename_len)) != 0)
	{
		ft_printf("Error: The extension is not ok");
		exit(1);
	}
}
