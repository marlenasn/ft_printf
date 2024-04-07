/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:31:44 by mwiecek           #+#    #+#             */
/*   Updated: 2024/04/07 21:02:39 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int    ft_putchar(char c)
{
        write(1, &c, 1);
        return (1);
}

static int    ft_putnbr(int n)
{
        char    a;
        int	len;

	len = 1;
        if (n == -2147483648)
        {
                write (1, "-", 1);
                write (1, "2", 1);
                n = 147483648;
        }
        if (n < 0)
        {
                write (1, "-", 1);
                n = -1 * n;
        }
        if (n >= 10)
        {
                len = len + ft_putnbr(n / 10);
                ft_putnbr(n % 10);
        }
        else
        {
                a = n + '0';
                write (1, &a, 1);
        }
        return (len);
}

static int    ft_putstr(char *s)
{
	int	len;
	
	len = 0;
        if (s != NULL)
        {
                while (*s)
                {
                        write(1, s, 1);
                        len++;
                        s++;
                }
        }
	return (len);
}

static int    ft_print_ptr(unsigned long ptr, int first)
{
        char    	a;
	unsigned long	n;
	int		len;

	n = (unsigned long)ptr;
	len = 3;
	if(first)
		write(1, "0x", 2);
        if (n >= 16)
        {
                len = len + ft_print_ptr(n / 16, 0);
                ft_print_ptr(n % 16, 0);
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

static int    ft_put_X(unsigned int n)
{
        char    a;
        int	len;

	len = 1;
        if (n >= 16)
        {
                len = len + ft_put_X(n / 16);
                ft_put_X(n % 16);
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

static int    ft_put_x(unsigned int n)
{
        char    a;
        int	len;

	len = 1;
        if (n >= 16)
        {
                len = len + ft_put_x(n / 16);
                ft_put_x(n % 16);
        }
        else
        {
                if (n < 10)
                        a = n + '0';
                else
                        a = n + 87;
                write (1, &a, 1);
        }
        return (len);
}

static int    ft_put_un_nbr(unsigned int n)
{
        char    a;
        int	len;
        
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
		len = len + ft_print_ptr((unsigned long)va_arg(arg, void *), 1);
	else if (c == '%')
	{
		write(1, "%", 1);
		len = len + 1;
	}
	else if (c == 'x')
		len = len + ft_put_x(va_arg(arg, unsigned int));
	else if (c == 'X')
		len = len + ft_put_X(va_arg(arg, unsigned int));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int	len;

	va_start(arg, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len = what_char(*s, arg);
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
	void	*ptr;

	ptr = NULL;
	ft_printf(" %c ", '0');
	write(1, "\n", 1);
	printf(" %c ", '0');
	return (0);
}
