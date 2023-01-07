/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/07 19:22:21 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	if (!mlx)
		return (1);
//	int ok;
//	int ko;
	win = mlx_new_window(mlx, 420, 420, "this is a test");
	//img = mlx_new_image(mlx, 420, 420);
	//mlx_put_image_to_window(mlx, win, img, 0, 0);
	//mlx_string_put(mlx, win, 42, 42, 0xFF342342, "CIAOOO beppe");
	mlx_loop(mlx);
	return (0);
}
/*
	int i = 0;
	int x = 60;
	int y = 60;
	while (i++ < 100)
		mlx_pixel_put(mlx, win, x++, y++, 0xFF342342);
	i = 0;
	x = 60;
	y = 160;
	while (i++ < 100)
		mlx_pixel_put(mlx, win, x++, y--, 0xFF342342);
		*/
