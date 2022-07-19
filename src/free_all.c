/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:04:07 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 05:11:26 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_data_all *data, int id, char *message)
{
	if (id == 1 || id == 2)
		ft_printf("%s\n", message);
	if (id == 1)
		ft_free_all(data);
	else if (id == 2)
		ft_free_all_before_display(data);
	else
	{
		ft_printf("Exit: The cross at the top of the window has been pressed");
		ft_free_all(data);
	}	
	exit(id);
}

void	ft_free_map(t_data_all *data)
{
	int	length;

	length = -1;
	while (data->map[++length] != NULL)
		free(data->map[length]);
	free(data->map);
}

void	ft_free_assets(t_data_all *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player_top);
	mlx_destroy_image(data->mlx_ptr, data->player_back);
	mlx_destroy_image(data->mlx_ptr, data->player_left);
	mlx_destroy_image(data->mlx_ptr, data->player_right);
	mlx_destroy_image(data->mlx_ptr, data->ground);
	mlx_destroy_image(data->mlx_ptr, data->obstacle);
	mlx_destroy_image(data->mlx_ptr, data->collectable);
	mlx_destroy_image(data->mlx_ptr, data->exit_close);
	mlx_destroy_image(data->mlx_ptr, data->exit_open);
}

void	ft_free_all(t_data_all *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	ft_free_assets(data);
	ft_free_map(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->mapstr);
	free(data);
}

void	ft_free_all_before_display(t_data_all *data)
{
	ft_free_map(data);
	free(data->mapstr);
	free(data);
}
