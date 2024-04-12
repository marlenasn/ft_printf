/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:02:05 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/12 13:02:07 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_helper(int n)
{
	char	a;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len = len + ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		len++;
	}
	else
	{
		a = n + '0';
		write (1, &a, 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write (1, "-2", 2);
		n = 147483648;
		len += 2;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -1 * n;
		len++;
	}
	len += ft_putnbr_helper(n);
	return (len);
}
