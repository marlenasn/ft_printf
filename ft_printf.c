/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:31:44 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/12 14:41:36 by mwiecek          ###   ########.fr       */
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

int	main(void)
{
	printf("%s\n", "string");
	ft_printf("%s\n", "string");

	printf("%p\n", "string");
        ft_printf("%p\n", "string");

	printf("%d\n", 12345);
        ft_printf("%d\n", 12345);
	
	printf("%%\n");
        ft_printf("%%\n");
	
	printf("%s\n %s\n %s\n", "string1", "string2", "string3");
        ft_printf("%s\n %s\n %s\n", "string1", "string2", "string3");

	printf("%i\n", 123456);
        ft_printf("%i\n", 123456);

	printf("%x\n", 1000000);
        ft_printf("%x\n", 1000000);

	printf("%X\n", 1000000);
        ft_printf("%X\n", 1000000);

	printf(" %s \n", "string");
        ft_printf(" %s \n", "string");

	return (0);
}

