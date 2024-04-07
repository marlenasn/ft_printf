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
#include <limits.h>

static int    ft_putchar(char c)
{
        write(1, &c, 1);
        return (1);
}

static int    ft_putnbr(int n)
{
        char    a;
        int	len;
	
	len = 0;
        if (n == -2147483648)
        {
                write (1, "-2", 2);
                n = 147483648;
		len += 2; // - and 2
        }
        if (n < 0)
        {
                write (1, "-", 1);
                n = -1 * n;
		len++;
        }

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
	else
	{
		write(1, "(null)", 6);
		len = 6;
	}
	return (len);
}

static int	ft_print_ptr_chars(unsigned long n)
{
        char    	a;
	int	len;
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

static int    ft_print_ptr(unsigned long ptr)
{
	unsigned long	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	n = (unsigned long)ptr;
	write(1, "0x", 2);
	// 2 + to include "Ox" characters for the first execution
	return (2 + ft_print_ptr_chars(n)); 
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
                        a = (n - 10) + 'a';
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
		len = len + ft_print_ptr((unsigned long)va_arg(arg, void *));
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
	int ft_res = ft_printf(" %p %p ", 0, 0);
	printf("%d\n", ft_res);
	write(1, "\n", 1);
	int print_res = printf(" %p %p ", 0, 0);
	printf("%d\n", print_res);
	
	int ft_res2 = ft_printf(" %p ", 16);
	printf("%d\n", ft_res2);
	write(1, "\n", 1);
	int print_res2 = printf(" %p ", 16);
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
