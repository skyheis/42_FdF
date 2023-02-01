/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:04:39 by ggiannit          #+#    #+#             */
/*   Updated: 2023/02/01 14:58:00 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_top(t_dot *dot, t_map *map)
{
	(void) dot;
	(void) map;
}

void	ft_isometric(t_dot *dot, t_map *map)
{
	//map->angle = 45;
	dot->x = (dot->x - dot->y) * cos(map->angle * M_PI / 180);
	dot->y = (dot->x + dot->y) * sin(map->angle * M_PI / 180) - dot->z;
}

void	ft_rotate_z(t_dot *dot, t_map *map)
{
	float a;
	float b;
	double tate;

	if (map->rotation == 0)
		return ;
	tate = map->rotation * M_PI / 180;
	a = dot->x * cos(tate) - dot->y * sin(tate);
	b = dot->x * sin(tate) + dot->y * cos(tate);
	dot->x = a;
	dot->y = b;
}
