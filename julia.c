/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:01:30 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 18:47:54 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_initialiser(t_env **e)
{
	(*e)->c_r = 0.285;
	(*e)->c_i = 0.01;
	(*e)->x1 = -1.27;
	(*e)->x2 = 1;
	(*e)->y1 = -1.3;
	(*e)->y2 = 1.2;
	(*e)->img_x = 500;
	(*e)->img_y = 500;
	(*e)->max_iter = 25;
	(*e)->zoom = 190;
}

void		jaux_aux(t_env **e)
{
	if ((*e)->i % 2 == 0)
	{
		color_initialiser(e);
		draw_img(e);
	}
	else
	{
		(*e)->r = 0;
		(*e)->b = 0;
		(*e)->g = (*e)->i * 250 / (*e)->max;
		draw_img(e);
	}
}

void		julia_aux(t_env **e)
{
	(*e)->tmp = (*e)->z_r;
	(*e)->z_r = (*e)->z_r * (*e)->z_r - (*e)->z_i * (*e)->z_i + (*e)->c_r;
	(*e)->z_i = 2 * (*e)->z_i * (*e)->tmp + (*e)->c_i;
	(*e)->i++;
	if ((*e)->i == (*e)->max_iter)
	{
		(*e)->r = 0;
		(*e)->g = 255;
		(*e)->b = 0;
		draw_img(e);
	}
	else
		jaux_aux(e);
}

void		julia(t_env **e)
{
	static int	bob;

	bob++;
	if (bob == 1)
		julia_initialiser(e);
	(*e)->x = 0;
	while ((*e)->x < (*e)->img_x)
	{
		(*e)->y = 0;
		while ((*e)->y < (*e)->img_y)
		{
			(*e)->i = 0;
			(*e)->z_r = (*e)->x / (*e)->zoom + (*e)->x1;
			(*e)->z_i = (*e)->y / (*e)->zoom + (*e)->y1;
			while (((*e)->z_r * (*e)->z_r + (*e)->z_i * (*e)->z_i) < 4 &&
				(*e)->i < (*e)->max_iter)
				julia_aux(e);
			(*e)->y++;
		}
		(*e)->x++;
	}
}
