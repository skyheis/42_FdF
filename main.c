/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/08 18:09:55 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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
	(void) vars;
	if (button == 1)
	{
		printf("ho hehe cose x=%d y=%d img=%p\n", x, y, vars->img->img);
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0x00FF0000);
	}
		//my_mlx_pixel_put(vars->img->img, x, y, 0xFF00FF00);
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
	vars->win = mlx_new_window(vars->mlx, 960, 540, "FdF from ggiannit");
	//win = mlx_new_window(mlx, 720, 720, "FdF from ggiannit");
	vars->img->img = mlx_new_image(vars->mlx, 420, 420);

	printf("img=%p\n", vars->img->img);

	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	//while (i-- > 0)
	//{
	//	my_mlx_pixel_put(&img, x, y++, 0xFF342342);
	//	my_mlx_pixel_put(&img, x++, y + 20, 0xFF340042);
	//}
	mlx_string_put(vars->mlx, vars->win, 42, 42, 0xFF342300, "CIAOOO beppe");
	mlx_key_hook(vars->win, ft_if_close, (void *)vars);
	mlx_mouse_hook(vars->win, ft_draw, (void *)vars);
	mlx_loop(vars->mlx);
	return (0);
}
