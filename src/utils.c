/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:05:49 by aradice           #+#    #+#             */
/*   Updated: 2022/07/21 04:31:22 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	ft_load_data(t_data_all *data)
{
	int		tab[9];

	ft_memset(&tab, 0, sizeof(int) * 9);
	ft_load_player(data, tab);
	ft_load_ground(data, tab);
	ft_load_obstacles(data, tab);
	ft_load_collectables(data, tab);
	ft_load_exit(data, tab);
	if (!data->player_top || !data->player_back || !data->player_left
		|| !data->player_right || !data->ground || !data->obstacle
		|| !data->collectable || !data->exit_close || !data->exit_open)
	{
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		ft_free_mlx_error(data, tab);
		ft_free_map(data);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data->mapstr);
		free(data);
		ft_printf("Error\nImage Problem");
		exit(1);
	}
}

void	ft_free_mlx_error(t_data_all *data, int *tab)
{
	if (tab[0] == 0)
		mlx_destroy_image(data->mlx_ptr, data->player_top);
	if (tab[1] == 0)
		mlx_destroy_image(data->mlx_ptr, data->player_back);
	if (tab[2] == 0)
		mlx_destroy_image(data->mlx_ptr, data->player_left);
	if (tab[3] == 0)
		mlx_destroy_image(data->mlx_ptr, data->player_right);
	if (tab[4] == 0)
		mlx_destroy_image(data->mlx_ptr, data->ground);
	if (tab[5] == 0)
		mlx_destroy_image(data->mlx_ptr, data->obstacle);
	if (tab[6] == 0)
		mlx_destroy_image(data->mlx_ptr, data->collectable);
	if (tab[7] == 0)
		mlx_destroy_image(data->mlx_ptr, data->exit_close);
	if (tab[8] == 0)
		mlx_destroy_image(data->mlx_ptr, data->exit_open);
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
