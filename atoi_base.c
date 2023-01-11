/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:12:39 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/11 18:37:04 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* WORK IN PROGRESS */

int ft_give_spot(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return i;
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int base_n;
	int value;
	int atoi;

	if (!str)
		return (0);
	atoi = 0;
	base_n = ft_strlen(base);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	value = ft_give_spot(*str, base);
	while (*str && value != -1)
	{
		atoi = atoi * base_n + value;
		str++;
		value = ft_give_spot(*str, base);
	}
	return (atoi);
}

int main(int argc, char *argv[])
{
	(void) argc;
	ft_printf("%d\n", ft_atoi_base(argv[1], argv[2]));
	ft_printf("%d\n", 0xFF342300);
	
	return 0;
}
