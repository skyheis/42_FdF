/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:12:39 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/11 19:25:49 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_give_spot(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_hex(char *str)
{
	int	atoi;

	if (!str)
		return (0);
	atoi = 0;
	str += 2;
	while (*str)
	{
		atoi = atoi * 16 + ft_give_spot(*str, "0123456789ABCDEF");
		str++;
	}
	return (atoi);
}
