/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:09:08 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/31 17:41:54 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_map *map)
{
	ft_free_matrix_xy((char ***) &(map->map), map->x, map->y);
	ft_free_null((char **)&map->minmax);
	ft_free_null((char **)&map);
}

void	ft_clean_all(t_mlxvars *meta)
{
	ft_free_map(meta->map);
	mlx_destroy_image(meta->mlx, meta->img->img);
	mlx_destroy_window(meta->mlx, meta->win);
	mlx_destroy_display(meta->mlx);
	ft_free_null((char **)&meta->img);
	ft_free_null((char **)&meta->mlx);
	ft_free_null((char **)&meta);
}
