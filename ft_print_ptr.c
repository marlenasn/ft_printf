/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:57:27 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/12 12:59:08 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr_chars(unsigned long n)
{
	char	a;
	int		len;

	len = 1;
	if (n >= 16)
	{
		len = len + ft_print_ptr_chars(n / 16);
		ft_print_ptr_chars(n % 16);
	}
	else
	{
		if (n < 10)
			a = n + '0';
		else
			a = (n - 10) + 'a';
		write (1, &a, 1);
	}
	return (len);
}

int	ft_print_ptr(unsigned long ptr)
{
	unsigned long	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = (unsigned long)ptr;
	write(1, "0x", 2);
	return (2 + ft_print_ptr_chars(n));
}
