/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:00:12 by aradice           #+#    #+#             */
/*   Updated: 2022/07/19 19:39:11 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data_all	*data;

	if (argc != 2)
	{
		ft_printf("Error\nYou need to enter 2 parameters");
		exit(1);
	}
	ft_verif_filename(argv[1]);
	data = ft_parsing_map(argv[1]);
	ft_init_data(data);
	ft_verif_map(data);
	data->mlx_ptr = mlx_init();
	data->window_ptr = mlx_new_window(data->mlx_ptr, (data->size_line * 60),
			(data->count_line * 60), "so_long");
	data->nb_collectible = ft_count_letter(data->map, 'C');
	ft_load_data(data);
	ft_display_assets(data);
	mlx_key_hook(data->window_ptr, ft_key_hook, data);
	mlx_hook(data->window_ptr, 17, (1L << 17), ft_exit_game, data);
	mlx_loop(data->mlx_ptr);
	ft_free_all(data);
	return (0);
}
