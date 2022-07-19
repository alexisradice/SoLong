/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:02:14 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 00:07:58 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_obstacles(t_data_all *data)
{
	int	width;
	int	height;

	data->obstacle = mlx_xpm_file_to_image(data->mlx_ptr, \
		"./assets/obstacle.xpm", &width, &height);
}

void	ft_load_collectables(t_data_all *data)
{
	int	width;
	int	height;

	data->collectable = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/mushroom.xpm", &width, &height);
}

void	ft_load_player(t_data_all *data)
{
	int	width;
	int	height;

	data->player_top = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/player_top.xpm", &width, &height);
	data->player_back = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/player_back.xpm", &width, &height);
	data->player_left = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/player_left.xpm", &width, &height);
	data->player_right = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/player_right.xpm", &width, &height);
}

void	ft_load_exit(t_data_all *data)
{
	int	width;
	int	height;

	data->exit_close = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/plate_down.xpm", &width, &height);
	data->exit_open = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/plate_up.xpm", &width, &height);
}

void	ft_load_ground(t_data_all *data)
{
	int	width;
	int	height;

	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets/ground.xpm", &width, &height);
}
