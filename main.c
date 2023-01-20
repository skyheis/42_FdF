/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:04 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/18 15:37:45 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_if_close_x(t_mlxvars *meta)
{
	ft_free_matrix_nozero((char ***) &(meta->map->val), meta->map->y);
	ft_free_matrix_nozero((char ***) &(meta->map->col), meta->map->y);
	ft_free_null((char **)&meta->map);
	ft_free_null((char **)&meta);
	mlx_destroy_window(meta->mlx, meta->win);
	exit(0);
	return (0);
}

int ft_if_close(int key_code, t_mlxvars *meta)
{
	if (key_code == B_ESC)
	{
		mlx_destroy_window(meta->mlx, meta->win);
		ft_free_matrix_nozero((char ***) &(meta->map->val), meta->map->y);
		ft_free_matrix_nozero((char ***) &(meta->map->col), meta->map->y);
		ft_free_null((char **)&meta->map);
		ft_free_null((char **)&meta);
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
			//printf("%d ,", meta->map->zoom);
			x++;
		}
		mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
		y++;
	}
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
	return (0);
}

/*void	ft_drawline(t_mlxvars *meta, int x0, int y0, int x1, int y1)
{
	int dxdy[2];
	int p, x, y;

	dxdy[X] = x1 - x0;
	dxdy[Y] = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dxdy[Y] - dxdy[X];
	while(x < x1)
	{
		if(p >= 0)
		{
			my_mlx_pixel_put(meta->img, x, y, -1);
			y++;
			p = p + 2 * dxdy[Y] - 2 * dxdy[X];
		}
		else
		{
			my_mlx_pixel_put(meta->img, x, y, -1);
			p = p + 2 * dxdy[Y];
		}
		x++;
	}
}*/

/*#include <stdbool.h>

void midPoint(int x1, int y1, int x2, int y2)
{
    bool steep = abs(y2 - y1) > abs(x2 - x1);
    if(steep) {
        // swap x1 and y1
        int tmp = x1;
        x1 = y1;
        y1 = tmp;
        // swap x2 and y2
        tmp = x2;
        x2 = y2;
        y2 = tmp;
    }
    if(x1 > x2) {
        // swap x1 and x2
        int tmp = x1;
        x1 = x2;int	ft_alloc_elem(t_map *map, char *line)
{
	static int	n_line = 0;
	int			n_elem;
	int			i;

	i = 0;
	n_elem = 0;
	map->val[n_line] = (int *) ft_calloc(map->x, sizeof(int));
	map->col[n_line] = (int *) ft_calloc(map->x, sizeof(int));
	while (line[i] == 32)
		i++;
	while (line[i] != 10 && line[i])
	{
		map->val[n_line][n_elem] = ft_atoi(&line[i]);
		while (line[i] != ',' && line[i] != 32 && line[i] != 10 && line[i])
			i++;
		if (line[i] == ',')
			map->col[n_line][n_elem++] = ft_atoi_hex(&line[i + 1]);
		else
			map->col[n_line][n_elem++] = -1;
		while (line[i] != 32 && line[i] != 10 && line[i])
			i++;
		while (line[i] == 32 && line[i] != 10 && line[i])
			i++;
	}
	return (++n_line);
}
        x2 = tmp;
        // swap y1 and y2
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }

    int dx, dy, error, ystep, y;

    dx = x2 - x1;
    dy = abs(y2 - y1);
    error = dx / 2;
    y = y1;

    if(y1 < y2)
        ystep = 1;
    else
        ystep = -1;

    glBegin(GL_POINTS);
    for (x = x1; x <= x2; x++) {
        if(steep)
            glVertex2f(y, x);
        else
            glVertex2f(x, y);
        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
    glEnd();
}*/


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
	meta->win = mlx_new_window(meta->mlx, WIN_WIDE, WIN_HEIGHT, "FdF from ggiannit");
	//win = mlx_new_window(mlx, 720, 720, "FdF from ggiannit");
	meta->img->img = mlx_new_image(meta->mlx, WIN_WIDE, WIN_HEIGHT);
	//printf("img=%p\n", meta->img->img);
	meta->img->addr = mlx_get_data_addr(meta->img->img, 
			&meta->img->bits_per_pixel,
			&meta->img->line_length, &meta->img->endian);
	//ft_zoom(meta);
	drawline(meta, 150, 150, 250, 150);
	drawline(meta, 150, 150, 200, 250);
	drawline(meta, 150, 250, 250, 250);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
	//ft_draw_on_image(meta);
	//mlx_string_put(meta->mlx, meta->win, 42, 42, 0x0, "CIAOOO beppe");
	//mlx_string_put(meta->mlx, meta->win, 42, 42, -1, "CIAOOO beppe");
	mlx_key_hook(meta->win, ft_if_close, (void *)meta);
	mlx_hook(meta->win, 17, 0, ft_if_close_x, (void *)meta);
	//mlx_mouse_hook(meta->win, ft_draw, (void *)meta);
	mlx_loop(meta->mlx);
	return (0);
}
