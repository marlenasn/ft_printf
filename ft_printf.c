/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:31:44 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/08 10:58:28 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	what_char(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len = len + ft_putstr(va_arg(arg, char *));
	else if (c == 'i' || c == 'd')
		len = len + ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len = len + ft_put_un_nbr(va_arg(arg, unsigned int));
	else if (c == 'p')
		len = len + ft_print_ptr((unsigned long)va_arg(arg, void *));
	else if (c == '%')
	{
		write(1, "%", 1);
		len = len + 1;
	}
	else if (c == 'x')
		len = len + ft_put_x(va_arg(arg, unsigned int));
	else if (c == 'X')
		len = len + ft_put_cap_x(va_arg(arg, unsigned int));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len += what_char(*s, arg);
			s++;
		}
		else
		{
			write(1, s, 1);
			len = len + 1;
			s++;
		}
	}
	va_end(arg);
	return (len);
}
/*
int	main(void)
{
	int ft_res = ft_printf(" %d %d ", 0, 0);
	printf("%d\n", ft_res);
	write(1, "\n", 1);
	int print_res = printf(" %d %d ", 0, 0);
	printf("%d\n", print_res);
	int ft_res2 = ft_printf(" %d ", 16);
	printf("%d\n", ft_res2);
	write(1, "\n", 1);
	int print_res2 = printf(" %d ", 16);
	printf("%d\n", print_res2);
	return (0);
}
*/
/*
int main(void)
{
	int ft_res = ft_printf(" %d ", INT_MIN);
	printf("%d\n", ft_res);
	write(1, "\n", 1);
	int print_res = printf(" %d ", INT_MIN);
	printf("%d\n", print_res);

}
*/
