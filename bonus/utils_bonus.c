/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:05:49 by aradice           #+#    #+#             */
/*   Updated: 2022/07/21 06:32:23 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_data(t_data_all *data)
{
	int		tab[12];

	ft_memset(&tab, 0, sizeof(int) * 12);
	ft_load_player(data, tab);
	ft_load_ground_and_obstacles(data, tab);
	ft_load_enemy(data, tab);
	ft_load_collectables(data, tab);
	ft_load_exit(data, tab);
	if (!data->player_top || !data->player_back || !data->player_left
		|| !data->player_right || !data->ground || !data->obstacle
		|| !data->collectable || !data->exit_close || !data->exit_open
		|| !data->enemy1 || !data->enemy2 || !data->enemy3)
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
	if (tab[9] == 0)
		mlx_destroy_image(data->mlx_ptr, data->enemy1);
	if (tab[10] == 0)
		mlx_destroy_image(data->mlx_ptr, data->enemy2);
	if (tab[11] == 0)
		mlx_destroy_image(data->mlx_ptr, data->enemy3);
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
	str = ft_strjoin_modif(str, count);
	mlx_string_put(data->mlx_ptr, data->window_ptr,
		(data->size_line * 60) / 2, data->count_line * 60 - 5, 0xFFFFFF, str);
	free(count);
	free(str);
}
