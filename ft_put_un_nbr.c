/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:03:39 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/12 13:03:42 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_un_nbr(unsigned int n)
{
	char	a;
	int		len;

	len = 1;
	if (n >= 10)
	{
		len = len + ft_put_un_nbr(n / 10);
		ft_put_un_nbr(n % 10);
	}
	else
	{
		a = n + '0';
		write (1, &a, 1);
	}
	return (len);
}
