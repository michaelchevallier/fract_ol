/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:47:15 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 18:48:44 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		tobetold(t_env **e)
{
	(*e)->b = 50;
	return ;
}

void		mandelbrot_initialiser(t_env **e)
{
	(*e)->x1 = -2.1;
	(*e)->x2 = 0.6;
	(*e)->y1 = -1.2;
	(*e)->y2 = 1.2;
	(*e)->img_x = 500;
	(*e)->img_y = 500;
	(*e)->max_iter = 15;
	(*e)->zoom = 180;
}

void		aux_aux(t_env **e)
{
	if ((*e)->i % 2 == 0)
	{
		color_initialiser(e);
		draw_img(e);
	}
	else
	{
		(*e)->g = 0;
		(*e)->b = 255;
		(*e)->r = (*e)->i * 255 / (*e)->max;
		draw_img(e);
	}
}

void		mandel_aux(t_env **e)
{
	(*e)->tmp = (*e)->z_r;
	(*e)->z_r = (*e)->z_r * (*e)->z_r - (*e)->z_i * (*e)->z_i + (*e)->c_r;
	(*e)->z_i = 2 * (*e)->z_i * (*e)->tmp + (*e)->c_i;
	(*e)->i++;
	if ((*e)->i == (*e)->max_iter)
	{
		(*e)->r = 155;
		(*e)->g = 0;
		(*e)->b = 0;
		draw_img(e);
	}
	else
		aux_aux(e);
}

void		mandelbrot(t_env **e)
{
	static int	bob;

	bob++;
	if (bob == 1)
		mandelbrot_initialiser(e);
	(*e)->x = 0;
	while ((*e)->x < (*e)->img_x)
	{
		(*e)->y = 0;
		while ((*e)->y < (*e)->img_y)
		{
			(*e)->i = 0;
			(*e)->z_i = 0;
			(*e)->z_r = 0;
			(*e)->c_r = (*e)->x / (*e)->zoom + (*e)->x1;
			(*e)->c_i = (*e)->y / (*e)->zoom + (*e)->y1;
			while (((*e)->z_r * (*e)->z_r + (*e)->z_i * (*e)->z_i) < 4 &&
					(*e)->i < (*e)->max_iter)
				mandel_aux(e);
			(*e)->y++;
		}
		(*e)->x++;
	}
}
