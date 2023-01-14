/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/14 15:07:39 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_if_close_x(t_mlxvars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int ft_if_close(int key_code, t_mlxvars *vars)
{
	if (key_code == B_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_draw(int button, int x, int y, t_mlxvars *vars)
{
	static int i = 10;
	(void) vars;
	if (button == 1)
	{
		if (i == 5)
			my_mlx_pixel_put(vars->img, x, y, 16711680);
		else
			my_mlx_pixel_put(vars->img, x, y, 0);
		printf("ho hehe cose x=%d y=%d img=%p\n", x, y, vars->img->img);
		if (!(i--))
		{
			i = 10;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
			mlx_string_put(vars->mlx, vars->win, 42, 42, 0xFFFFFFFF, "CIAOOO beppe");
		}
	}
	if (button == 3)
		printf("ho hoho cose x=%d y=%d\n", x, y);
	return (0);
}


//int main(int ac, char **av)
int main(void)
{
	t_mlxvars	*vars;

	vars = (t_mlxvars *) malloc(sizeof(t_mlxvars));
	vars->img = (t_data *) malloc(sizeof(t_data));
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, WIN_WIDE, WIN_HEIGHT, "FdF from ggiannit");
	//win = mlx_new_window(mlx, 720, 720, "FdF from ggiannit");
	vars->img->img = mlx_new_image(vars->mlx, WIN_WIDE, WIN_HEIGHT);

	printf("img=%p\n", vars->img->img);

	vars->img->addr = mlx_get_data_addr(vars->img->img, 
			&vars->img->bits_per_pixel,
			&vars->img->line_length, &vars->img->endian);
	int i = 50;
	int x = 50;
	int y = 50;
	while (i-- > 0)
	{
		my_mlx_pixel_put(vars->img, x, y++, 0xFF342342);
		my_mlx_pixel_put(vars->img, x++, y + 20, 0xFF340042);
	}
	mlx_key_hook(vars->win, ft_if_close, (void *)vars);
	mlx_hook(vars->win, 17, 0, ft_if_close_x, (void *)vars);
	mlx_mouse_hook(vars->win, ft_draw, (void *)vars);
	mlx_string_put(vars->mlx, vars->win, 42, 42, 0x0, "CIAOOO beppe");
	mlx_loop(vars->mlx);
	return (0);
}
