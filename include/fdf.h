/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:48:31 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/14 22:58:03 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include "mlx.h"
# include "keynum.h"

# ifndef WIN_WIDE 
#  define WIN_WIDE 960
# endif
# ifndef WIN_HEIGHT 
#  define WIN_HEIGHT 540
# endif

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
}				t_mlxvars;

typedef struct	s_map
{
	int **val;
	int **col;
	int x;
	int y;
	int max_n;
	int max_e;
	int max_s;
	int max_w;
}				t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* map */
int	ft_check_each_line(t_map *map, char *line);
//int	ft_alloc_val(t_map *map, char *line);
//int	ft_alloc_col(t_map *map, char *line);
int	ft_alloc_elem(t_map *map, char *line);

#endif
