/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:05:49 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 00:08:22 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data(t_data_all *data)
{
	data->player_x = 0;
	data->player_y = 0;
	data->player_position = 'N';
	data->count_collectable = 0;
	data->count_moves_player = 0;
	data->exit_ok = 0;
	data->nb_collectible = 0;
	data->size_asset = 0;
	data->window_width = 0;
	data->window_height = 0;
}

void	ft_load_data(t_data_all *data)
{
	ft_load_player(data);
	ft_load_ground(data);
	ft_load_obstacles(data);
	ft_load_collectables(data);
	ft_load_exit(data);
}

void	ft_find_player(t_data_all *data)
{
	int	x;
	int	y;

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
	int	y;
	int	count;

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
