/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:31 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/30 21:49:16 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include "mlx.h"
# include "keynum.h"
# include <math.h>

# ifndef WIN_WIDE 
#  define WIN_WIDE 1920
# endif
# ifndef WIN_HEIGHT 
#  define WIN_HEIGHT 1080
# endif

# define X	0
# define Y	1
# define Z	2
# define MINX 0
# define MINY 1
# define MAXX 2
# define MAXY 3

typedef struct	s_dot
{
	float	x;
	float	y;
	int	z;
	int		col;
}				t_dot;

typedef struct	s_map
{
	char	*map_memory;
	t_dot	**map;
	int		**col;
	int		x;
	int		y;
	int		check_x;
	int		zoom;
	double	angle;
	int		zx;
	int		zy;
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	int		*minmax;
}				t_map;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlxvars
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_map	*map;
}				t_mlxvars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* map */
t_map	*ft_get_map(char **av);
int		ft_check_each_line(t_map *map, char *line);
int		ft_alloc_elem(t_map *map, char *line);
int		ft_check_n_size_map(t_map *map);
int		ft_popol_map(t_map *map);
void	ft_free_map(t_map *map);

/* set dot */
int		ft_set_dot(t_map *map);
void	ft_set_zoom_td(t_map *map);

/* draw_map */
void	ft_draw_map(t_mlxvars *meta, t_dot **map);


#endif
