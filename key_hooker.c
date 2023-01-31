/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:00:08 by ggiannit          #+#    #+#             */
/*   Updated: 2023/01/31 18:08:17 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_if_close_x(t_mlxvars *meta)
{
	ft_clean_all(meta);
	exit(0);
	return (0);
}

int ft_key_press(int key_code, t_mlxvars *meta)
{
	if (key_code == B_ESC)
	{
		ft_clean_all(meta);
		exit(0);
	}
	return (0);
}
