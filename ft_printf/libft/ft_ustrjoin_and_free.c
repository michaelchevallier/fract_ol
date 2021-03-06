/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrjoin_and_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:38:21 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/04 13:28:00 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		*ft_ustrjoin_and_free(unsigned char *s1, char *s2, int n)
{
	unsigned char	*str;

	if (s1 == NULL || s2 == NULL || n < 0 || n > 3)
		return (NULL);
	str = ft_ustrnew(ft_ustrlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	str = ft_uustrcat(str, s1);
	str = ft_ustrcat(str, s2);
	if (n == 0)
	{
		ft_ustrdel(&s1);
		ft_strdel(&s2);
	}
	else if (n == 1)
		ft_ustrdel(&s1);
	else if (n == 2)
		ft_strdel(&s2);
	return (str);
}
