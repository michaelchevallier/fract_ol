/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:22:45 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 19:18:58 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		usage(t_env *e)
{
	if (ft_strcmp(e->argv, "julia") == 0)
		e->fract_type = 1;
	if (ft_strcmp(e->argv, "mandelbrot") == 0)
		e->fract_type = 2;
	if (ft_strcmp(e->argv, "burning_ship") == 0)
		e->fract_type = 3;
	if (e->fract_type == 0)
		ft_error();
}

static void	env_initialiser(t_env **e, char **argv)
{
	*e = (t_env *)ft_memalloc(sizeof(t_env));
	if (*e)
	{
		(*e)->fract_type = 0;
		(*e)->argv = ft_strdup(argv[1]);
		(*e)->r = 0;
		(*e)->g = 0;
		(*e)->b = 0;
		(*e)->space = 1;
	}
}

void		fract_manager(t_env **e)
{
	if ((*e)->fract_type == 1)
		julia(e);
	if ((*e)->fract_type == 2)
		mandelbrot(e);
	if ((*e)->fract_type == 3)
		burning_ship(e);
}

void		mega_usage(t_env *e)
{
	ft_putendl("Press ESC to exit");
	ft_putendl("Scroll to zoom or use  +/-");
	ft_putendl("Use * and / to modify the number of iteration");
	ft_putendl("Use arrow to move image");
	if (e->fract_type == 1)
	{
		ft_putendl("Hover mouse to modify shapes");
		ft_putendl("Press space to lock the shape");
		ft_putendl("You can modify shape with e/r u/i");
	}
}

int			main(int argc, char **argv)
{
	t_env		*e;

	if (argc != 2)
		ft_error();
	env_initialiser(&e, argv);
	usage(e);
	mega_usage(e);
	event_maker(e);
	mlx_loop(e->mlx_ptr);
}
