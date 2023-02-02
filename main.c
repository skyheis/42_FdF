/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2023/02/02 17:04:22 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_draw(int button, int x, int y, t_mlxvars *meta)
{
	(void) meta;
	if (button == 4)
	{
		my_mlx_pixel_put(meta->img, x, y, 16711680);
		printf("ho hehe cose x=%d y=%d img=%p\n", x, y, meta->img->img);
		mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
		mlx_string_put(meta->mlx, meta->win, 42, 42, 0xFFFFFFFF, "CIAOOO beppe");
	}
	if (button == 5)
		printf("ho hoho cose x=%d y=%d\n", x, y);
	return (0);
}

void	ft_set_img(t_mlxvars *meta, t_data *img)//void (*ft_vision)(t_dot *, t_map *))
{
	if (img->img)
		mlx_destroy_image(meta->mlx, img->img);
	img->img = mlx_new_image(meta->mlx, WIN_WIDE, WIN_HEIGHT);
	meta->img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	//serve un flag per ogni visione
	if (meta->map->vision == 1)
		ft_set_dot(meta->map, ft_isometric);
	else if (meta->map->vision == 0)
		ft_set_dot(meta->map, ft_top);
	else
		return ;
	ft_draw_map(meta, meta->map->map);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_mlxvars	*meta;

	(void)ac;
	meta = (t_mlxvars *) malloc(sizeof(t_mlxvars));
	meta->map = ft_get_map(av);
	meta->img = (t_data *) malloc(sizeof(t_data));
	if (!meta->map || !meta->img)
		return (2);
	meta->img->img = NULL;
	meta->mlx = mlx_init();
	if (!meta->mlx)
		return (1);
	meta->win = mlx_new_window(meta->mlx, WIN_WIDE, WIN_HEIGHT, "FdF ggiannit");
	//ft_set_zoom_td(meta->map);
	ft_set_img(meta, meta->img);//, ft_isometric);
	//mlx_string_put(meta->mlx, meta->win, 42, 42, 0x0, "CIAOOO beppe");
	//mlx_string_put(meta->mlx, meta->win, 42, 42, -1, "CIAOOO beppe");
	//mlx_key_hook(meta->win, ft_if_close, (void *)meta);
	mlx_hook(meta->win, 17, 0L, ft_if_close_x, (void *)meta);
	mlx_hook(meta->win, 2, 1L<<0, ft_key_press, (void *)meta);
	mlx_mouse_hook(meta->win, ft_mouse_press, (void *)meta);
	mlx_loop(meta->mlx);
	return (0);
}
