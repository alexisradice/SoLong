/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <aradice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 06:29:19 by aradice           #+#    #+#             */
/*   Updated: 2022/07/21 06:34:18 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_mod(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_modif(char *s1, char *s2)
{
	char	*test;
	int		s1size;
	int		s2size;

	s1size = 0;
	s2size = 0;
	test = malloc(sizeof(char) * (ft_strlen_mod(s1) + ft_strlen_mod(s2) + 1));
	if (!test)
		return (NULL);
	while (s1 && s1[s1size])
	{
		test[s1size] = s1[s1size];
		s1size++;
	}
	while (s2[s2size])
	{
		test[s1size++] = s2[s2size++];
	}
	test[s1size] = '\0';
	free(s1);
	return (test);
}
