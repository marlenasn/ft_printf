/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cap_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:59:43 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/12 13:00:32 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_cap_x(unsigned int n)
{
	char	a;
	int		len;

	len = 1;
	if (n >= 16)
	{
		len = len + ft_put_cap_x(n / 16);
		ft_put_cap_x(n % 16);
	}
	else
	{
		if (n < 10)
			a = n + '0';
		else
			a = n + 55;
		write (1, &a, 1);
	}
	return (len);
}
