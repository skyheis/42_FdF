/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:19:48 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/14 23:19:57 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	if (!(*matrix))
		return (NULL);
	while ((*matrix)[i])
		ft_free_null(&(*matrix)[i++]);
	free(*matrix);
	return (NULL);
}

char	*ft_free_matrix_nomat(char **matrix, int i)
{
	while (i)
		ft_free_null(&(matrix)[i--]);
	return (NULL);
}

char	*ft_free_matrix_nozero(char ***matrix, int i)
{
	if (!*matrix)
		return (NULL);
	while (i)
		ft_free_null(&(*matrix)[--i]);
	free(*matrix);
	return (NULL);
}
