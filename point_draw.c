/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:09 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/17 15:34:41 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_draw_on_image(t_mlxvars *meta)
{
	int x;
	int y;

	y = 0;
	while (y < meta->map->y)
	{
		x = 0;
		while (x < meta->map->x)
		{
			my_mlx_pixel_put(meta->img,
					x * meta->map->zoom + 20, y * meta->map->zoom + 20,
					meta->map->col[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
}
