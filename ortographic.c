/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortographic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:23:05 by ggiannit          #+#    #+#             */
/*   Updated: 2023/02/07 10:48:54 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_orto(t_map *map, int new_zx, int new_zy,
		void (*ft_vision)(t_dot *, t_map *))
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
			map->map[ky][kx].x = (float) (a++ * map->zoom);
			map->map[ky][kx].y = (float) (b * map->zoom);
			ft_vision(&map->map[ky][kx], map);
			map->map[ky][kx].x += new_zx;
			map->map[ky][kx].y += new_zy;
			ft_fill_minmax(map, (int) map->map[ky][kx].x,
					(int) map->map[ky][kx].y);
			kx++;
		}
		ky++;
		b++;
	}
}

void	ft_orto_lines(t_mlxvars *meta)
{
	t_dot a;
	t_dot b;

	a.z = 0;
	a.col = -1;
	b.z = 0;
	b.col = -1;
	a.x = WIN_WIDE / 12 * 2;
	a.y = WIN_HEIGHT >> 1;
	b.x = WIN_WIDE;
	b.y = WIN_HEIGHT >> 1;
	ft_bresenham(meta, a, b);
	a.x = (WIN_WIDE >> 1) + WIN_WIDE / 12;
	a.y = 0;
	b.x = (WIN_WIDE >> 1) + WIN_WIDE / 12;
	b.y = WIN_HEIGHT;
	ft_bresenham(meta, a, b);
}

void	ft_orto_zoomfix(t_map *map)
{
	int	zoom_x;
	int	zoom_y;
	int	new_wide;

	new_wide = WIN_WIDE - (WIN_WIDE / 6);
	zoom_x = ((new_wide >> 1) - ((new_wide >> 1) / 10)) / map->x;
	zoom_y = ((WIN_HEIGHT >> 1) - ((WIN_HEIGHT >> 1) / 10)) / map->y;
	if (zoom_x > zoom_y)
		map->zoom = zoom_y;
	else
		map->zoom = zoom_x;
	if (!map->zoom)
		map->zoom = 1;
}

int	check_zoomfit_down(t_map *map, int new_zx, int new_zy, int k)
{
	int	diff_y;

	ft_set_orto(map, new_zx, new_zy + k, ft_ytoz);
	while (map->min_y < new_zy + 15 || map->max_y > WIN_HEIGHT - 15)
	{
		diff_y = abs(map->min_y - new_zy - 15);
		if (diff_y + map->max_y < WIN_HEIGHT - 15)
			k += diff_y;
		else
			map->zoom -= 1;
		ft_set_orto(map, new_zx, new_zy + k, ft_ytoz);
	}
	return (k);
}

/*int	check_zoomfit_right(t_map *map, int new_zx, int new_zy, int k)
{
	int	diff_x;

	while (map->min_x < new_zx + 15 || map->max_x > WIN_WIDE - 15)
	{
		diff_x = abs(map->min_x - new_zx - 15);
		if (diff_x + map->max_x < WIN_WIDE - 15)
			k += diff_x;
		else
			map->zoom -= 1;
		ft_set_orto(map, new_zx + k, new_zy, ft_xtoz);
	}
	return (k);
}*/

void	ft_ortographic(t_mlxvars *meta)
{
	int	new_zx;
	int	new_zy;
	int	k;
	int	old_zoom;

	old_zoom = meta->map->zoom;
	//ft_orto_zoomfix(meta->map);
	//new_zx = ((WIN_WIDE >> 2) + WIN_WIDE / 9);
	//new_zy = (WIN_HEIGHT >> 2);
	//ft_set_orto(meta->map, new_zx , new_zy, ft_top);
	//ft_draw_map(meta, meta->map->map);
	//k = WIN_HEIGHT >> 2;
	new_zx = ((WIN_WIDE >> 2) + WIN_WIDE / 9);
	new_zy = (WIN_HEIGHT >> 1);
	k = check_zoomfit_down(meta->map, new_zx, new_zy, WIN_HEIGHT >> 2);
	
	//ft_set_orto(meta->map, new_zx , new_zy + k, ft_ytoz);
	//ft_draw_map(meta, meta->map->map);
	
	// non serve ad una sega
	//new_zx = ((WIN_WIDE >> 1) + WIN_WIDE / 12);
	//new_zy = (WIN_HEIGHT >> 2);
	//ik = check_zoomfit_right(meta->map, new_zx, new_zy, k);
	//ft_set_orto(meta->map, new_zx + k, new_zy, ft_xtoz);
	//ft_draw_map(meta, meta->map->map);
	
	///////priiint
	new_zx = ((WIN_WIDE >> 2) + WIN_WIDE / 9);
	new_zy = (WIN_HEIGHT >> 2);
	ft_set_orto(meta->map, new_zx , new_zy, ft_top);
	ft_draw_map(meta, meta->map->map);

	new_zx = ((WIN_WIDE >> 2) + WIN_WIDE / 9);
	new_zy = (WIN_HEIGHT >> 1);
	ft_set_orto(meta->map, new_zx, new_zy + k, ft_ytoz);
	ft_draw_map(meta, meta->map->map);

	new_zx = ((WIN_WIDE >> 1) + WIN_WIDE / 12);
	new_zy = (WIN_HEIGHT >> 2);
	ft_set_orto(meta->map, new_zx + k, new_zy, ft_xtoz);
	ft_draw_map(meta, meta->map->map);

	ft_orto_lines(meta);
	meta->map->zoom = old_zoom;
}

/* my_mlx_pixel_put(meta->img, ((WIN_WIDE >> 1) + WIN_WIDE / 12)  , new_zy, 0x000FF); */
