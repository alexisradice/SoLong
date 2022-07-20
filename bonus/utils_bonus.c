/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:05:49 by aradice           #+#    #+#             */
/*   Updated: 2022/07/20 04:02:17 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_data(t_data_all *data)
{
	data->player_position = 'N';
	data->exit_ok = 0;
	data->count_collectable = 0;
	data->count_player_moves = 0;
	data->exit_ok = 0;
	data->size_line = 0;
	data->count_line = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->nb_collectible = 0;
	data->frame_anim = 0;
}

void	ft_load_data(t_data_all *data)
{
	ft_load_player(data);
	ft_load_ground_and_obstacles(data);
	ft_load_enemy(data);
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

void	ft_display_movements_count(t_data_all *data)
{
	char	*str;
	char	*count;

	count = ft_itoa(data->count_player_moves);
	str = ft_strdup("Total Movements: ");
	str = ft_strjoin_gnl(str, count);
	mlx_string_put(data->mlx_ptr, data->window_ptr,
		(data->size_line * 60) / 2, data->count_line * 60 - 5, 0xFFFFFF, str);
	free(count);
	free(str);
}
