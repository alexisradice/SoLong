/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:03:03 by aradice           #+#    #+#             */
/*   Updated: 2022/07/21 04:32:48 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x - 1][data->player_y] == 'E'
			&& ft_count_letter(data->map, 'C') == 0)
		ft_exit_game(data, 1, "You win!");
	if (data->map[data->player_x - 1][data->player_y] == '0'
			|| data->map[data->player_x - 1][data->player_y] == 'C')
	{
		if (data->map[data->player_x - 1][data->player_y] == 'C')
		{
			data->count_collectable++;
			if (data->count_collectable == data->nb_collectible)
				data->exit_ok = 1;
		}
		data->map[data->player_x - 1][data->player_y] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		data->player_position = 'B';
		data->count_player_moves++;
		ft_printf("Total Movements: %d\n", data->count_player_moves);
		ft_display_assets(data);
	}
}

void	ft_move_down(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x + 1][data->player_y] == 'E'
			&& ft_count_letter(data->map, 'C') == 0)
		ft_exit_game(data, 1, "You win!");
	if (data->map[data->player_x + 1][data->player_y] == '0'
			|| data->map[data->player_x + 1][data->player_y] == 'C')
	{
		if (data->map[data->player_x + 1][data->player_y] == 'C')
		{
			data->count_collectable++;
			if (data->count_collectable == data->nb_collectible)
				data->exit_ok = 1;
		}
		data->map[data->player_x + 1][data->player_y] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		data->player_position = 'U';
		data->count_player_moves++;
		ft_printf("Total Movements: %d\n", data->count_player_moves);
		ft_display_assets(data);
	}
}

void	ft_move_left(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x][data->player_y - 1] == 'E'
			&& ft_count_letter(data->map, 'C') == 0)
		ft_exit_game(data, 1, "You win!");
	if (data->map[data->player_x][data->player_y - 1] == '0'
			|| data->map[data->player_x][data->player_y - 1] == 'C')
	{
		if (data->map[data->player_x][data->player_y - 1] == 'C')
		{
			data->count_collectable++;
			if (data->count_collectable == data->nb_collectible)
				data->exit_ok = 1;
		}
		data->map[data->player_x][data->player_y - 1] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		data->player_position = 'L';
		data->count_player_moves++;
		ft_printf("Total Movements: %d\n", data->count_player_moves);
		ft_display_assets(data);
	}
}

void	ft_move_right(t_data_all *data)
{
	ft_find_player(data);
	if (data->map[data->player_x][data->player_y + 1] == 'E'
			&& ft_count_letter(data->map, 'C') == 0)
		ft_exit_game(data, 1, "You win!");
	if (data->map[data->player_x][data->player_y + 1] == '0'
			|| data->map[data->player_x][data->player_y + 1] == 'C')
	{
		if (data->map[data->player_x][data->player_y + 1] == 'C')
		{
			data->count_collectable++;
			if (data->count_collectable == data->nb_collectible)
				data->exit_ok = 1;
		}
		data->map[data->player_x][data->player_y + 1] = 'P';
		data->map[data->player_x][data->player_y] = '0';
		data->player_position = 'R';
		data->count_player_moves++;
		ft_printf("Total Movements: %d\n", data->count_player_moves);
		ft_display_assets(data);
	}
}

int	ft_key_hook(int key, t_data_all *data)
{
	if (key == 119 || key == 65362)
		ft_move_up(data);
	else if (key == 115 || key == 65364)
		ft_move_down(data);
	else if (key == 97 || key == 65361)
		ft_move_left(data);
	else if (key == 100 || key == 65363)
		ft_move_right(data);
	else if (key == 65307)
		ft_exit_game(data, 1, "Exit\nThe ESC key has been pressed");
	return (0);
}
