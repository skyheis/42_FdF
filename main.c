/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/30 22:36:08 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean_all(t_mlxvars *meta)
{
	ft_free_map(meta->map);
	ft_free_null((char **)&meta);
	mlx_destroy_window(meta->mlx, meta->win);
}

int ft_if_close_x(t_mlxvars *meta)
{
	ft_clean_all(meta);
	exit(0);
	return (0);
}

int ft_if_close(int key_code, t_mlxvars *meta)
{
	if (key_code == B_ESC)
	{
		ft_clean_all(meta);
		exit(0);
	}
	return (0);
}

int	ft_draw(int button, int x, int y, t_mlxvars *meta)
{
	(void) meta;
	if (button == 1)
	{
		my_mlx_pixel_put(meta->img, x, y, 16711680);
		printf("ho hehe cose x=%d y=%d img=%p\n", x, y, meta->img->img);
		mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
		mlx_string_put(meta->mlx, meta->win, 42, 42, 0xFFFFFFFF, "CIAOOO beppe");
	}
	if (button == 3)
		printf("ho hoho cose x=%d y=%d\n", x, y);
	return (0);
}

void	ft_zoom(t_mlxvars *meta)
{
	meta->map->zoom = (WIN_WIDE - 40) / meta->map->x;
	if (meta->map->zoom * meta->map->y - 40 > WIN_HEIGHT)
		meta->map->zoom = (WIN_HEIGHT - 40) / meta->map->y;;
	if (!meta->map->zoom)
		meta->map->zoom = 1;
	printf("zoom is %d", meta->map->zoom);
}

int	ft_draw_on_image(t_mlxvars *meta)
{
	int kx;
	int ky;

	ky = 0;
	while (ky < meta->map->y)
	{
		kx = 0;
		while (kx < meta->map->x)
		{
			my_mlx_pixel_put(meta->img,
					(int) meta->map->map[ky][kx].x, (int) meta->map->map[ky][kx].y,
					meta->map->map[ky][kx].col);
			//printf("%d ,", meta->map->zoom);
			kx++;
		}
		mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
		ky++;
	}
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
	return (0);
}

//int main(int ac, char **av)
int main(int ac, char **av)
{
	t_mlxvars	*meta;

	(void)ac;
	meta = (t_mlxvars *) malloc(sizeof(t_mlxvars));
	meta->map = ft_get_map(av);
	if (!meta->map)
		return (2);
	meta->img = (t_data *) malloc(sizeof(t_data));
	meta->mlx = mlx_init();
	if (!meta->mlx)
		return (1);
	meta->win = mlx_new_window(meta->mlx, WIN_WIDE, WIN_HEIGHT, "FdF ggiannit");
	meta->img->img = mlx_new_image(meta->mlx, WIN_WIDE, WIN_HEIGHT);
	//printf("img=%p\n", meta->img->img);
	meta->img->addr = mlx_get_data_addr(meta->img->img, 
			&meta->img->bits_per_pixel,
			&meta->img->line_length, &meta->img->endian);
	//ft_zoom(meta);
	//drawline(meta, 150, 250, 250, 250);
	ft_draw_on_image(meta);
	ft_draw_map(meta, meta->map->map);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
	//mlx_string_put(meta->mlx, meta->win, 42, 42, 0x0, "CIAOOO beppe");
	//mlx_string_put(meta->mlx, meta->win, 42, 42, -1, "CIAOOO beppe");
	
	mlx_key_hook(meta->win, ft_if_close, (void *)meta);
	mlx_hook(meta->win, 17, 0, ft_if_close_x, (void *)meta);
	//mlx_mouse_hook(meta->win, ft_draw, (void *)meta);
	mlx_loop(meta->mlx);
	return (0);
}
