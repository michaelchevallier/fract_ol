/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 13:34:10 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 18:50:48 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# define MAP_W 500
# define MAP_H 500

typedef struct		s_env
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_new_image;
	void	*img_ptr;
	char	*argv;
	char	*data;
	int		len;
	int		bpp;
	int		endian;
	int		fract_type;
	int		img_x;
	int		img_y;
	float	zoom;
	float	tmp;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	max;
	int		r;
	int		g;
	int		b;
	int		i;
	int		space;
	float	z_r;
	float	z_i;
	float	c_r;
	float	c_i;
	int		max_iter;
}					t_env;

int					keyhook(int keycode, t_env *e);
int					mousehook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);
int					motion_notifier(int x, int y, t_env *e);
void				ft_error();
void				event_maker(t_env *e);
void				draw_img(t_env **e);
void				burning_ship(t_env **e);
void				julia(t_env **e);
void				mandelbrot(t_env **e);
void				tobetold(t_env **e);
void				color_initialiser(t_env **e);
void				fract_manager(t_env **e);
void				usage(t_env *e);
#endif
