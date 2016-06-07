/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peripherals_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:02:50 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 18:54:00 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	motion_aux(int x, int y, t_env *e)
{
	if (x > 250)
	{
		e->c_r += 0.005;
		e->c_i += 0.005;
	}
	else if (x <= 250)
	{
		e->c_r -= 0.005;
		e->c_i -= 0.005;
	}
	if (y > 250)
	{
		e->c_r += 0.01;
		e->c_i += 0.01;
	}
	else if (y <= 250)
	{
		e->c_r -= 0.01;
		e->c_i -= 0.01;
	}
}

int		motion_notifier(int x, int y, t_env *e)
{
	if (e->space == 1)
	{
		if (x >= 0 && y >= 0 && x <= 500 && y <= 500)
			motion_aux(x, y, e);
	}
	free(e->data);
	e->img_ptr = mlx_new_image(e->mlx_ptr, MAP_W, MAP_H);
	e->data = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->len, &e->endian);
	fract_manager(&e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	return (0);
}

int		mousehook(int button, int x, int y, t_env *e)
{
	x = y;
	if (button == 5)
		e->zoom += 20;
	if (button == 7)
		e->zoom -= 20;
	free(e->data);
	e->img_ptr = mlx_new_image(e->mlx_ptr, MAP_W, MAP_H);
	e->data = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->len, &e->endian);
	fract_manager(&e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	return (0);
}

int		keyhook(int keycode, t_env *e)
{
	(keycode == 53 ? exit(EXIT_SUCCESS) : 0);
	(keycode == 123 ? e->x1 += 5 / e->zoom : 0);
	(keycode == 126 ? e->y1 += 5 / e->zoom : 0);
	(keycode == 124 ? e->x1 -= 5 / e->zoom : 0);
	(keycode == 125 ? e->y1 -= 5 / e->zoom : 0);
	(keycode == 67 ? e->max_iter++ : 0);
	(keycode == 75 ? e->max_iter-- : 0);
	(keycode == 78 ? e->zoom -= 20 : 0);
	(keycode == 69 ? e->zoom += 20 : 0);
	(keycode == 15 ? e->c_r += 0.00125 : 0);
	(keycode == 34 ? e->c_i += 0.0005 : 0);
	(keycode == 14 ? e->c_r -= 0.00125 : 0);
	(keycode == 32 ? e->c_i -= 0.0005 : 0);
	if (keycode == 49 && e->space == 0)
		e->space = 1;
	else if (keycode == 49 && e->space == 1)
		e->space = 0;
	free(e->data);
	e->img_ptr = mlx_new_image(e->mlx_ptr, MAP_W, MAP_H);
	e->data = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->len, &e->endian);
	fract_manager(&e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	return (0);
}
