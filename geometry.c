/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:04:39 by ggiannit          #+#    #+#             */
/*   Updated: 2023/02/02 15:00:16 by ggiannit         ###   ########.fr       */
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
	dot->x = (dot->x - dot->y) * cos(map->angle * M_PI / 180);
	dot->y = (dot->x + dot->y) * sin(map->angle * M_PI / 180)
		- (dot->z * map->zoom / 2);
}

void	ft_rotate_z(t_dot *dot, t_map *map)
{
	float	a;
	float	b;
	double	alpha;

	if (map->alpha == 0)
		return ;
	alpha = map->alpha * M_PI / 180;
	a = dot->x * cos(alpha) - dot->y * sin(alpha);
	b = dot->x * sin(alpha) + dot->y * cos(alpha);
	dot->x = a;
	dot->y = b;
}

void	ft_rotate_x(t_dot *dot, t_map *map)
{
	float	a;
	float	b;
	double	beta;

	if (map->beta == 0)
		return ;
	beta = map->beta * M_PI / 180;
	a = dot->y * cos(beta) + dot->z * sin(beta);
	b = -dot->y * sin(beta) + dot->z * cos(beta);
	dot->y = a;
	dot->z = b;
}

void	ft_rotate_y(t_dot *dot, t_map *map)
{
	float	a;
	float	b;
	double	gamma;

	if (map->gamma == 0)
		return ;
	gamma = map->gamma * M_PI / 180;
	a = dot->x * cos(gamma) + dot->z * sin(gamma);
	b = -dot->x * sin(gamma) + dot->z * cos(gamma);
	dot->x = a;
	dot->z = b;
}
