/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:36:35 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/13 15:28:06 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* open file, check file and get elxline and nline */
/* open file, two malloc matrix */

int	ft_use_map(t_map *map, char *file, int (*ft_each_line)(t_map *, char *))
{
	int		fd;
	char	*line;
	int	i = 0;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!(*ft_each_line)(map, line))
		{
			ft_free_null(&line);
			get_next_line(-42);
			close(fd);
			return (0);
		}
		ft_free_null(&line);
		ft_printf("%i ", i++);
		line = get_next_line(fd);
	}
	ft_printf("\n");
	close(fd);
	return (1);
}

int	ft_check_infile(char *infile)
{
	int	len;

	len = ft_strlen(infile);
	if (len < 5)
		return (0);
	if (!ft_strncmp(&infile[len - 4], ".fdf", 5))
		return (1);
	return (0);
}

t_map *ft_get_map(char **av)
{
	t_map	*map;

	if (!ft_check_infile(av[1]))
		return (NULL);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!ft_use_map(map, av[1], ft_check_each_line))
		return (ft_free_null((char **)&map));
	printf("x is %i\ny is %i\n", map->x, map->y);
	map->val = (int **) malloc(map->y * sizeof(int));
	if (!map->val)
		return (NULL);
//	map->col = (int **) malloc(map->y * sizeof(int));
//	if (!map->col)
//		return (NULL);
	if (!ft_use_map(map, av[1], ft_alloc_val))
	{
		ft_printf("ciao\n");
		return (ft_free_null((char **)&map));
	}
//	if (!ft_use_map(map, av[1], ft_alloc_col))
//		return (ft_free_null((char **)&map));
	return (map);
}

void	fdf_print_matrix(t_map *maps, int **mat)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < maps->y)
	{
		while (x < maps->x)
		{
			ft_printf("%i ", mat[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
		x = 0;
	}
}

int main(int ac, char **av)
{
	t_map	*map;

	if (ac < 2)
		return (1);
	map = ft_get_map(av);
	if (!map)
		return (2);
	fdf_print_matrix(map, map->val);
	ft_free_null((char **)&map);
	ft_free_null((char **)&map);
	return (0);
}
