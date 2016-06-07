/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:35:48 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/07 17:34:49 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putstr_fd("Usage: input one parameter only\njulia\nmandelbrot\n", 2);
	ft_putstr_fd("burning_ship", 2);
	exit(EXIT_FAILURE);
}
