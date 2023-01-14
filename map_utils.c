/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:25 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/14 23:49:50 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_alloc_elem(t_map *map, char *line)
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
			map->col[n_line][n_elem++] = 0;
		while (line[i] != 32 && line[i] != 10 && line[i])
			i++;
		while (line[i] == 32 && line[i] != 10 && line[i])
			i++;
	}
	return (++n_line);
}

/*int	ft_alloc_col(t_map *map, char *line)
{
	static int	n_line = 0;
	int			n_col;
	int			k;

	n_col = 0;
	k = 0;
	map->col[n_line] = (int *) ft_calloc(map->x, sizeof(int));
	while (line[k] == 32)
		k++;
	while (line[k] == '\n' || !line[k])
	{
		while (line[k] != ',' || line[k] == 32 || line[k] == '\n' || !line[k])
			k++;
		if (line[k] == ',')
			map->col[n_line][n_col++] = ft_atoi_hex(&line[k + 1]);
		else
			map->col[n_line][n_col++] = 0;
		while (line[k] != 32 || line[k] == '\n' || !line[k])
			k++;
		while (line[k] == 32 || line[k] == '\n' || !line[k])
			k++;
	}
	n_line++;
	return (1);
}

int	ft_alloc_val(t_map *map, char *line)
{
	static int	n_line = 0;
	int			n_val = 0;
	int			k = 0;

	n_val = 0;
	k = 0;
	map->val[n_line] = (int *) ft_calloc(map->x, sizeof(int));
	while (line[k] == '\n' || !line[k])
	{
		map->val[n_line][n_val] = ft_atoi(&line[k]);
		n_val++;
		while (line[k] != 32 || line[k] == '\n' || !line[k])
			k++;
		while (line[k] == 32 || line[k] == '\n' || !line[k])
			k++;
	}
	n_line++;
	return (1);
}*/

int	ft_check_el(char const *line, int i)
{
	int	old_i;

	while (line[i] != 32 && line[i] != ',' && line[i] != '\n' && line[i] != 0)
	{
		if (line[i] < '0' || line[i] > '9')
			return (-1);
		i++;
	}
	if (line[i] != ',')
		return (i);
	if (line[++i] != '0' || line[i + 1] != 'x')
		return (-1);
	i += 2;
	old_i = i;
	while (line[i] != 32 && line[i] != '\n' && line[i] != '\0')
	{
		if (!ft_strchr("0123456789ABCDEFabcdef", line[i++]))
			return (-1);
	}
	if (i - old_i > 8 || i == old_i)
		return (-1);
	return (i);
}

int	ft_count_el_ncheck(char const *line)
{
	int	i;
	int	n_el;

	i = 0;
	n_el = 0;
	while (line[i])
	{
		while (line[i] == 32)
			i++;
		if (line[i] == '\n')
			break ;
		if (line[i] == '-')
			i++;
		if (line[i] < '0' || line[i] > '9')
			return (-1);
		i = ft_check_el(line, i);
		if (i == -1)
			return (-1);
		n_el++;
	}
	if (n_el == 0)
		return (-1);
	return (n_el);
}

int	ft_check_each_line(t_map *map, char *line)
{
	static unsigned char	first = 1;

	if (first)
	{
		map->x = ft_count_el_ncheck(line);
		map->y = 1;
		if (map->x == -1)
			return (0);
		first = 0;
	}
	else
	{
		if (map->x != ft_count_el_ncheck(line))
			return (0);
		map->y += 1;
	}
	return (1);
}