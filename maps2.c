/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:36:35 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/19 17:18:49 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	printf("x is %i\ny is %i\n", map->x, map->y);
	ft_free_matrix_nozero((char ***) &(map->val), map->y);
	ft_free_matrix_nozero((char ***) &(map->col), map->y);
	ft_free_null((char **)&map);
*/
# define READ_SIZE	5000

void	ft_set_map_x(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_memory[i] != '\n')
	{
		while (map->map_memory[i] == 32)
			i++;
		if (map->map_memory[i] != '\n')
			map->x += 1;
		while (map->map_memory[i] != 32 && map->map_memory[i] != '\n')
			i++;
	}
}

int	ft_read_map(t_map *map, char *file)
{
	int		fd;
	int		b_readed;
	char	*file_memory;

	b_readed = READ_SIZE;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (b_readed == READ_SIZE)
	{
		file_memory = (char *) ft_calloc(READ_SIZE, sizeof(char));
		b_readed = read(fd, file_memory, READ_SIZE);
		if (b_readed == -1)
			return (0);
			//return(ft_free_null(&map->map_memory));
		map->map_memory = ft_strjoin_free(map->map_memory, file_memory);
	}
	close(fd);
	ft_set_map_x(map);
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

int	ft_init_map(t_map *map)
{
	map->map_memory = NULL;
	map->val = NULL;
	map->col = NULL;
	map->x = 0;
	map->y = 1;
	map->check_x = 0;
}

t_map	*ft_get_map(char **av)
{
	t_map	*map;

	if (!ft_check_infile(av[1]))
		return (NULL);
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	ft_init_map(map);
	if (!map)
		return (NULL);
	if (!ft_read_map(map, av[1]))
		return (ft_free_null((char **)&map));
	if (!ft_check_n_size_map(map))
		return (NULL);
	map->val = (int **) ft_calloc(map->y, sizeof(int *));
	map->col = (int **) ft_calloc(map->y, sizeof(int *));
	if (!map->col || !map->val)
		return (NULL);

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
