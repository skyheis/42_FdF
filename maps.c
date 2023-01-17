/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:36:35 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/15 19:20:52 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	printf("x is %i\ny is %i\n", map->x, map->y);
	ft_free_matrix_nozero((char ***) &(map->val), map->y);
	ft_free_matrix_nozero((char ***) &(map->col), map->y);
	ft_free_null((char **)&map);
*/

int	ft_use_map(t_map *map, char *file, int (*ft_each_line)(t_map *, char *))
{
	int		fd;
	char	*line;

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
		line = get_next_line(fd);
	}
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

t_map	*ft_get_map(char **av)
{
	t_map	*map;

	if (!ft_check_infile(av[1]))
		return (NULL);
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	if (!ft_use_map(map, av[1], ft_check_each_line))
		return (ft_free_null((char **)&map));
	map->val = (int **) ft_calloc(map->y, sizeof(int *));
	map->col = (int **) ft_calloc(map->y, sizeof(int *));
	if (!map->col || !map->val)
		return (NULL);
	if (!ft_use_map(map, av[1], ft_alloc_elem))
		return (ft_free_null((char **)&map));
	return (map);
}

/*void	fdf_print_matrix(t_map *maps, int **mat)
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
}*/

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac < 2)
		return (1);
	map = ft_get_map(av);
	if (!map)
		return (2);
	//fdf_print_matrix(map, map->val);
	//write(1, "\n", 1);
	//fdf_print_matrix(map, map->col);
	ft_free_matrix_nozero((char ***) &(map->val), map->y);
	ft_free_matrix_nozero((char ***) &(map->col), map->y);
	ft_free_null((char **)&map);
	return (0);
}
