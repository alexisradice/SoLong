/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:19:12 by aradice           #+#    #+#             */
/*   Updated: 2022/07/20 05:11:34 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy_animation(t_data_all *data)
{
	if (data->frame_anim == 3000)
		ft_display_animation(data, data->enemy1);
	else if (data->frame_anim == 6000)
		ft_display_animation(data, data->enemy2);
	else if (data->frame_anim >= 9000)
	{
		data->frame_anim = 0;
		ft_display_animation(data, data->enemy3);
	}
	data->frame_anim += 1;
	return (1);
}
