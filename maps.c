/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:36:35 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/11 19:54:00 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_in_str(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			i++; 
		str++;
	}
	return (i);
}

int	ft_make_map_val(char *line, mmap);
{
	int instances;

	instances = ft_count_in_str(line, ' ') + 1;

}

t_map *ft_get_map(char **av)
{
	int		fd;
	t_map	*map;
	char	*line;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		ft_make_map_val(char *line, &map);
		ft_make_map_col(char *line, &map);
	}
}

