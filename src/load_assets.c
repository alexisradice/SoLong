/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:02:14 by aradice           #+#    #+#             */
/*   Updated: 2022/07/21 04:33:17 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_player(t_data_all *data, int *tab)
{
	int	width;
	int	height;

	data->player_top = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player_top.xpm", &width, &height);
	data->player_back = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player_back.xpm", &width, &height);
	data->player_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player_left.xpm", &width, &height);
	data->player_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/player_right.xpm", &width, &height);
	if (!data->player_top)
		tab[0] = 1;
	if (!data->player_back)
		tab[1] = 1;
	if (!data->player_left)
		tab[2] = 1;
	if (!data->player_right)
		tab[3] = 1;
}

void	ft_load_ground(t_data_all *data, int *tab)
{
	int	width;
	int	height;

	data->ground = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/ground.xpm", &width, &height);
	if (!data->ground)
		tab[4] = 1;
}

void	ft_load_obstacles(t_data_all *data, int *tab)
{
	int	width;
	int	height;

	data->obstacle = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/obstacle.xpm", &width, &height);
	if (!data->obstacle)
		tab[5] = 1;
}

void	ft_load_collectables(t_data_all *data, int *tab)
{
	int	width;
	int	height;

	data->collectable = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/mushroom.xpm", &width, &height);
	if (!data->collectable)
		tab[6] = 1;
}

void	ft_load_exit(t_data_all *data, int *tab)
{
	int	width;
	int	height;

	data->exit_close = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/plate_down.xpm", &width, &height);
	data->exit_open = mlx_xpm_file_to_image(data->mlx_ptr,
			"./assets/plate_up.xpm", &width, &height);
	if (!data->exit_close)
		tab[7] = 1;
	if (!data->exit_open)
		tab[8] = 1;
}
