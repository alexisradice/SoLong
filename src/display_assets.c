/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:05:01 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 00:07:49 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_place_assets_player(t_data_all *data, int x, int y)
{
	if (data->map[x][y] == 'P' && data->player_position == 'U')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->player_top, y * 60, x * 60);
	else if (data->map[x][y] == 'P' && data->player_position == 'B')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->player_back, y * 60, x * 60);
	else if (data->map[x][y] == 'P' && data->player_position == 'L')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->player_left, y * 60, x * 60);
	else if (data->map[x][y] == 'P' && data->player_position == 'R')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->player_right, y * 60, x * 60);
	else if (data->map[x][y] == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->player_top, y * 60, x * 60);
}

void	ft_place_assets(t_data_all *data, int x, int y)
{
	if (data->map[x][y] == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->ground, y * 60, x * 60);
	else if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->obstacle, y * 60, x * 60);
	else if (data->map[x][y] == 'P')
		ft_place_assets_player(data, x, y);
	else if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->collectable, y * 60, x * 60);
	else if (data->map[x][y] == 'E' && data->exit_ok == 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->exit_open, y * 60, x * 60);
	else if (data->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window_ptr, data->exit_close, y * 60, x * 60);
}

void	ft_display_assets(t_data_all *data)
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
			ft_place_assets(data, x, y);
			y++;
		}
		x++;
	}
}
