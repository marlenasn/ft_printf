/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiecek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:31:44 by mwiecek           #+#    #+#             */
/*   Updated: 2024/03/26 13:31:48 by mwiecek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putnbr(int n)
{
        char    a;

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
                ft_putnbr(n / 10);
                ft_putnbr(n % 10);
        }
        else
        {
                a = n + '0';
                write (1, &a, 1);
        }
}

void    ft_putstr(char *s)
{
        if (s != NULL)
        {
                while (*s)
                {
                        write(1, s, 1);
                        s++;
                }
        }
}

void    ft_print_ptr(unsigned long ptr, int first)
{
        char    	a;
	unsigned long	n;

	n = (unsigned long)ptr;

	if(first)
		write(1, "0x", 2);
        if (n >= 16)
        {
                ft_print_ptr(n / 16, 0);
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
}

void    ft_put_X(unsigned int n)
{
        char    a;

        if (n >= 16)
        {
                ft_put_X(n / 16);
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
}

void    ft_put_x(unsigned int n)
{
        char    a;

        if (n >= 16)
        {
                ft_put_x(n / 16);
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
}

void    ft_put_un_nbr(unsigned int n)
{
        char    a;

        if (n >= 10)
        {
                ft_put_un_nbr(n / 10);
                ft_put_un_nbr(n % 10);
        }
        else
        {
                a = n + '0';
                write (1, &a, 1);
        }
}


void	ft_printf(char *s, ...)
{
	va_list	arg;

	va_start(arg, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
				ft_putchar(va_arg(arg, int));
			else if (*s == 's')
				ft_putstr(va_arg(arg, char *));
			else if (*s == 'i' || *s == 'd')
				ft_putnbr(va_arg(arg, int));
			else if (*s == 'u')
				ft_put_un_nbr(va_arg(arg, unsigned int));
			else if (*s == 'p')
				ft_print_ptr((unsigned long)va_arg(arg, void *), 1);
			else if (*s == '%')
				write(1, "%", 1);
			else if (*s == 'x')
				ft_put_x(va_arg(arg, unsigned int));
			else if (*s == 'X')
				ft_put_X(va_arg(arg, unsigned int));
			s++;
		}
		else
		{
			write(1, s, 1);
			s++;
		}
	}
	va_end(arg);
}

int	main(void)
{
	void	*ptr;

	ft_printf("%c\n%p\n%x\n", 'a', ptr, 9840938);
	write(1, "\n", 1);
	printf("%c\n%p\n%x\n", 'a', ptr, 9840938);

	ft_printf("hdjkhjsdk");
        write(1, "\n", 1);
        printf("hdjkhjsdk");
	return (0);
}
