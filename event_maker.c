/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:41:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 18:06:59 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_img(t_env **e)
{
	int		n;

	n = (*e)->x * (*e)->bpp / 8 + (*e)->y * (*e)->len;
	(*e)->data[n] = (*e)->r;
	(*e)->data[n + 1] = (*e)->g;
	(*e)->data[n + 2] = (*e)->b;
}

void	event_maker(t_env *e)
{
	e->mlx_ptr = mlx_init();
	e->img_ptr = mlx_new_image(e->mlx_ptr, MAP_W, MAP_H);
	e->data = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->len, &e->endian);
	e->mlx_win = mlx_new_window(e->mlx_ptr, MAP_W, MAP_H, e->argv);
	fract_manager(&e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	mlx_hook(e->mlx_win, 2, 1L << 0, keyhook, e);
	mlx_mouse_hook(e->mlx_win, mousehook, e);
	mlx_hook(e->mlx_win, 6, 1L << 6, motion_notifier, e);
}
