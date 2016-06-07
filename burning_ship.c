/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:31:34 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 18:48:27 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		burning_initialiser(t_env **e)
{
	(*e)->x1 = -2;
	(*e)->x2 = 2.3;
	(*e)->y1 = -2;
	(*e)->y2 = 2;
	(*e)->img_x = 500;
	(*e)->img_y = 500;
	(*e)->max_iter = 17;
	(*e)->zoom = 160;
}

void		baux_aux(t_env **e)
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

void		burning_aux(t_env **e)
{
	(*e)->tmp = (*e)->z_r;
	(*e)->z_r = (*e)->z_r * (*e)->z_r - (*e)->z_i * (*e)->z_i + (*e)->c_r;
	(*e)->z_i = 2 * fabs((*e)->z_i * (*e)->tmp) + (*e)->c_i;
	(*e)->i++;
	if ((*e)->i == (*e)->max_iter)
	{
		(*e)->r = 0;
		(*e)->g = 255;
		(*e)->b = 0;
		draw_img(e);
	}
	else
		baux_aux(e);
}

void		burning_ship(t_env **e)
{
	static int	bob;

	bob++;
	if (bob == 1)
		burning_initialiser(e);
	(*e)->x = 0;
	while ((*e)->x < (*e)->img_x)
	{
		(*e)->y = 0;
		while ((*e)->y < (*e)->img_y)
		{
			(*e)->i = 0;
			(*e)->z_r = (*e)->x / (*e)->zoom + (*e)->x1;
			(*e)->z_i = (*e)->y / (*e)->zoom + (*e)->y1;
			(*e)->c_r = (*e)->x / (*e)->zoom + (*e)->x1;
			(*e)->c_i = (*e)->y / (*e)->zoom + (*e)->y1;
			while (((*e)->z_r * (*e)->z_r + (*e)->z_i * (*e)->z_i) < 4 &&
					(*e)->i < (*e)->max_iter)
				burning_aux(e);
			(*e)->y++;
		}
		(*e)->x++;
	}
}
