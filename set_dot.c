/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:34:42 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/27 15:46:38 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_dot *dot, t_map *map)
{
	dot->x = (dot->x - dot->y) * cos(map->angle) + map->zx;
	dot->y = (dot->x + dot->y) * sin(map->angle) - dot->z;
	//printf("x %f  y %f     zx %i zy %i\n", dot->x, dot->y, map->zx, map->zy);
}

void	ft_fix_zoom(t_map *map)//isometric function to be added
{
	int	diff_y;

	while (map->min_x < map->minmax[MINX] || map->max_x > map->minmax[MAXX])
	{
		map->zoom -= 1;
		ft_set_dot(map);
	}
	while (map->min_y < map->minmax[MINY])
	{
		diff_y = map->min_y - map->minmax[MINY];
		if (diff_y + map->max_x < map->minmax[MAXY])
			map->zy += diff_y - 1;
		else
			map->zoom -= 1;
		ft_set_dot(map);
	}
}//to be done

void	ft_set_zoom_td(t_map *map)
{
	int	zoom_x;
	int	zoom_y;

	zoom_x = (WIN_WIDE - (WIN_WIDE / 10)) / (map->x);
	zoom_y = (WIN_HEIGHT - (WIN_HEIGHT / 10)) / (map->y);
	if (zoom_x < zoom_y)
		map->zoom = zoom_x;
	else
		map->zoom = zoom_y;
}

/*void	fdf_print_dot(t_map *maps, t_dot **mat)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < maps->y)
	{
		while (x < maps->x)
		{
			ft_printf("%i,%i,%i   ", mat[y][x].x, mat[y][x].y, mat[y][x].z);
			x++;
		}
		ft_printf("\n");
		y++;
		x = 0;
	}
}*/

/*int	ft_set_dot(t_map *map)
{
	int	a;
	int	b;
	int kx;
	int ky;

	ky = 0;
	a = (map->x / 2);
	b = (map->y / 2);
	while (ky < map->y)
	{
		kx = 0;
		while (kx < map->x)
		{
			map->map[ky][kx].x = kx - a + (map->zoom * (kx + a));
			map->map[ky][kx].y = ky - b + map->zy;
			kx++;
		}
		ky++;
	}
	fdf_print_dot(map, map->map);
	return (0);
}*/

int	ft_reset_minmax(t_map *map)
{
	map->min_x = WIN_WIDE;
	map->min_y = WIN_HEIGHT;
	map->max_x = -1;
	map->max_y = -1;
	return (0);
}

void	ft_fill_minmax(t_map *map, int the_x, int the_y)
{
	if (the_x > map->max_x)
		map->max_x = the_x;
	if (the_x < map->min_x)
		map->min_x = the_x;
	if (the_y > map->max_y)
		map->max_y = the_y;
	if (the_y < map->min_y)
		map->min_y = the_y;
}

int	ft_set_dot(t_map *map)
{
	int	a;
	int	b;
	int kx;
	int ky;

	ky = ft_reset_minmax(map);
	b = -1 * (map->y / 2);
	while (ky < map->y)
	{
		kx = 0;
		a = -1 * (map->x / 2);
		while (kx < map->x)
		{
			//map->map[ky][kx].x = (float) (a * map->zoom) + map->zx;
			//map->map[ky][kx].y = (float) (b * map->zoom) + map->zy;
			map->map[ky][kx].x = (float) (a * map->zoom);
			map->map[ky][kx].y = (float) (b * map->zoom);
			ft_isometric(&map->map[ky][kx], map);
			//ft_fill_minmax(map, (int) map->map[ky][kx].x, (int) map->map[ky][kx].y);
			//what if lo faccio qua il check no perche' non se scendere o dezoom
			kx++;
			a++;
		}
		ky++;
		b++;
	}//fdf_print_dot(map, map->map);
	return (0);
}
