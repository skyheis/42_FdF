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

void	ft_zoom(t_mlxvars *meta)
{
	meta->map->zoom = (WIN_WIDE - 40) / meta->map->x;
	if (meta->map->zoom * meta->map->y - 40 > WIN_HEIGHT)
		meta->map->zoom = (WIN_HEIGHT - 40) / meta->map->y;;
	if (!meta->map->zoom)
		meta->map->zoom = 1;
	printf("zoom is %d", meta->map->zoom);
}

