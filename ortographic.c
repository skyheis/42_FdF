/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortographic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:23:05 by ggiannit          #+#    #+#             */
/*   Updated: 2023/02/06 20:36:24 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* reset center
 * take the center of each quadrant
 * first qadrant top
 * second xtoz
 * third ytoz
 */
int	ft_set_orto(t_map *map, int new_zx, int new_zy,
		void (*ft_vision)(t_dot *, t_map *))
{
	int	a;
	int	b;
	int kx;
	int ky;

	ky = 0;
	b = -1 * (map->y / 2);
	//map->max_y = 0;
	//map->min_y = 0;
	while (ky < map->y)
	{
		kx = 0;
		a = -1 * (map->x / 2);
		while (kx < map->x)
		{
			map->map[ky][kx].x = (float) (a * map->zoom);// + new_zx;
			map->map[ky][kx].y = (float) (b * map->zoom);// + new_zy;
			ft_vision(&map->map[ky][kx], map);
			map->map[ky][kx].x += new_zx;
			map->map[ky][kx].y += new_zy;
			//if (map->map[ky][kx].z > map->max_y)
			//	map->max_y = map->map[ky][kx].z;d
			kx++;
			a++;
		}
		ky++;
		b++;
	}
	return (0);
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

/*void	ft_orto_zoomfix(t_mlxvars *meta) */

void	ft_ortographic(t_mlxvars *meta)
{
	int	new_zx;
	int	new_zy;
	int	k;

	//meta->map->zoom = 30;
	new_zx = ((WIN_WIDE >> 2) + WIN_WIDE / 9);
	new_zy = (WIN_HEIGHT >> 2);
	meta->map->zoom = 1;
	ft_set_orto(meta->map, new_zx , new_zy, ft_top);
	ft_draw_map(meta, meta->map->map);
	k = WIN_HEIGHT >> 2;
	new_zx = ((WIN_WIDE >> 2) + WIN_WIDE / 9);
	new_zy = (WIN_HEIGHT >> 1) + k;
	ft_set_orto(meta->map, new_zx , new_zy, ft_ytoz);
	ft_draw_map(meta, meta->map->map);
	new_zx = ((WIN_WIDE >> 1) + WIN_WIDE / 12 + k);
	new_zy = (WIN_HEIGHT >> 2);
	ft_set_orto(meta->map, new_zx , new_zy, ft_xtoz);
	ft_draw_map(meta, meta->map->map);
	ft_orto_lines(meta);
}

/* my_mlx_pixel_put(meta->img, ((WIN_WIDE >> 1) + WIN_WIDE / 12)  , new_zy, 0x000FF); */
